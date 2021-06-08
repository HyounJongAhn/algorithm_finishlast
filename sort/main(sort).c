#include <stdio.h>
#include "util.h"
#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

int main() {
	//test_selectionSort();
	//test_bubbleSort();
	//test_insertosort();
	test_quickosort();
	getchar();
	return 0;
}