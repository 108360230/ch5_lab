#include <stdlib.h>
#include <stdio.h>
#define issues 5
#define ratings 10

void record(int i, int response);
void high();
void low();
float ave(int issue);
void dissplay();

int responses[issues][ratings];
const char *topics[issues] = { "global warming","the economy","war","health care","education" };

int main(void)
{
	int response;
	int i;
	do
	{
		printf("please rate the following topics on a scale from 1 - 10"
			"\n 1 = least important, 10 = most important\n");
		for (i = 0; i < issues; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("?");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			record(i, response);
		}
		printf("enter 1 to stop. enter - torate the issues again. ");
		scanf_s("%d", &response);
	} while (response != 1);
	dissplay();
	system("pause");
	return 0;
}

void record(int issue, int rating)
{
	responses[issue][rating-1]++;
}

void high(void)
{
	int highrating = 0;
	int hightopic = 0;
	int i, j;

	for (i = 0; i < issues;i++)
	{
		int topicraing = 0;

		for (j = 0; j < ratings; j++)
		{
			topicraing += responses[i][j] * (j + 1);
		}
		if (highrating < topicraing)
		{
			highrating = topicraing;
			hightopic = i;
		}
	}
	printf("the highest rated topoc was");
	printf("%s", topics[hightopic]);
	printf(" with a total rating of %d\n", highrating);
}

void low()
{
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;

	for (i = 0; i < issues; i++)
	{
		int topicraing = 0;

		for (j = 0; j < ratings; j++)
		{
			topicraing += responses[i][j] * (j + 1);
		}
		if (i==0)
		{
			lowrating = topicraing;
		}
		if (lowrating > lowtopic)
		{
			lowrating = topicraing;
			lowrating = i;
		}
	}
	printf("the lowest rated topoc was");
	printf("%s", topics[lowtopic]);
	printf(" with a total rating of %d\n", lowrating);
}

float ave(int issue)
{
	float total = 0;
	int counter = 0;
	int j;

	for (j = 0; j < ratings; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return total / counter;
}

void dissplay()
{
	int i, j;
	printf("%20s", "topic");
	for (i = 1; i <= ratings; i++)
	{
		printf("%4d", i);
	}
	printf("\n");
	printf("%80s", "avrtage rating\n");

	for (i = 0; i < issues; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < ratings; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n", ave(i));
	}
	high();
	low();
}