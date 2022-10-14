/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:32:37 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:32:56 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	merge_sort(int array[], int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + ((right - left) / 2);
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge_array(array, left, mid, right);
	}
}
