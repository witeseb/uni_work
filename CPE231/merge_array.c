/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:30:32 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:30:47 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	merge_array(int array[], int left, int mid, int right)
{
	int	left_i;
	int	right_i;
	int	result_i;
	int	left_size;
	int	right_size;
	int	*left_temp;
	int *right_temp;

	left_size = mid - left + 1;
	right_size = right - mid;

	left_temp = malloc(left_size * sizeof(int));
	right_temp = malloc(right_size * sizeof(int));

	left_i = 0;
	right_i = 0;
	while (left_i < left_size)
	{
		left_temp[left_i] = array[left + left_i];
		left_i++;
	}
	while (right_i < right_size)
	{
		right_temp[right_i] = array[mid + 1 + right_i];
		right_i++;
	}
	left_i = 0;
	right_i = 0;
	result_i = left;
	while (left_i < left_size && right_i < right_size)
	{
		if (left_temp[left_i] <= right_temp[right_i])
			array[result_i] = left_temp[left_i++];
		else
			array[result_i] = right_temp[right_i++];
		result_i++;
	}
	while (left_i < left_size)
		array[result_i++] = left_temp[left_i++];
	while (right_i < right_size)
		array[result_i++] = right_temp[right_i++];
	free(left_temp);
	free(right_temp);
}
