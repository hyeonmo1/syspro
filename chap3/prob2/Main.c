#include <stdio.h>
#include <string.h>
#include "Copy.h"

#define MAXLINE 100
#define MAXSTRINGS 100 

char lines[MAXSTRINGS][MAXLINE];    //입력된 라인을 저장하는 배열
int lengths[MAXSTRINGS]; // 각 라인의 길이를 저장하는 배열

void copy(char from[], char to[]);  // 문자열 복사 함수의 선언
void swapStrings(int i, int j);

int main()
{
	int numLines = 0;

	while (numLines < MAXSTRINGS && fgets(lines[numLines], MAXLINE, stdin) != NULL)
	{
		lengths[numLines] = strlen(lines[numLines]);
		numLines++;
	}

	for (int i = 0; i < numLines - 1; i++)
	{
		for (int j = 0; j < numLines - i - 1; j++)
		{
			if (lengths[j] < lengths[j + 1])
			{
				swapStrings(j, j + 1);
			}
		}	
	}

	for (int i = 0; i < numLines; i++)
	{
		printf("%s", lines[i]);
	}

	return 0;
}

void swapStrings(int i, int j)
{
	char temp[MAXLINE];
	int tempLen;

	    copy(lines[i], temp);
    tempLen = lengths[i];

    copy(lines[j], lines[i]);
    lengths[i] = lengths[j];

    copy(temp, lines[j]);
    lengths[j] = tempLen;
}
