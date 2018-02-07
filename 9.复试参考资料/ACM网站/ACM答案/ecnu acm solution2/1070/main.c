#include <stdio.h>
#include <stdlib.h>
#include "string.h"


char *
reversal(char * origin);

char *
mulitiplication(char *multiplier,char *multiplicand);

int ctoi(char c);

void
irtocr(int* array,char* result,int len);
int main(int argc, char *argv[]) 
{
	int n;
	char origin1[501];
	char origin2[501];
	scanf("%d",&n);
	
	while(n--){
		scanf("%s %s",origin1,origin2);
		printf("%s\n",mulitiplication(origin1,origin2));
	}
	
	system("pause");	
	return 0;
}
//�����ݳ˷���
char *
mulitiplication(char *multiplier,char *multiplicand){
	int ultimate[1001];  //���ս��
	int len = 0;  //����ܳ���
	reversal(multiplier);
	reversal(multiplicand);
	int i,j,k;  //ѭ�����Ʊ���
	int multicarry,addcarry,temp1,temp2,m,n;
	m =strlen(multiplicand); //�������ĳ���
	n =strlen(multiplier);// �����ĳ���
	memset(ultimate,0,sizeof(int)*1001);
	char result[1001];
	if( !strcmp(multiplier,"0") || !strcmp(multiplicand,"0") ){  //�����һ����0 ���ټ��㡣
		return "0";
	}
	
	for(i = 0;i<strlen(multiplier);i++){
		multicarry = 0;
		addcarry = 0;
		for(j = 0;j<strlen(multiplicand);j++){
			temp1 = ctoi(multiplicand[j]) * ctoi(multiplier[i]) +multicarry;// ���result maybe����10
		//	printf("temp1 = :%d \n",temp1);
			multicarry = temp1 / 10;  //��������˷���λ
			temp1 = temp1%10;// ȡ����
			temp2 = ultimate[i+j] +temp1 +addcarry;  //��һ�ν�λ�͵�ǰ�˷�ȡ����ֵ ����һ�μӷ���λ
			addcarry = temp2 /10;  //���μӷ���λ  �˴μӷ���λ�Ѿ������˴εĳ˷���λ��
			ultimate[i+j] = temp2 %10;
		}
		ultimate[i+m] = multicarry + addcarry; // ��һλ�������Ա������Ľ�����֮�����߽�λ���档
	/*	printf("���γ˷������");
		for(k = i+m;k>=0;k--){
			printf("%d",ultimate[k]);
		}
		printf("\n");
		*/
	}
	if(ultimate[i+m-1] == 0){
		len = i+j-1;
	}if(ultimate[i+m-1] !=0){
		len = i+j;
	}
	irtocr(ultimate,result,len);
	return reversal(result);
}

// ��һ����������ת��Ϊchar �������顣
void
irtocr(int* array,char* result,int len){
	//char result[1001];
	int i;
//	printf("len = %d\n",len);
	for(i = 0;i< len ;i++){
		result[i] = (char)(array[i]+'0');
	}
	
	result[i] = '\0';
	//puts(result);

}
//char ת��Ϊint
int ctoi(char c){
	return c-'0';
}
//��ת�ַ�����
char *
reversal(char * origin){
	int len = strlen(origin);
	//printf("reversal len = %d \n",len);
	int i = 0;
	int temp;
	while((len-1)>=i){
		temp = origin[i];
		origin[i] = origin[len-1];
		origin[len-1] = temp;
		len--;i++;
	}
	//printf("reversal ��");
	//puts(origin);
	return origin;
}
