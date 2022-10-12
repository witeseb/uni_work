/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:48:08 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 06:27:51 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

int	ft_quick_select(int array[], size_t left, size_t right, int k)
{
	int s;
	
	s = ft_lomuto(array, left, right);

	if (s == k - 1)
		return (array[s]);
	else if (s > k - 1)
		return ft_quick_select(array, left, s - 1, k);
	else
		return ft_quick_select(array, s + 1, right, k); 
}
