#include <cstdlib>
#include <iostream>
#include "stdlib.h"
using namespace std;

void reverseOrder(char* str, int p, int q);

char* multiLargeNum(char* A, char* B);
int main()
{
    char A[] = "962346239843253528686293234124";
    char B[] = "93459382645998213649236498";
    char *res = multiLargeNum(A, B);
    if(res[0] != 48)
        printf("%c", res[0]);
    printf("%s", res+1);
    delete [] res;
    return 0;
}

char* multiLargeNum(char* A, char* B)
{
    int m = strlen(A);
    int n = strlen(B);
    char* result = new char[m+n+1];
    memset(result, '0', m+n);
    result[m+n] = '\0';
    reverseOrder(A, 0, m-1);
    reverseOrder(B, 0, n-1);

    int multiFlag; // �˻���λ
    int addFlag;   // �ӷ���λ
    for(int i=0; i <= n-1; i++) // B��ÿһλ
    {
        multiFlag = 0;
        addFlag = 0;
        for(int j=0; j <= m-1; j++) // A��ÿһλ
        {
            // '0' - 48 = 0
            int temp1 = (A[j] - 48) * (B[i] - 48) + multiFlag;
//������� ���ϳ˷���λ
            multiFlag = temp1 / 10;
//�µĳ˷���λ
            temp1 = temp1 % 10;
//ȡ���������˷����㵱ǰλ�õ���ֵ
            int temp2 = (result[i+j] - 48) + temp1 + addFlag;
//��ǰλ��ԭ����ֵ���ϳ˷����������һ�μӷ���λ
            addFlag = temp2 / 10;
//�ӷ���λֵ
            result[i+j] = temp2 % 10 + 48;
//��ǰλ�õ�ֵ��
        }
        result[i + m] += multiFlag + addFlag;
    }
    reverseOrder(result, 0, m+n-1); // �������

    return result;
}

void reverseOrder(char* str, int p, int q)
{
    char temp;
    while(p < q)
    {
        temp = str[p];
        str[p] = str[q];
        str[q] = temp;
        p ++;
        q --;
    }
}
