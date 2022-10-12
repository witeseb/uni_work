/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:17:38 by tponark           #+#    #+#             */
/*   Updated: 2022/10/12 13:37:17 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJLIB_H
# define PROJLIB_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

//Utilities
void	ft_swap(int *a, int *b);
void    ft_putarray(int array[], size_t size);

//Merge sort functions
void	ft_merge_array(int array[], int left, int mid, int right);
void    ft_merge_sort(int array[], int left, int right);

//Partitioning
int		ft_hoare(int array[], int left, int right);
int		ft_lomuto(int array[], size_t left, size_t right);

//Quick sort functions
void	ft_quick_sort_hoare(int array[], int left, int right);
void	ft_quick_sort_lomuto(int array[], int left, int right);

//Quick select functions
int		ft_quick_select(int array[], size_t left, size_t right, int k);

#endif
