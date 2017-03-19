#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100	/*�洢�ռ��ʼ������*/

/*Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
typedef int Status;

int F[100];	//쳲���������

/* ���ڱ�˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� */
int Sequential_Search1(int *a, int n, int key) {
	int i;
	for (i = 1; i <= n; i++) {
		if (a[i] == key)
			return i;
	}
	return 0;
}

/* ���ڱ�˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� */
int Sequential_Search2(int *a, int n, int key) {
	int i;
	a[0] = key;
	i = n;
	while (a[i] != key)
	{
		i--;
	}
	return i;
}

/*�۰����*/
int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;	/*��������±�Ϊ��¼��λ*/
	high = 1;	/*��������±�Ϊ��¼ĩλ*/
	while (low <= high)
	{
		mid = (low + high) / 2;	/*�۰�*/
		if (key < a[mid])	/*������ֵ����ֵС*/
			high = mid - 1;	/*����±��������λ�±�Сһλ*/
		else if (key > a[mid])	/*������ֵ����ֵ��*/
			low = mid + 1;
		else
		{
			return mid;	/*����ȣ���˵��mid��Ϊ���ҵ���λ��*/
		}
	}
	return 0;
}

/*��ֵ����*/
int Interpolation_Search(int *a, int n, int key) {
	int low, high, mid;
	low = 1;	/*��������±�Ϊ��¼��λ*/
	high = 1;	/*��������±�Ϊ��¼ĩλ*/
	while (low<=high) {
		mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]);	/*��ֵ*/
		if (key < a[mid])	/*������ֵ�Ȳ�ֵС*/
			high = mid - 1;	/*����±��������ֵ�±�Сһλ*/
		else if (key > a[mid])	/*������ֵ�Ȳ�ֵ��*/
			low = mid + 1;
		else
			return mid;	/*�������˵��mid��Ϊ���ҵ���λ��*/
	}
	return 0;
}

/*쳲���������*/
int Fibonacci_Search(int *a, int n, int key) {
	int low, high, mid, i, k = 0;
	low = 1;	/*��������±�Ϊ��¼��λ*/
	high = n;	/*��������±�Ϊ��¼ĩλ*/
	while (n>F[k]-1)
		k++;
	for (i = n; i < F[k] - 1; i++)
		a[i] = a[n];
	while (low<=high)
	{
		mid = low + F[k - 1] - 1;
		if (key < a[mid]) {
			high = mid - 1;
			k = k - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;	/*�������˵��mid��Ϊ���ҵ���λ��*/
			else
				return n;
		}
	}
	return 0;
}

int main(void) {
	int a[MAXSIZE + 1], i, result;
	int arr[MAXSIZE] = { 0,1,16,24,35,47,59,62,73,88,99 };

	for (i = 0; i <= MAXSIZE; i++)
	{
		a[i] = i;
	}

	result = Sequential_Search1(a, MAXSIZE, MAXSIZE);
	printf("���ڱ�˳�����:%d\n",result);
	result = Sequential_Search2(a, MAXSIZE, 1);
	printf("���ڱ�˳�����:%d\n",result);

	result = Binary_Search(arr, 10, 62);
	printf("�۰����:%d\n",result);

	result = Interpolation_Search(arr,10,62);
	printf("��ֵ���ң�%d\n",result);

	F[0] = 0;
	F[1] = 1;
	for (i = 2; i < 100; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	result = Fibonacci_Search(arr,10,62);
	printf("쳲���������:%d\n",result);

	system("pause");
	return 0;
}