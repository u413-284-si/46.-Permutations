#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void	rec_heap(int **arr, int *line, int *nums, int numsSize, int cols);
void	fill_line(int **arr, int *line, int *nums, int cols);
void	swap(int **arr, int *line, int *nums, int index1, int index2, int cols);

int**	permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int	**arr;
	int	i;
	int	*line;
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
	rec_heap(arr, *line, nums, numsSize, **returnColumnSizes);
	return (arr);
}

void	rec_heap(int **arr, int *line, int *nums, int numsSize, int cols)
{
	int	i;

	if (numsSize == 1)
		fill_line(arr, line, nums, cols);
	else
	{
		numsSize -= 1;
		rec_heap(arr, *line, nums, numsSize, cols);
		i = 0;
		while (i < numsSize)
		{
			if (numsSize % 2 == 0)
				swap(arr, line, nums, i, numsSize, cols);
			else
				swap(arr, line, nums, 0, numsSize, cols);
			i++;
		}
	}
}

void	swap(int **arr, int *line, int *nums, int index1, int index2, int cols)
{
	int	i;

	*line++;
	i = 0;
	while (i < cols)
	{
		if (i == index2)
			arr[*line][index1] = nums[index2];
		else if (i == index1)
			arr[*line][index2] = nums[index1];
		else
			arr[*line][i] = nums[i];
		i++;
	}
}

void	fill_line(int **arr, int *line, int *nums, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		arr[*line][i] = nums[i];
		i++;
	}
}
