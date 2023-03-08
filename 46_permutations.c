#include <stdio.h>
#include <stdlib.h>

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

void	rec_heap(int **arr, int *line, int *nums, int numsSize, int cols);
void	fill_line(int **arr, int *line, int *nums, int cols);
void	swap(int *nums, int index1, int index2);

int**	permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int	**arr;
	int	i;
	int	line;
	int	perm;
	int	cols;

	arr = malloc (*returnSize * sizeof(int *));
	perm = 1;
	cols = **returnColumnSizes;
	while (cols)
	{
		perm *= cols;
		cols--;
	}
	i = 0;
	while (i < perm)
		arr[i++] = malloc (**returnColumnSizes * sizeof(int));
	line = 0;
	rec_heap(arr, &line, nums, numsSize, **returnColumnSizes);
	return (arr);
}

/* This function generates permutations with the Heap algorithm.*/

void	rec_heap(int **arr, int *line, int *nums, int numsSize, int cols)
{
	int	i;
	int	what;

	if (numsSize == 1)
	{
		fill_line(arr, line, nums, cols);
		*line += 1;
	}
	i = 0;
	while (i < numsSize)
	{
		what = numsSize - 1;
		rec_heap(arr, line, nums, what, cols);
		if (numsSize % 2 == 0)
			swap(nums, i, what);
		else
			swap(nums, 0, what);
		i++;
	}
}

void	swap(int *nums, int index1, int index2)
{
	int	buf;

	buf = nums[index1];
	nums[index1] = nums[index2];
	nums[index2] = buf;
}

void	fill_line(int **arr, int *line, int *nums, int cols)
{
	int	i;

	i = -1;
	while (++i < cols)
		arr[*line][i] = nums[i];
}

int	main(void)
{
	int	nums[3];
	int	**arr;
	int	rtrns;
	int	rtrnc;
	int	*ptr;
	int	i;
	int	j;

	nums[0] = 4;
	nums[1] = 2;
	nums[2] = 3;
	rtrnc = 3;
	rtrns = 6;
	ptr = &rtrnc;
	arr = permute(nums, 3, &rtrns, &ptr);
	i = -1;
	while (++i < rtrns)
	{
		j = -1;
		while (++j < rtrnc)
			printf("%d", arr[i][j]);
		printf("\n");
		free(arr[i]);
	}
	free(arr);
	return (0);
}
