# CLanguage
收集的排序算法的C语言实现。
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANDOM(i) (rand()%i)
#define N 9    //设置数组长度
//分区操作
int Partition(int array[], int left, int right)
{
	 int i,j;
	 int temp;
	 j = left-1;
	 for (i=left; i<=right; i++)
	 {
		  	if (array[i] <=  array[right]) //以最后一个数组的值为基准
		  {
			   j++;
			   temp = array[j];
			   array[j] = array[i];
			   array[i] = temp;
		  }
	 }
	 return j;
}
//迭代运算
void QuikSort(int array[], int left, int right)
{
	 int pivot;
	 if (left < right)
	 {
		  pivot = Partition(array, left, right);
		  QuikSort(array, left, pivot-1);
		  QuikSort(array, pivot+1, right);
	 }
}
//示例
int main()
{
	 int i = 0;
	 int a[N];
	 srand((int)time(0));  //设置随机数种子
		 for (i=0; i<N; i++)  //排序前
		 {
			  a[i] = RANDOM(100);
			  printf("%d\t", a[i]);
		 }
		 printf("\n\n");
		 QuikSort(a, 0, N-1);
			 for (i=0; i<N; i++) //排序后
			 {
			  	printf("%d\t", a[i]);
			 }
}
