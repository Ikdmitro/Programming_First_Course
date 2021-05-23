#include <iostream>
#include <stdio.h>
#include <math.h>
struct otr {
	double length_otr;
	int x1;
	int x2;
	int y1;
	int y2;
};
struct masotr {
    otr line[100];
	int length=-1;
};
void write_on_display(masotr array) {
	for (int i = 0; i < array.length; i++) {
		printf_s("Координаты точек %d отрезка (%d;%d) и (%d;%d) \n", i + 1, array.line[i].x1, array.line[i].y1, array.line[i].x2, array.line[i].y2);
	}
}
void write_on_binary(masotr array, const char* file_name) {
	FILE* output = fopen(file_name, "wb");
	fwrite(&array.length, sizeof(int), 1, output);
	for (int i = 0; i < array.length; i++) {
		fwrite(&array.line[i].x1, sizeof(int), 1, output);
		fwrite(&array.line[i].y1, sizeof(int), 1, output);
		fwrite(&array.line[i].x2, sizeof(int), 1, output);
		fwrite(&array.line[i].y2, sizeof(int), 1, output);
	}
	printf_s("Данные записаны \n");
}
void write_on_txt(masotr array, const char* file_name) {
	FILE* output = fopen(file_name, "wb");
	fprintf(output, "%d ", array.length);
	for (int i = 0; i < array.length; i++) {
		fprintf(output, "%d ", array.line[i].x1);
		fprintf(output, "%d ", array.line[i].y1);
		fprintf(output, "%d ", array.line[i].x2);
		fprintf(output, "%d ", array.line[i].y2);
	}
	printf_s("Данные записаны \n");
}
masotr change_in_mas(masotr array) {
	int f;
	do {
		int ind;
		do {
			printf_s("Введите номер элемента от 1 до %d \n", array.length);
			scanf_s("%d", &ind);
		} while (ind<1 || ind>array.length);
		printf_s("Введите новые координаты концов отрезка \n");
		scanf_s("%d%d%d%d", &array.line[ind-1].x1, &array.line[ind-1].y1, &array.line[ind-1].x2, &array.line[ind-1].y2);
		write_on_display(array);
		printf_s("Нужна ли еще замена: да (нажмите 1) или нет (любое другое число) \n");
		scanf_s("%d", &f);
	} while (f == 1);
	return array;
}
void search(masotr array) {
	int f;
	printf_s("Нужен ли поиск по массиву: да (нажмите 1) или нет (любое другое число) \n");
	scanf_s("%d", &f);
	if (f == 1) {
		int x1, y1, x2, y2,k=0;
		do {
			printf_s("Введите координаты концов отрезка\n");
			scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int i = 0; i < array.length; i++) {
				if (x1 == array.line[i].x1 && x2 == array.line[i].x2 && y1 == array.line[i].y1 && y2 == array.line[i].y2) {
					printf_s("Найден элемент с такими параметрами под номером %d \n", i + 1);
					k=1;
				}
			     if (array.length - 1 == i && k==0) {
					printf_s("Элементов с заданными параметрами не существует \n");
				}
			}
			k = 0;
			printf_s("Нужен ли еще поиск: да (нажмите 1) или нет (любое другое число) \n");
			scanf_s("%d", &f);
		} while (f == 1);
	} 
}
masotr write_from_txt(masotr array) {
	int f;
	FILE* input = fopen("input.txt", "rt");
	fscanf(input, "%d", &array.length);
	for (int i = 0; i < array.length; i++) {
		fscanf(input, "%d%d%d%d", &array.line[i].x1, &array.line[i].y1, &array.line[i].x2, &array.line[i].y2);
		printf_s("Координаты точек %d отрезка (%d;%d) и (%d;%d) \n", i + 1, array.line[i].x1, array.line[i].y1, array.line[i].x2, array.line[i].y2);
		array.line[i].length_otr = sqrt((array.line[i].x1 - array.line[i].x2) * (array.line[i].x1 - array.line[i].x2) + (array.line[i].y1 - array.line[i].y2) * (array.line[i].y1 - array.line[i].y2));
	}
	search(array);
	printf_s("Нужна ли заменить какой либо элемент: да (нажмите 1) или нет (любое другое число) \n");
	scanf_s("%d", &f);
	if (f == 1) {
		array = change_in_mas(array);
		write_on_txt(array, "input.txt");
	}
	fclose(input);
	return array;
}
masotr write_from_binary(masotr array) {
	int f;
	FILE* input = fopen("input.bin", "rb");
	fread(&array.length, sizeof(int), 1, input);
	for (int i = 0; i < array.length; i++) {
		fread(&array.line[i].x1, sizeof(int), 1, input);
		fread(&array.line[i].y1, sizeof(int), 1, input);
		fread(&array.line[i].x2, sizeof(int), 1, input);
		fread(&array.line[i].y2, sizeof(int), 1, input);
		printf_s("Координаты точек %d отрезка (%d;%d) и (%d;%d) \n", i + 1, array.line[i].x1, array.line[i].y1, array.line[i].x2, array.line[i].y2);
		array.line[i].length_otr = sqrt((array.line[i].x1 - array.line[i].x1) * (array.line[i].x1 - array.line[i].x2) + (array.line[i].y1 - array.line[i].y2) * (array.line[i].y1 - array.line[i].y2));
	}
	search(array);
	printf_s("Нужна ли заменить какой либо элемент: да (нажмите 1) или нет (любое другое число) \n");
	scanf_s("%d", &f);
	if (f == 1) {
		array = change_in_mas(array);
		write_on_binary(array,"input.bin");
	}
	fclose(input);
	return array;
}
masotr write_keyboard(masotr array) {
	int N,f;
	do {
		printf_s("Введите количество элементов массива (нат число, меньшее 100)\n");
		scanf_s("%d", &N);
	} while (N <= 0 || N > 100);
	array.length = N;
	for (int i = 0; i < array.length; i++) {
		printf_s("Введите координаты вершин %d отрезка \n", i + 1);
		scanf_s("%d%d%d%d", &array.line[i].x1, &array.line[i].y1, &array.line[i].x2, &array.line[i].y2);
		array.line[i].length_otr = sqrt((array.line[i].x1 - array.line[i].x2) * (array.line[i].x1 - array.line[i].x2) + (array.line[i].y1 - array.line[i].y2) * (array.line[i].y1 - array.line[i].y2));
	}
	search(array);
	printf_s("Нужна ли заменить какой либо элемент: да (нажмите 1) или нет (любое другое число) \n");
	scanf_s("%d", &f);
	if (f == 1) {
		array = change_in_mas(array);
	}
	return array;
}
masotr write_elems() {
	masotr array;
	int f;
	printf_s("Получить массив из текстового файла (нажмите 1) \n");
	printf_s("Получить массив из бинарного файла (нажмите 2) \n");
	printf_s("Вводить самому(любое другое число) \n");
	scanf_s("%d", &f);
	switch (f) {
	case 1:  array = write_from_txt(array); 
	break;
	case 2:  array = write_from_binary(array); 
	break;
	default: array = write_keyboard(array);		
	}
	return array;
}
void middle_value_otr(masotr array) {
	double sum = 0;
	int f;
	for (int i = 0; i < array.length; i++) {
		sum += array.line[i].length_otr;
	}
	double sr = sum / array.length;
	printf_s("Средняя длина равна %f \n\n", sr);
	FILE* iofile = fopen("output.bin", "wb");
	fwrite(&array.length, sizeof(int), 1, iofile);
	for (int i = 0; i < array.length; i++) {
		if (array.line[i].length_otr > sr) {
			printf("Отрезок %d больше среднего значения \n", i + 1);
		}
	}
	printf_s("Записать в текстовый файл (нажмите 1) \n");
	printf_s("Записать в бинарный файл  (нажмите 2) \n");
	printf_s("Вывести значения на экран(любое другое число)\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1: write_on_txt(array,"output.txt");
			break;
		case 2: write_on_binary(array,"output.bin");
			break;
		default: write_on_display(array);
		}
	}
int main() {
	setlocale(LC_ALL, "Russian");
	masotr array = write_elems();
	middle_value_otr(array);
}