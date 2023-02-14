#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void	rec_heap(int **arr, int *nums, int numsSize);

int**	permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int	**arr;
	int	i;
	int	j;
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
	rec_heap(arr, nums, numsSize);
	return (arr);
}

void	rec_heap(int **arr, int *nums, int numsSize)
{
	int	i;

	if (numsSize == 1)
		arr[0][0] = nums[0];
	else
	{
		numsSize -= 1;
		rec_heap(arr, nums, numsSize);
		i = 0;
		while (i < numsSize)
		{
			if (numsSize % 2 == 0)
				swap(arr, nums, i, numsSize);
			else
				swap(arr, nums, 0, numsSize);
			i++;
		}
	}
}

void	swap(int **arr, int *nums, int index1, int index2)
{
	int	buf1;
	int	buf2;

	buf2 = nums[index1];
	buf1 = nums[index2];
}
