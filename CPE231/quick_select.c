/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:31:03 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:31:13 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

int	quick_select(int array[], size_t left, size_t right, int k)
{
	int s;
	
	s = lomuto(array, left, right);

	if (s == k - 1)
		return (array[s]);
	else if (s > k - 1)
		return quick_select(array, left, s - 1, k);
	else
		return quick_select(array, s + 1, right, k); 
}
