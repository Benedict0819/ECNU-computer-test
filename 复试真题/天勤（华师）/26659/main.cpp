#include <iostream>
#include <stdio.h>
#define INF 0x7fffffff
#include <algorithm>
using namespace std;

int a[301];
int k[301]={0};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            k[i]=a[i];
            for(int j=1;j<i;j++)
            {
                if(k[i]==k[j])
                    k[i]=-1;
            }
        }//�����ͬ�����ָ��� Ȼ��ѡ
        for(int i=1;i<=n;i++)
        {
            if(k[i]!=-1)
                cnt++;
        }
        //cntΪ��ͬ�� jian������Ŀɴ��� //flag�Ǳ�־����Ŀɴ�
        int jian=0,flag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]==(a[i]/2))
                    {
                        flag=1;
                        for(int z=1;z<=i;z++)
                        {
                            if(a[z]==(a[i]/2))
                            {
                                flag=0;
                            }

                        }

                        if(flag==1)
                        {
                            for(int u=i+1;u<=n;u++)
                                if(a[u]==a[i])
                                    flag=0;
                            if(flag==1)
                                jian++;
                            flag=0;
                        }

                    }
                }
            }
        }
        printf("%d\n",cnt-jian);
    }
    return 0;
}
