typedef int element;

#define INCREASING		1
#define DECREASING		2

void selectoin_sort(element data[], int size, char trace);
void bubble_sort(element data[], int size,int dir, char trace);
void insertion_sort(element data[], int size, int dir, char trace);
void quick_sort(element data[], int left, int right);
