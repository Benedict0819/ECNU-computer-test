#include <iostream>
#include<stdio.h>
#include <queue>
using namespace std;


char fstr[27],mstr[27];
struct TNode{
    TNode *lchild,*rchild;
    char str;
    TNode()
    {
        lchild=NULL;
        rchild=NULL;
    }
};
int search(char *str,char x) //�����ַ��������ض�Ӧ�������±�
{
    int i;
    for(i=0;str[i]!='\0';i++)
        if(str[i]==x) return i;
    return -1;
}
void Fbit(TNode *root,char x) //��������������飬�ж���Ŀ�������߻��ұߡ���Ҷ�ڵ㴦����
{
    int mindex,findex;
    mindex=search(mstr,x);
    findex=search(mstr,root->str);
    if(mindex<findex)
    {
       if(root->lchild==NULL)
       {
        root->lchild=new TNode;
        root->lchild->str=x;
        }else Fbit(root->lchild,x);
    }
    else
    {
        if(root->rchild==NULL)
        {
            root->rchild=new TNode;
            root->rchild->str=x;
        }else Fbit(root->rchild,x);
    }
}
void Bbit(TNode *root) //����������
{
    if(root==NULL) return;
    Bbit(root->lchild);
    Bbit(root->rchild);
    printf("%c",root->str);
}

void print(TNode *T)
{

    int parentSize=1,childSize=0;
    TNode *temp;
    queue<TNode*> q;
    q.push(T);
    do{
        temp=q.front();
        printf(" %c ",temp->str);
        q.pop();
        if(temp->lchild!=NULL)
        {

            q.push(temp->lchild);

            childSize++;
        }
        if(temp->rchild!=NULL)
        {

            q.push(temp->rchild);
            childSize++;
        }
        parentSize--;
        if(parentSize==0)
        {
            parentSize=childSize;
            childSize=0;
            printf("\n");
        }
    }while(!q.empty());
}
int main()
{
    while(gets(fstr))
    {
        gets(mstr);
        int i;
        TNode *root = new TNode;
        root->str=fstr[0];
        for(i=1;fstr[i]!='\0';i++)  //��������������飬�ж���Ŀ�������߻��ұߡ���Ҷ�ڵ㴦����
        {
            Fbit(root,fstr[i]);
        }
        print(root);
        Bbit(root);
        printf("\n");
    }
}
