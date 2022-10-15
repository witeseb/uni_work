/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_lomuto.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:46:10 by tponark           #+#    #+#             */
/*   Updated: 2022/10/15 19:46:14 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	quick_sort_lomuto(int array[], int left, int right)
{
	int s;

	if (left < right)
	{
		s = lomuto(array, left, right);
		quick_sort_lomuto(array, left, s - 1);
		quick_sort_lomuto(array, s + 1, right);
	}
}
