/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 03:29:32 by tponark           #+#    #+#             */
/*   Updated: 2022/10/04 11:53:17 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	ft_putarray(int array[], size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
		i++;
	}
	printf("\n");
}
