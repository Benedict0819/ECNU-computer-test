#include <stdio.h>
#include <stdlib.h>
/*
Description

Castor��ECNU�����������ܳ���һ�������ߣ�����������ˮ�����Ŷӵ��������ΪM����ǰCastor��ʼ�ӹ���һ�������
��ˮ���ϵ�������ǰ�˳��ӹ��ġ��������i�����������i+1֮ǰ�ӹ�.
����Castorֻ��Ҫ�ټӹ�K(K<=M)�����������Ϣ�ˣ�Castor��֪������Ҫ�����೤ʱ�������Ϣ.
Input

��һ��Ϊһ������T,��ʾ�������ݵ�����.
��ÿ���������
��һ������������M,K(1<=K<=M<=1000)
Ȼ��һ����M������ ��i�����ֱ�ʾ������еĵ�i�������Ҫ�ӹ���ʱ��Ϊti(1<=ti<=10000)
Output

ÿ���������һ��,ÿ��ֻ��һ��������ʾCastor����Ҫ�����೤ʱ��

Sample Input

2
3 2
5 2 3
3 1
1 2 3
Sample Output

7
1
*/
int main(int argc, char *argv[]) 
{
	int T,M,K;
	int count;
	int i;
	int sum;
	scanf("%d",&T);
	while(T--){
		sum = 0;
		scanf("%d %d",&M,&K);
		count = M - K;
		//printf("%d",count);
		while(K--){
			scanf("%d",&i);
			sum+=i;
		}
		while(count--){
			scanf("%d",&i);
			//printf("--%d--",i);
		}
		printf("%d\n",sum);
	}
	//system("pause");
	return 0;
}
