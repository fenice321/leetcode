#define _CRT_SECURE_NO_WANINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#if 1
int* find2DiffInArr(int* pa, int sz, int* pc)
{
	assert(pa && pc);
	int* p = (int*)calloc(2, sizeof(int));
	if (NULL == p) {
		puts(strerror(errno));
		exit(-1);
	}
	int tmp = 0;
	int pos = 0;
	int i = 0;
	for (i = 0; i < sz; i++) {
		tmp ^= pa[i];
	}
	for (i = 0; i < 32; i++) {
		if (1 == ((tmp >> i) & 1)) {
			pos = i;
			break;
		}
	}
	for (i = 0; i < sz; i++) {
		if (1 == ((pa[i] >> pos) & 1)) {
			p[0] ^= pa[i];
		}
		else {
			p[1] ^= pa[i];
		}
	}
	*pc = 2;
	return p;
}
int main()
{
	//数组中数字出现的次数
	int arr[] = { 1, 2, 3, 4, 5, 6, 1, 2, 5, 6 };
	int sz = (int)(sizeof(arr) / sizeof(arr[0]));
	int count = 0;
	int* pf = find2DiffInArr(arr, sz, &count);
	printf("%d, %d\n", pf[0], pf[1]);
	free(pf);
	system("pause");
	return 0;
}
#endif

#if 0
int findNum(int* pa, int sz)
{
	assert(pa != NULL);
	int* p = (int*)calloc(sz + 1, sizeof(int));
	if (p == NULL) {
		puts(strerror(errno));
		return -1;
	}
	int i = 0;
	int idx = 0;
	for (i = 0; i < sz; i++) {
		idx = pa[i];
		p[idx] = 1;
	}
	for (i = 0; i < sz + 1; i++) {
		if (0 == p[i]) {
			free(p);
			return i;
		}
	}
	return 0;
}
int main()
{
	//消失的数字
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };
	int sz = (int)(sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", findNum(arr, sz));
	system("pause");
	return 0;
}
#endif