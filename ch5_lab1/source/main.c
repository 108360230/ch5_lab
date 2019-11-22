#include <stdlib.h>
#include <stdio.h>
#define exams 4
#define student 3

void maximum(int grades[][exams], int pupils , int tests);
void minimum(int grades[][exams], int pupils , int tests);
void ave(int grades[][exams], int pupils , int tests);
void printarray(int grades[][exams], int pupils , int tests);
void printmenu(void);

int main()
{
	void(*process[4])(int[][exams], int, int)
		= { printarray,minimum,maximum,ave };
	int choice = 0;
	int studentgrades[student][exams] = { {77,68,86,73},
										  {96,87,89,78},
										  {70,90,86,81} };
	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*process[choice])(studentgrades, student, exams);
		}
		else
			printf("program ended. \n");
	}
	system("pause");
	return 0;
}

void minimum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int low = 100;

	for (i = 0; i <= pupils - 1; i++)
		for (j = 0; j <= tests - 1; j++)
			if (grades[i][j] < low)
				low = grades[i][j];
	printf("\n\tThe lowest grade is %d\n", low);
}

void maximum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int high = 0;

	for (i = 0; i <= pupils - 1; i++)
		for (j = 0; j <= tests - 1; j++)
			if (grades[i][j] > high)
				high = grades[i][j];
	printf("\n\tThe highest grade is %d\n", high);
}

void ave(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int total;
	printf("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += grades[i][j];
		}
		printf("\tThe average grade for student %d is %.1f\n", i + 1, (double)total / tests);
	}
}

void printarray(int grades[][exams], int pupils, int tests)
{
	int i,j;
	printf("\n\t                 [0]  [1]  [2]  [3]");
	for (i = 0; i < pupils - 1; i++)
	{
		printf("\n\tstudentGrandes[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu(void)
{
	printf("\n\tenter a choice:\n"
		"\t 0 print the array oh grades\n"
		"\t 1 find the minimum grade\n"
		"\t 2 find the maximum grade"
		"tests for each student\n"
		"\t 4 end progrem\n"
		"\t?");
}