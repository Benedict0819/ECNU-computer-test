/*Description

��һ������(32λ�޷�������)���й������µļ��ܣ�
1. ��16λ�͸�16λ����
2. ��ʱ�ĵ�16λ��λȡ��
3. ��ʱ�ĸ�16λ���16λ����������㣬����洢����16λ
д��һ�������ָ�����������м��ܡ�

Input

�����ж�case��ÿ��caseһ�У���ֻ��һ������

Output

����ÿ��case���һ������(16������ʽ)�������ܺ������

Sample Input

1

Sample Output

FFFEFFFF*/

#include <stdio.h>
#include <stdlib.h>
int
test();
int main(int argc, char *argv[]) 
{   
	test();
	return 0;
}
int
prog(){
    	unsigned int value;
	unsigned int value_high_16;
	unsigned int value_low_16;
	while(scanf("%d",&value) !=EOF){
		value_high_16 = value & 0xffff0000;

		value_low_16 = value & 0x0000ffff;

		/*exchange the high value and low value*/
		value = 0x0000000;
		value |= value_low_16<<16;
		value |= value_high_16>>16;

		value_high_16 = value & 0xffff0000;
		value_low_16 = (~value & 0x0000ffff); // negation the low 16 bit

		value_high_16 ^= value_low_16<<16;

		value = 0x0000000;
		value |=value_high_16;
		value |=value_low_16;
		printf("%08X\n",value);
	}
	return 0;

}
int
test(){
	unsigned int value;
	unsigned int value_high_16;
	unsigned int value_low_16;
	while(scanf("%d",&value) !=EOF){
		value_high_16 = value & 0xffff0000;

		value_low_16 = value & 0x0000ffff;

		value_high_16 = ~value_high_16 & 0xffff0000;

		value_low_16 ^= value_high_16>>16;


		value = 0;
		value |=value_high_16>>16;
		value |=value_low_16<<16;
		printf("%08X\n",value);
	}
	return 0;
}



