#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int k,i;
	scanf("%d",&k);
	char array[100];
	
	while(k--){
		scanf("%d",&i);
		scanf("%s",&array);
		if(stack(i,array)){
			printf("yes\n");
		}else{
            printf("no\n");
		}
	}

	system("pause");	
	return 0;
}

int stack(int n,char *array){
	int stack[100];
	int top  =0;
	stack[top] = -1; //��ʼ��
	int i;
	int j = 0;
	for(i = 0;i<=n;){
		while(stack[top] != ((int)array[j]-(int)'0')){//��ƥ�� ��ջ��
            stack[++top] = ++i;
            
            
            if(i>n){// ����Ԫ�ؽ�ջ����ƥ�䣬������
				break;
            }
		}
		stack[top--] = -1;//ƥ�䵽һ������ջ��
		if(++j == n){//ƥ�����
		    break;
		}
	}
	if(stack[1] == -1){
		return 1; // �ɹ�
	}
	else return 0;

}
