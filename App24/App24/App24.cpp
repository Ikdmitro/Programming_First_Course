#include <iostream>
#include <malloc.h>
void method_one() {
	int *a,n,m;
	int maxElem, maxCell, sum = 0;
	float average;
	printf_s("Введите количество строк и количество столбцов \n");
	scanf_s("%d%d", &n, &m);
	a = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf_s("Введите a[%d][%d] \n", i, j);
			scanf_s("%d", (a + i * m + j));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf_s("%d ", *(a + i * m + j));
		}
		printf_s("\n");
	}
	maxElem = *(a+0*m+0);
	maxCell = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxElem < *(a + i * m + j)) {
				maxElem = *(a + i * m + j);
				maxCell = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		sum += *(a + i * m + maxCell);
	}
	average = sum / m;
	printf_s("Среднее арифметическое равно %f", average);
	free(a);
}
void method_two() {
	int** a, n, m, i, j;
	int maxElem, maxCell, sum = 0;
	float average;
	printf_s("Введите количество строк и количество столбцов \n");
	scanf_s("%d%d", &n, &m);
	a = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++) {
			printf_s("Введите a[%d][%d] \n", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf_s("%d ", a[i][j]);
		}
		printf_s("\n");
	}
	maxElem = a[0][0];
	maxCell = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxElem < a[i][j]) {
				maxElem = a[i][j];
				maxCell = j;
			}
		}
	}
	for (i = 0; i < n; i++) {
		sum += a[i][maxCell];
	}
	average = (float)sum / m;
	printf_s("Среднее арифметическое равно %f", average);
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int flag;
	printf_s("Выберите способ создания двумерной матрицы \n");
	printf_s("Динамическое выделение памяти для двумерных массивов в виде одномерного массива (нажмите 0) \n");
	printf_s("Создание динамического массива при помощи массива указателей (любое другое число) \n");
	scanf_s("%d", &flag);
	if (!flag) {
		method_one();
	}
	else {
		method_two();
	}
}