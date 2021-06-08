#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"
#include "sort.h"

void genRand(int data[], int size, int mod) {
	int i;
	for (i = 0; i < size; i++) {
		data[i] = rand() % mod;
	}
}
void printData(char* str, int data[], int size) {
	int i;
	printf("- %s\n", str);

	for (i = 0; i < size; i++) {
		if ((i != 0) && !(i % 8)) {
			printf("\n");
		}
		printf("%6d", data[i]);
	}
	printf("\n");
}
