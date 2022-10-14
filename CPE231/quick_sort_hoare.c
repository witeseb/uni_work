/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_hoare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:35:09 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:35:21 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	quick_sort_hoare(int array[], int left, int right)
{
	int s;

	if (left < right)
	{
		s = hoare(array, left, right);
		quick_sort_hoare(array, left, s - 1);
		quick_sort_hoare(array, s + 1, right);
	}
}
