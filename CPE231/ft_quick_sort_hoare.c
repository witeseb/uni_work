/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_hoare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:11:59 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 08:16:39 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	ft_quick_sort_hoare(int array[], int left, int right)
{
	int s;

	if (left < right)
	{
		s = ft_hoare(array, left, right);
		ft_quick_sort_hoare(array, left, s - 1);
		ft_quick_sort_hoare(array, s + 1, right);
	}
}
