// lab1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdafx.h"
#include <stdlib.h>
#define n 10

int mass[n], i, j, key;

void restart()
{
	printf("	ARRAY\n");
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 19 - 10;
		printf("%d ", mass[i]);
	};
	printf("\n\n");
}

void bubble_sort()
{
	printf("	BUBBLE_SORT\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				int tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			};
		};
	for (int i = 0; i < n; i++)
		printf("%d ", mass[i]);
};

void selection_sort()
{
	int min,tmp;
	printf("	SELECTION_SORT\n");
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n - 1; j++)
			if (mass[j] < mass[min])
			{
				min = j;
			};
		tmp = mass[i];
		mass[i] = mass[min];
		mass[min] = tmp;
	};
	for (int i = 0; i < n; i++)
		printf("%d ", mass[i]);
}

void insertion_sort()
{
	for (int i = 1; i < n; i++)
	{
		int tmp = mass[i];
		int loc = i - 1;
		while (loc >= 0 && mass[loc] > tmp)
		{
			mass[loc + 1] = mass[loc];
			loc--;
		};
		mass[loc + 1] = tmp;
	};
	for (int i = 0; i < n; i++)
		printf("%d ", mass[i]);
}

void quick_sort(int *s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		quick_sort(s_arr, first, right);
		quick_sort(s_arr, left, last);
	}
	
};

void sift_down(int *numbers, int root, int bottom)
{
	int max_child;
	bool flag = false;
	while ((root * 2 <= bottom) && (!flag))
	{
		if (root * 2 == bottom)
			max_child = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		if (numbers[root] < numbers[max_child])
		{
			int tmp = numbers[root];
			numbers[root] = numbers[max_child];
			numbers[max_child] = tmp;
			root = max_child;
		}
		else
			flag = true;
	}
}

void heap_sort(int *numbers, int array_size)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		sift_down(numbers, i, array_size);
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		sift_down(numbers, 0, i - 1);
	}
}

int main()
{
	printf("Arrays` process program\n1.Bubble_sort\n2.Selection_sort\n3.Insertion_sort\n4.Quick_sort\n5.Heap_sort\n\n");
	restart();
	scanf_s("%d", &key);
	switch (key)
	{
	default: getchar();
	case 0: restart(); break;
	case 1: bubble_sort(); break;
	case 2: selection_sort(); break;
	case 3: insertion_sort(); break;
	case 4: quick_sort(mass, 0, n - 1);
		for (int i = 0; i < n; i++)
			printf("%d ", mass[i]); break;
	case 5:heap_sort(mass,n); 
		for (int i = 0; i < n; i++)
		printf("%d ", mass[i]); break;
	};

	fflush(stdin);
	getchar();
	getchar();
    return 0;
}
