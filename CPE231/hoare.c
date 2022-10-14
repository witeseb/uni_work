/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoare.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:43:25 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:43:38 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

int	hoare(int array[], int left, int right)
{
	int	pivot;
	int i;
	int j;

	pivot = array[left];
	i = left;
	j = right + 1;
	while (i < j)
	{
		do i++; while (array[i] < pivot);
		do j--; while (array[j] > pivot);
		swap(&array[i], &array[j]);
	}
	swap(&array[i], &array[j]);
	swap(&array[left], &array[j]);
	return (j);
}
