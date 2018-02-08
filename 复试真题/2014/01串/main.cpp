#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char* a,char*b)
{
	if(*a!=*b)
	{
		char t=*a;
		*a=*b;
		*b=t;
	}
}
void reserve(char*first,char*last)
{
	int left=0,right=last-first-1;
	while(left < right)
	{
		swap(first++,--last);
		++left;
		--right;
	}
}
//��һ�����У����ظ����ַ�Ҳ�ɡ�
//�㷨�����ҵ����ҵ���һ�� A[i]<A[i+1]������A[i]
// �ڴ��ҵ����ҵ���һ��A[i]<A[j]������A[j]
//����A[i] A[j],Ȼ����[i+1,last)������䣬OK
bool next_permutation(char *first,char *last)
{
	if(first==last || first+1 ==last) return false;
	char *left=last-1;
	for(;;)
	{
		--left;
		if(*left < *(left+1))
		{
			char* right=last-1;
			while(!(*left < *right)) --right;
			swap(left,right);
			reserve(left+1,last);
			return true;
		}
		if(left == first)
		{
			reserve(first,last);
			return false;
		}
	}
}
int main(void) {
	char s[]="133"; //ԭʼ�ַ���������������
	int i=0;
	do{
		printf("%d: %s\n",++i,s);
	}while(next_permutation(s,s+strlen(s)));
	return 0;
}

