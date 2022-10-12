/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lomuto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:38:38 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 06:17:32 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

/*
int	ft_lomuto(int array[], size_t left, size_t right)
{
	int 	pivot;
	size_t	s;

	pivot = array[left];
	s = left;
	for (size_t i = left + 1; i < right; i++)
	{
		if (pivot > array[i])
		{
			s++;
			ft_swap(&array[i], &array[s]);
		}
	}
	ft_swap(&array[left], &array[s]);
	return (s);
}
*/

int	ft_lomuto(int array[], size_t left, size_t right)
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
			ft_swap(&array[i], &array[current]);
		}
	}
	ft_swap(&array[left], &array[current]);
	return (current);
}
