#include <stdio.h>
#include <stdlib.h>
int array[100000];

void quick_sort(int arr[], int len);

void quick_sort_recursive(int arr[], int start, int end) ;

void swap(int *x, int *y) ;

comp(void const  *a,void const  *b);
int main(int argc, char *argv[]) 
{
	int n,k;
	int i;
	int loc;
	scanf("%d",&n);
	for(i = 0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//quick_sort(array,n);  // �Զ������� Ч����΢�ߣ��ڴ���΢��
	qsort(array,n,sizeof(int),comp); // ϵͳ���� ��Ч����΢�� �ڴ���΢��
	scanf("%d",&k);
	for(i = 0;i<k;i++){
		scanf("%d",&loc);
		printf("%d\n",array[loc-1]);
	}
	system("pause");	
	return 0;
}
int comp(void const  *a,void const  *b){
	if(*(int *)a >*(int *)b ){ // ת��������֮��Ҫ�ǵü�* ����
		return 1;
	}
	if(*(int*)a <*(int *)b){
		return -1;
	}
	if(*(int *)a == *(int *)b){
		return 0;
	}
}
void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;//�@�Ǟ��˷�ֹ����ѯB��Еr���C
	int mid = arr[end]; // �Ա�ֵ�����м�
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}
