#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
        int C;
        int n,V,W;
        int VM,sum;  //sum��Ũ��;
        int P[101]={0};
        while (cin>>C)
        {
                for (int i=0;i<C;i++)
                {
                        cin>>n>>V>>W;
                        for (int j=0;j<n;j++)
                        {
                                cin>>P[j];
                        }
                        sort(P,P+n);
                        VM=sum=0;
                        int count=0;
                        for (int k=0;k<n;k++)
                        {
                                if ((sum+P[k])<=W*(k+1))   //����һ��ʼ���õĳ�����Ҳ����
                                {
                                        VM+=V; sum+=P[k];count++;
                                }else {
                                        break;
                                }
                        }
                        //(count==0)? cout<<"0 0.00"<<endl : cout<<VM<<" "<<setw(4)<<(double)sum/count/100<<endl;
                        (count==0)? printf("0 0.00\n"): printf("%d %.2lf\n",VM,(double)sum/count/100);

                }
        }
        return 0;
}
