#include<iostream>
using namespace std;

int m1, n1, m2, n2;

int main()
{
    cout << "���������A��������������" << endl;
    cin >> m1 >> n1;

    double** A = new double* [m1]; //��̬�����ά���飺��ָ������
    cout << "���������A��Ԫ�أ�" << endl;
    for (int i = 0; i < m1; i++)
    {
        A[i] = new double[n1];
    }
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cin >> A[i][j];//����A��ʼ��
        }
    }

    //�������A
    cout << "������ľ���Ϊ" << endl;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }


    m2 = n1;
    cout << "����B������Ϊ" << m2 << "�����������B��������" << endl;
    cin >> n2;

    double** B = new double* [m2];
    cout << "���������B��Ԫ�أ�" << endl;
    for (int i = 0; i < m2; i++)
    {
        B[i] = new double[n2];
    }
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> B[i][j];//����B��ʼ��
        }
    }

    //�������B
    cout << "������ľ���Ϊ" << endl;
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }


    //AB=C
    double** C = new double* [m1];
    for (int i = 0; i < m1; i++)
    {
        C[i] = new double[n2];
    }
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            C[i][j] = 0;
            for (int p = 0; p < m2; p++)
            {
                C[i][j] = C[i][j] + A[i][p] * B[p][j];
            }
        }
    }


    //�������C
    cout << "C = AB =��" << endl;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }


    system("pause");
    return 0;
}