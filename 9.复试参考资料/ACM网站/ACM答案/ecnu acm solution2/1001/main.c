#include <stdio.h>
#include <stdlib.h>
#include "string.h"
void shift_to_double(char*,char*,char*);
int convert_to_integer(char );
char convert_to_char(int number);
int main(int argc, char *argv[]) 
{
	char ch[1002]; //input integer
	int len_r = 0;
	char ch_a[501] = {'\0'}; // integer A
	char ch_b[501] = {'\0'}; // integer B
	while(scanf("%s%s", ch_a,ch_b)!=EOF){
		char result[502]; //result
	//	shift_to_double(ch,ch_a,ch_b);
		get_result(ch_a,ch_b,result);
		len_r = strlen(result);
		while(len_r--){
		printf("%c",result[len_r]);
		}
		printf("\n");
	}

	
//	system("pause");
	return 0;
}
/*������������ӵĽ����*/
get_result(char *ch_a,char *ch_b,char *result){
	int len_a = 0;
	int len_b = 0;
	int number_a = 0;
	int number_b = 0;
	int crray = 0;
	int number = 0;
	int count = 0;
	len_a = strlen(ch_a);
	len_b = strlen(ch_b);
	/*ÿһλ����ӣ������λ*/
	while((len_a)!= 0 && (len_b)!=0){

		number_a = convert_to_integer(ch_a[--len_a]);
		number_b = convert_to_integer(ch_b[--len_b]);
		(crray == 1)? (number = number_a+number_b+1) :(number =number_a+number_b);

		if(number<10){

			result[count++] = convert_to_char(number);
			crray = 0;
		}else if(number>=10){
			result[count++] = convert_to_char(number%10);
			crray = 1;
		}
	}
	while(len_a != 0){
		number = convert_to_integer(ch_a[--len_a])+crray;
		result[count++] = convert_to_char(number%10);
		crray = (number<10) ? 0: 1;
	}
	while(len_b != 0){
		number = convert_to_integer(ch_b[--len_b])+crray;
		result[count++] = convert_to_char(number%10);
		crray = (number<10) ? 0: 1;
	}
	if(crray == 1){
		result[count++] = convert_to_char(1);
	}
	result[count] = '\0';
	
}
char convert_to_char(int number){
	return (char)(number+'0');
}
int convert_to_integer(char ch){
	return ch-'0';
}
/*��������ַ���ת��Ϊ�����ַ���*/
void shift_to_double(char *ch,char *ch_A,char *ch_B){
    int num = 0;
	int count = 0;
	while(ch[num] !=' '){ //extract integer A
		ch_A[num] = ch[num];
		num++;
	}
	ch_A[num] = '\0';

	while(ch[++num] != '\0'){  //extract integer B
		ch_B[count] = ch[num];
		count++;
	}
	ch_B[num]= '\0';

}
