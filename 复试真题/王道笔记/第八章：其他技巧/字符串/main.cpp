#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string a=" 123456789";
    string b="79";
    //if(a<=b)//���
      //  printf("%s\b",b.c_str());
    //else printf("%s\b",a.c_str());

    //����
    //for(int i=0;i<a.size();i++)
      //  printf("%c",a[i]);

    //ɾ��a[7]������a[7]�����1����
    //a.erase(7,1);
    //puts(a.c_str());

    //���ҺͲ���
    int startPos=0;
    int pos=a.find(b,startPos);
    printf("%d\n",pos);

    a.insert(2,b);
    printf("%s",a.c_str());
    return 0;
}
