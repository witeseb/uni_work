/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_lomuto.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:14:22 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 08:16:23 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "projlib.h"

void	ft_quick_sort_lomuto(int array[], int left, int right)
{
	int s;

	if (left < right)
	{
		s = ft_lomuto(array, left, right);
		ft_quick_sort_lomuto(array, left, s - 1);
		ft_quick_sort_lomuto(array, s + 1, right);
	}
}
