#include<stdio.h>
#include<string.h>
int prime[10005];
void init()
{
int i;
int j;
prime[0]=prime[1]=0;//��������
prime[2]=1;//������
for(i=3;i<=10005;i+=2)
{
prime[i]=1;//������
prime[i+1]=0;//��������	��0��2֮���ż������������
}
for(i=3;i<=10005;i+=2)
{
if(prime[i]==1)//������
{
j=i+i;
while(j<=10005)
{
prime[j]=0;//��������
j+=i;
}
}
}
}
int main()
{
int c;
int n;
init();//��ʼ��
while(scanf("%d",&c)!=EOF)
{
    while(c--)
    {
        scanf("%d",&n);
        int sum=0;
        int i;
        for(i=2;i<=n/2;i++)
        {
            if(prime[i]&&prime[n+1-i])
            {sum++;}
        }
sum*=2;
if(n%2==1)//nΪ����
{
if(prime[n/2+1])
sum+=1;
}
printf("%d\n",sum);
}
}
return 0;
}
