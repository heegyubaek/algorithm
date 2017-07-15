#include <stdio.h>
#include <stdlib.h>


void PicturePointStack(int in_row, int in_col)
{
	static int stack_size = 0;
	static int** stack = (int**)malloc(sizeof(int*));
	int i = 0;

	stack_size++;

	stack = (int**)realloc(stack, sizeof(int*) * stack_size);
	stack[stack_size] = (int*)malloc(sizeof(int) * 2);

	stack[stack_size][0] = in_row;
	stack[stack_size][1] = in_col;

	for(i = 0; i < stack_size ; i++)
	{
		printf("stack[%d][%d] \n", stack[i][0], stack[i][1]);
	}

}

int main()
{
	PicturePointStack(0,1);
	PicturePointStack(3,1);

	return -1;
}
