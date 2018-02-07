#include <stdio.h>
#include <stdlib.h>
// ��1-N ��������С������ ��������Ҫ�������


int greatest_common_divisor(int a, int b);//�����Լ���ĺ���
int change(int *a,int *b);//���a<b�򽻻�a��b��ֵ
int least_common_multiple(int x);//����С�������ĺ���

int flag[500001];
int main(int argc, char *argv[]) 
{
    int a, c;

    while(scanf("%d",&a)!=EOF){
		if(a == 1){
			printf("1");
		}else{
	    c = least_common_multiple(a);
	    printf("%d\n",c%987654321);
		}


    }
	system("pause");	
	return 0;
}

int least_common_multiple(int x)
{
    int i = 3;
    int lcm = 2;

    for(; i <= x; i++)
    {
        lcm = i * lcm / greatest_common_divisor(lcm, i);
		flag[i] = lcm;
    }
    return lcm;
}
//�����������Լ��
int greatest_common_divisor(int a, int b)
{
    int x;
    while(b)
   {
        change(&a, &b);
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}

int change(int *a, int *b)
{
    int x;
    if(*a < *b)
    {
        x = *a;
        *a = *b;
        *b = x;
    }
    return 1;
}
