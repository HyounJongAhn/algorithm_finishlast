#include <stdio.h>
#include "sort.h"
#include "util.h"



void selectoin_sort(element data[], int size, char trace)
{
	int i, j;
	int min;
	element temp;

	for (i = 0; i < size - 1;i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (data[min] > data[j]) {
				min = j;
			}

		}
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;

		/*if (trace) {
			printf("\n%d단계 : ", i + 1);
			printData("",data,size);
		}*/
	}
}

void bubble_sort(element data[], int size, int dir, char trace)
{
	int i, j;

	element temp;
	if (dir == INCREASING) {
		for (i = size - 1; i > 0; i--) {
			/*if (trace) {
				printf("\n%d단계 : ", size - i);
			}*/
			for (j = 0; j < i; j++) {
				if (data[j] > data[i]) {
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;


				}
				/*if (trace) {
					printData("", data, size);
				}*/

			}

		}
	}
	else if (dir == DECREASING) {
		for (i = size - 1; i > 0; i--) {
			/*if (trace) {
				printf("\n%d단계 : ", size - i);
			}*/
			for (j = 0; j < i; j++) {
				if (data[j] < data[i]) {
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;


				}
				/*if (trace) {
					printData("", data, size);
				}*/

			}

		}

	}
	
}

void insertion_sort(element data[], int size, int dir, char trace) {
	int i, j;
	element key;
	if (dir == INCREASING) {

		for (i = 1; i < size; i++) {
			key = data[i];
			for (j = i - 1; j >= 0 && data[j] > key; j--) {
				data[j + 1] = data[j];
			}
			data[j + 1] = key;

			/*if (trace) {
				printf("\n%d단계 : ", i + 1);
				printData("", data, size);
			}*/
		}
	}
	else if (dir == DECREASING) {

		for (i = 1; i < size; i++) {
			key = data[i];
			for (j = i - 1; j >= 0 && data[j] < key; j--) {
				data[j + 1] = data[j];
			}
			data[j + 1] = key;

			/*if (trace) {
				printf("\n%d단계 : ", i + 1);
				printData("", data, size);
			}*/
		}
	}

}

int partition(element data[], int left, int right) {
	int pivot, L, R;
	element temp;

	L = left;
	R = right;
	pivot = (left + right) >> 1;

	while (L < R)
	{
		// L은 pivot에 위치한 데이터와 같거나 큰 데이터를 찾음
		while ((data[L]<data[pivot])&&(L<R))
		{
			L++;
		}
		while ((data[R] >= data[pivot]) && (L < R))
		{
			R--;
		}
		if (L < R) {
			temp = data[L];
			data[L] = data[R];
			data[R] = temp;

			if (L == pivot) {
				pivot = R;
			}
		}
	}
	temp = data[pivot];
	data[pivot] = data[R];
	data[R] = temp;

	return R;
}

void quick_sort(element data[], int left, int right)
{
	int pivot;
	int i;

	if (left < right) {
		pivot = partition(data, left, right);

		quick_sort(data, left, pivot - 1);
		quick_sort(data, pivot+1, right);
	}
}
