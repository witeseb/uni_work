/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:35:42 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:35:47 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	putarray(int array[], size_t size)
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
