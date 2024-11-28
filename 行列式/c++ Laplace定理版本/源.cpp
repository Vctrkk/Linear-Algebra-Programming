#include<iostream>
using namespace std;

double det(double** A, int n);
double det3(double** A);
double det2(double** A);

int main() {
	int n;
	cout << "�����뷽��A�Ľ���n����n��2" << endl;
	cin >> n;
    if (n < 2)return -1;
    double** A = new double* [n]; //��̬�����ά���飺��ָ������
    cout << "���������a��Ԫ�أ�" << endl;
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }
    //����A��ʼ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "A������ʽΪ" << det(A, n) << endl;
    return 0;
}

double det(double** A, int n) {
    switch (n) {
    case 1:
        return A[0][0];
    case 2:
        return det2(A);
    case 3:
        return det3(A);
    default:
        //ȡ��ǰ���е�����������ʽ������ʽ��i,j,k������ȡ��
        double sum = 0;//�����return���ֵ
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = i + 2; k < n; k++) {
                    double A1[3][3];//ȡ����3�׾���
                    double** A2 = new double* [n-3]; //��������ʽ�ľ���
                    for (int l = 0; l < n - 3; l++) {
                        A2[l] = new double[n - 3];
                    }
                    //������l�У�����i,j,k�ͼ���3����ʽ��������i,j,k�ͼ������ʽ�Ĵ�������ʽ
                    for (int l = 0; l < n; l++) {
                        int m1 = 0, m2 = 0;//m1��A1�ã�m2��A2��
                        if (l == i || l == j || l == k) {
                            A1[0][m1] = A[0][l]; A1[1][m1] = A[1][l]; A1[2][m1] = A[2][l];//A1��ʼ��
                            m1++;
                        }
                        else {
                            for (int p = 0; p < n - 3; p++) A2[p][m2] = A[p + 3][l];//A2��ʼ��
                            m2++;
                        }
                    }
                    //��������
                    int exp = 0;//-1���ݴΣ���������Ҫ���������






                    //����ʽ*��������ʽ��ֵ�ӽ�sum
                    switch (exp % 2) {
                        case 0:
                            sum += det3(A1) * det(A2, n - 3);//ƾɶA1������������������
                            break;
                        case 1:
                            sum -= det3(A1) * det(A2, n - 3);//ƾɶA1������������������
                            break;
                    }
                    //��̬����A2������ֹ�ڴ�й©
                    for (int l = 0; l < n - 3; l++) delete[]A2[l];
                    delete[]A2;
                }
            }
        }
        return sum;
    }
}

double det3(double** A) {
    return A[0][0] * A[1][1] * A[2][2]
        + A[0][1] * A[1][2] * A[2][0]
        + A[1][0] * A[2][1] * A[0][2]
        - A[0][2] * A[1][1] * A[2][0]
        - A[0][0] * A[1][2] * A[2][1]
        - A[0][1] * A[1][0] * A[2][2];
}

double det2(double** A) {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}