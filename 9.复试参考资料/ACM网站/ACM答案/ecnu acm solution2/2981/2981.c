#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int price;
    struct NODE *next;
}NODE;

int main(int argc, char *argv[])
{

    int T;
    int i,j;
    int n;
    int price;
    scanf("%d",&T);
	for(i = 0;i<T;i++){
        NODE *head;
    	head = (NODE*)malloc(sizeof(NODE));
    	head->next = NULL;
        printf("case #%d:\n",i);
        scanf("%d",&n);
		for(j= 0;j<n;j++){
            char ch;
            int price;
            while((ch = getchar()) !=EOF && ch != '\n')
            	;
            if((ch = getchar()) == 'B'){
				scanf("%d",&price);
			}
            NODE *p = head;
			if(ch == 'B'){
                //����
                NODE *temp;
                temp = (NODE*)malloc(sizeof(NODE));
                temp->price = price;
                temp->next = NULL; // ������Ʒ��㡣
				while(p->next != NULL  && p->next->price < price ){
					p = p->next;
				}
				//���ݲ��롣
				temp->next = p->next;
				p->next = temp;
			}
			else{
				//����
				if(p->next !=NULL){
					printf("%d\n",p->next->price);
					p->next = p->next->next;
				}
			}
		}
	}
	return 0;
}
