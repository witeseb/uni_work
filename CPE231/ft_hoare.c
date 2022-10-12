/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hoare.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:42:25 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 06:53:33 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

int	ft_hoare(int array[], int left, int right)
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
		ft_swap(&array[i], &array[j]);
	}
	ft_swap(&array[i], &array[j]);
	ft_swap(&array[left], &array[j]);
	return (j);
}
