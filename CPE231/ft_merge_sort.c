/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 03:24:07 by tponark           #+#    #+#             */
/*   Updated: 2022/10/07 00:42:46 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	ft_merge_sort(int array[], int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + ((right - left) / 2);
		ft_merge_sort(array, left, mid);
		ft_merge_sort(array, mid + 1, right);
		ft_merge_array(array, left, mid, right);
	}
}
