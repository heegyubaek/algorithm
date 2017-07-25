/* 
Q. 영어 대소문자와 띄어쓰기만으로 이루어진 문장이 주어진다. 
이 문장에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 
단, 단어는 띄어쓰기 하나로 구분된다고 생각한다.

Input: 첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문장이 주어진다. 이 문장의 길이는 1,000,000을 넘지 않는다.
ex)The Curious Case of Benjamin Button
Output: 첫째 줄에 단어의 개수를 출력한다.
ex)6
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRING 1000000

int main()
{
	char input_string[MAX_STRING] = { 0, };

	scanf("%[^\n]s", input_string);

	printf("%s\n", input_string);
	int string_count = 0;
	char *pch;
	pch = strtok(input_string, " ");
	while (pch != NULL)
	{
		printf("string = %s\n", pch);
		pch = strtok(NULL, " ");
		string_count++;
	}
	printf("%d", string_count);


	return 0;
}