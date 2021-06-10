#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>

LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER EndTime;
__int64 elapsed;
double duringTime;

void file_test1() {
	FILE* fp = NULL;

	fp = fopen("data0.txt", "wt");

	//fp : cmd창에 아무것도 안나오고 파일만 생성
	//stdout : cmd창에 출력
	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}

	fprintf(fp, "Hello, world as %d!!\n", 3000);
	if (fp != NULL) {
		fclose(fp);
	}
}

void file_test2() {
	FILE* fp = NULL;
	int i;
	int data[5] = { 0, };
	int data2[5] = { 0, };

	printf("Input 5 numbers : \n");
	for (i = 0; i < 5; i++) {
		scanf("%d", &data[i]);
	}

	fp = fopen("data1.txt", "wt");

	//fp : cmd창에 아무것도 안나오고 파일만 생성
	//stdout : cmd창에 출력
	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}
	for (i = 0; i < 5; i++) {
		fprintf(fp, "%d\n", data[i]);
	}
	if (fp != NULL) {
		fclose(fp);
	}


	fp = fopen("data1.txt", "rt");
	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}

	i = 0;
	while (fscanf(fp, "%d", &data2[i] ) != EOF) {
		data2[i] += 1;
		printf("%d\n", data2[i]);
	}
	
	if (fp!=NULL) {
		fclose(fp);
	}
}


void file_test3() {
	FILE* fp = NULL;
	char ch;

	fp = fopen("text.txt", "wt");

	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}
	printf("문장을 입력하세요 : \n");
	while (1) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		fputc(ch, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen("data1.txt", "wt");
	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		printf("%C", ch);
	}
	printf("입니다.\n");
	if (fp != NULL) {
		fclose(fp);
	}
}

void file_test4() {
	FILE* fp = NULL;
	char buffer[128] = { 0x00, };

	fp = fopen("string.txt", "wt");

	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}
	printf("문장을 입력하세요 : \n");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		fputs(buffer, fp);
	}
	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen("string.txt", "rt");
	if (fp == NULL) {
		fprintf(stderr, "fopen() error\n");
		return;
	}
	printf("당신이 입력한 문장은 : \n");
	if (fgets(buffer, sizeof(buffer), fp) != NULL) {
		fputs(buffer, stdout);
	}
	printf("입니다.\n");
	if (fp != NULL) {
		fclose(fp);
	}
}

void file_test_5_copy() {
	FILE* fp_src = NULL;
	FILE* fp_dst = NULL;

	char buffer[128];;

	fp_src = fopen("src.txt", "wt");
	fp_dst = fopen("dst.txt", "wt");

	assert(fp_src != NULL);
	assert(fp_dst != NULL);

	printf("문장을 입력하세요 : \n");
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		fputs(buffer, fp_src);
	}
	if (fp_src != NULL) {
		fclose(fp_src);
	}

	fp_src = fopen("src.txt", "rt");
	assert(fp_src != NULL);


	printf("* 복사 시작\n");
	while (fgets(buffer, sizeof(buffer), fp_src) != NULL) {
		fputs(buffer, fp_dst);
	}
	printf("* 복사 완료\n");
	if (fp_src != NULL) {
		fclose(fp_src);
	}
	if (fp_dst != NULL) {
		fclose(fp_dst);
	}
}

void file_test_6_copy() {
	FILE* wfp = NULL;
	FILE* ifp = NULL;

	char buffer[128];;

	wfp = fopen("original.txt", "wt");

	assert(wfp != NULL);
	
	fprintf(wfp, "Hello, world!\n");
	
	if (wfp != NULL) {
		fclose(wfp);
	}

	ifp = fopen("original.txt", "rt");
	assert(ifp != NULL);

	fgets(buffer, sizeof(buffer), ifp);

	printf("[First]\n");
	printf("Read: %s", buffer);

	if (ifp != NULL) {
		fclose(ifp);
	}

	wfp = fopen("original.txt", "at");

	assert(wfp != NULL);

	fprintf(wfp, "Hello, students!\n");
	fprintf(wfp, "Good Bye!\n");

	if (wfp != NULL) {
		fclose(wfp);
	}


	ifp = fopen("original.txt", "rt");
	assert(ifp != NULL);

	printf("\n\n[Second]\n");
	while (!feof(ifp)) {
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, sizeof(buffer), ifp);
		printf("Read: %s\n", buffer);
	}

	if (ifp != NULL) {
		fclose(ifp);
	}
}

void file_test7() {
	FILE* bfp = NULL;
	FILE* tfp = NULL;
	char buf[] = "Hello, world!!!";
	int data = 100;

	bfp = fopen("exec7_binary.dat", "wb");
	tfp = fopen("exec7_binary.txt", "wt");


	assert(bfp != NULL);
	assert(tfp != NULL);

	fwrite(buf, sizeof(buf), 1, bfp);
	fwrite(&data, sizeof(int), 1, bfp);

	fprintf(tfp, "%s", buf);
	fprintf(tfp, "%d", data);


	if (bfp != NULL) {
		fclose(bfp);
	}

	if (tfp != NULL) {
		fclose(tfp);
	}
}

void file_test8() {
	int i;
	int* dataList = NULL;

	FILE* bfp = NULL;
	FILE* tfp = NULL;

	QueryPerformanceFrequency(&Frequency);

	dataList = (int*)calloc(10000, sizeof(int));

	for (i = 0; i < 10000; i++) {
		dataList[i] = i;
	}

	bfp = fopen("exec8_binary.dat", "wb");
	tfp = fopen("exec8_binary.txt", "wt");

	assert(bfp != NULL);
	assert(tfp != NULL);

	QueryPerformanceCounter(&BeginTime);
	fwrite(dataList, sizeof(int), 10000, bfp);
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with binary file: %lf\n", duringTime);

	QueryPerformanceCounter(&BeginTime);
	for (i = 0; i < 10000; i++) {
		fprintf(tfp, "%d", dataList[i]);
	}
	QueryPerformanceCounter(&EndTime);

	elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	duringTime = (double)elapsed / (double)Frequency.QuadPart;
	printf("elapsed time with text file: %lf\n", duringTime);

	if (bfp != NULL) {
		fclose(bfp);
	}

	if (tfp != NULL) {
		fclose(tfp);
	}

}
void file_test9() {
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	int i = 0;
	int data[5] = { 0x00, };

	

	fprintf(stdout, "Input 5 numbers : \n");
	for (i = 0; i < 5; i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	fprintf(stdout, "Writing 5 numbers to a file\n");

	fp1 = fopen("data1.txt", "wt");
	fp2 = fopen("data2.bin", "wb");


	assert(fp1 != NULL);
	assert(fp2 != NULL);

	for (i = 0; i < 5; i++) {
		fprintf(fp1, "%08x\n", data[i]);
		fwrite(&data[i], sizeof(int), 1, fp2);
	}
	//fwrite(&data[i], sizeof(int), 5, fp2);


	if (fp1 != NULL) {
		fclose(fp1);
		fp1 = NULL;
	}

	if (fp2 != NULL) {
		fclose(fp2);
		fp2 = NULL;
	}
}

file_test10() {
	int i;
	int dataList[100] = { 0x00, };
	int data = 0x00;
	FILE* bfp = NULL;

	bfp = fopen("exec10_binary.dat", "wb");
	assert(bfp != NULL);

	for (i = 0; i < 100; i++) {
		dataList[i] = i;
	}

	fwrite(dataList, sizeof(dataList), 1, bfp);

	if (bfp != NULL) {
		fclose(bfp);
	}

	bfp = fopen("exec7_binary.dat", "rb");
	assert(bfp != NULL);

	fseek(bfp, 4 * (50 - 1), SEEK_SET);
	fread(&data, sizeof(int), 1, bfp);
	printf("%d\n", data);

	if (bfp != NULL) {
		fclose(bfp);
	}
}

typedef struct _STUDENT_ {
	char name[32];
	char major[32];
	int age;
}STUDENT;

void file_test11() {
	STUDENT stu[3] = { {0x00,}, };
	STUDENT oneStu = { 0x00, };
	FILE* fp = NULL;
	int i = 0;

	fp = fopen("studentInfo", "wb");
	assert(fp != NULL);

	for (i = 0; i < 3; i++) {
		printf("[%d 학생] 이름 전공 나이를 입력하세요\n", i);
		scanf("%s%s%d", &stu[i].name, &stu[i].major, &stu[i].age);
		fwrite(&stu[i], sizeof(STUDENT), 1, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen("studentInfo", "rb");
	assert(fp != NULL);

	printf("\n\n");

	for (i = 0; i < 3; i ++ ) {
		fread(&oneStu, sizeof(STUDENT), 1, fp);
		printf("[%d 학생 정보] %s %s %d\n", i, stu[i].name, stu[i].major, stu[i].age);
	}
	if (fp != NULL) {
		fclose(fp);
	}
}

file_test12() {
	int size = 0;
	FILE* fp = NULL;
	char buf[128] = { 0x00, };

	fp = fopen("original.txt", "r");
	assert(fp != NULL);

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	printf("file size: %d\n", size);

	printf("Reading file first attempt : \n");
	fgets(buf, sizeof(buf), fp);
	printf("%s\n", buf);
	

	printf("\nReading file second attempt : \n");
	rewind(fp);
	fgets(buf, sizeof(buf), fp);
	printf("%s\n", buf);

	if (fp != NULL) {
		fclose(fp);
	}
}

int main() {
	//file_test1();
	//file_test2();
	//file_test3();
	//file_test4();
	//file_test5_copy();
	//file_test6_copy();
	//file_test7();
	file_test8();
	//file_test9();
	//file_test10();
	//file_test11();
	//file_test12();

	getchar();
	return 0;
}