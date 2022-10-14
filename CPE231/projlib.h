/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:25:43 by tponark           #+#    #+#             */
/*   Updated: 2022/10/14 18:25:47 by tponark          ###   ########.fr       */
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
void	swap(int *a, int *b);
void    putarray(int array[], size_t size);

//Merge sort functions
void	merge_array(int array[], int left, int mid, int right);
void    merge_sort(int array[], int left, int right);

//Partitioning
int		hoare(int array[], int left, int right);
int		lomuto(int array[], size_t left, size_t right);

//Quick sort functions
void	quick_sort_hoare(int array[], int left, int right);
void	quick_sort_lomuto(int array[], int left, int right);

//Quick select functions
int		quick_select(int array[], size_t left, size_t right, int k);

#endif
