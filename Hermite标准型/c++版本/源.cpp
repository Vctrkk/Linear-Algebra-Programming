#include<iostream>
using namespace std;

int m, n;

//�ж���Ԫλ��
int zhuyuan(double** A, int m)//�������ָ�뼰Ҫ��������
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (A[m][j] == 0)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}

//����Ϊhermit��׼��
void huajian(double** A, int p, int q)//�������ָ�뼰���е���Ԫλ�� ��p+1�е�q+1��
{
    double standard = A[p][q];
    //
    for (int j = 0; j < n; j++)
    {
        A[p][j] = A[p][j] / standard;//����Ԫ��Ϊ1
    }
    //
    for (int j = 0; j < m; j++)
    {
        if (j != p)
        {
            double times = A[j][q];
            for (int k = 0; k < n; k++)
            {
                A[j][k] = A[j][k] - times * A[p][k];//�����е�ÿ��Ԫ�ؼ�ȥ��Ԫ�����еĸ�λ��Ԫ���������Ԫ����λ�õ�Ԫ�صĻ�
            }
        }
    }
}

void swap(double** p1, double** p2)
{
    double* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main()
{
    cout << "���������a��������������" << endl;
    cin >> m >> n;

    double** A = new double* [m]; //��̬�����ά���飺��ָ������
    cout << "���������a��Ԫ�أ�" << endl;
    for (int i = 0; i < m; i++)
    {
        A[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];//����A��ʼ��
        }
    }

    //�������ǰ�ľ���A
    cout << "������ľ���Ϊ" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        int zy = zhuyuan(A, i);
        for (int j=i; zy != i; j++)
        {
            swap(&A[i],&A[j + 1]);
        }
        huajian(A, i, zy);
    }

    //��������ľ���A
    cout << "Hermite��׼�ͣ�" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    delete[]A;
    return 0;
}