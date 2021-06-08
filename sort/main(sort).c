#include <stdio.h>
#include "util.h"
#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <Windows.h>

LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER EndTime;
__int64 elapsed;
double duringTime;

void test_selectionSort() {
  //int data[10] = { 69,10,30,2,16,8,31,22,17,91 };
	int* data = NULL;
	int num = 100;

	data = (int*)calloc(num, sizeof(int));
	assert(data != NULL);
	srand(time(NULL));

	genRand(data, num, 100);

	printData("original", data, num);
	selectoin_sort(data, num, 1);
	if (data != NULL) {
		free(data);
		data = NULL;
	}
}

void test_bubbleSort() {
	int data[10] = { 69,10,30,2,16,8,31,22,17,91 };
	//int* data = NULL;
	//int num = 100;
	int num = sizeof(data) / sizeof(int);

	//data = (int*)calloc(num, sizeof(int));
	//assert(data != NULL);
	srand(time(NULL));

	genRand(data, num, 100);

	printData("original", data, num);
	bubble_sort(data, num, INCREASING,1);
	/*if (data != NULL) {
		free(data);
		data = NULL;
	}*/
}

void test_insertosort() {
	//int data[10] = { 69,10,30,2,16,8,31,22,17,91 };
	int* data = NULL;
	int num = 10;

	data = (int*)calloc(num, sizeof(int));
	assert(data != NULL);
	srand(time(NULL));

	genRand(data, num, 100);

	printData("original", data, num);
	insertion_sort(data, num, DECREASING,1);
	if (data != NULL) {
		free(data);
		data = NULL;
	}
}

void test_quickosort() {
	//int data[10] = { 69,10,30,2,16,8,31,22,17,91 };
	int* data = NULL;
	int num = 20;

	data = (int*)calloc(num, sizeof(int));
	assert(data != NULL);
	srand(time(NULL));

	genRand(data, num, 100);

	printData("original", data, num);
	quick_sort(data, 0, num-1);

	printData("sorted", data, num);

	if (data != NULL) {
		free(data);
		data = NULL;
	}
}


void benchmarking() {
	element* sorted = NULL;
	element* original = NULL;

	int num = 10000;
	int i;
	QueryPerformanceFrequency(&Frequency);

	original = (int*)calloc(num, sizeof(int));
	assert(original != NULL);
	srand(time(NULL));

	sorted = (int*)calloc(num, sizeof(int));
	assert(sorted != NULL);
	srand(time(NULL));

	genRand(original, num, 200000);
	memcpy(sorted, original, sizeof(element) * num);
	
	//삽입정렬
	QueryPerformanceCounter(&BeginTime);
	insertion_sort(sorted, num, INCREASING, 0);
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with InsertionSort: %lf\n", duringTime);
	//버블정렬
	memcpy(sorted, original, sizeof(element) * num);

	QueryPerformanceCounter(&BeginTime);
	bubble_sort(sorted, num, INCREASING, 0);
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with bubbleSort: %lf\n", duringTime);
	//선택정렬
	memcpy(sorted, original, sizeof(element) * num);

	QueryPerformanceCounter(&BeginTime);
	selectoin_sort(sorted, num, 0);
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with selectoinSort: %lf\n", duringTime);
	//퀵정렬
	memcpy(sorted, original, sizeof(element) * num);

	QueryPerformanceCounter(&BeginTime);
	quick_sort(sorted, 0, num - 1);
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with quickSort: %lf\n", duringTime);

	if (original != NULL) {
		free(original);
		original == NULL;
	}
	if (sorted != NULL) {
		free(sorted);
		sorted == NULL;
	}
}
int main() {
	//test_selectionSort();
	//test_bubbleSort();
	//test_insertosort();
	//test_quickosort();
	benchmarking();
	getchar();
	return 0;
}