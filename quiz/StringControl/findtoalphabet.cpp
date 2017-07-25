/*
Q. 알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

Input: 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
ex)baekjoon

Output: 각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.
ex)1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

int main()
{
	char input_string[MAX_STRING] = { 0, };

	scanf("%[^\n]s", input_string);

	//printf("%d\n", strlen(input_string));
	char ch = 'a';
	int flag = 0;
	for (; ch <= 'z'; ch++)
	{
		flag = 0;
		for (int i = 0; i < strlen(input_string) ; i++)
		{
			if (input_string[i] == ch)
			{
				printf("%d ", i);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d ", -1);
		}
	}

	return 0;
}