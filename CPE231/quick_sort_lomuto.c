
#include "projlib.h"

void	quick_sort_lomuto(int array[], int left, int right)
{
	int s;

	if (left < right)
	{
		s = lomuto(array, left, right);
		quick_sort_lomuto(array, left, s - 1);
		quick_sort_lomuto(array, s + 1, right);
	}
}
