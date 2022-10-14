/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lomuto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:30:01 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:30:18 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

int	lomuto(int array[], size_t left, size_t right)
{
	int		pivot;
	size_t	current;

	pivot = array[left];
	current = left;
	for (size_t i = left + 1; i <= right; i++)
	{
		if (array[i] < pivot)
		{
			current++;
			swap(&array[i], &array[current]);
		}
	}
	swap(&array[left], &array[current]);
	return (current);
}
