/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <tponark@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:31:35 by tponark           #+#    #+#             */
/*   Updated: 2022/10/15 18:09:04 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	print_time(size_t array_s, int kth_pos, double run_t, char type);

int	main(void)
{
	//Array variables
	int				*mer_array;    //Merge sort array
	int				*h_qui_array;  //Quick sort with Hoare array
	int				*l_qui_array;  //Quick sort with Lomuto array
	int				*sel_array;    //Quick selection array

	//Size and position variables
	int				kth_element;
	size_t			i;
	size_t			kth_pos;
	size_t			array_s;

	//Runtime variables
	double			m_run_t;
	double			h_q_run_t;
	double			l_q_run_t;
	double			s_run_t;
	double			total_run_t;
	clock_t			total_begin;
	clock_t			total_end;
	clock_t			begin;
	clock_t			end;

	//Random temp
	unsigned long	rand_temp;

	//Clear Screen
	system("clear");

	//Input n & k
	printf("\033[0;32m");
	printf("\nEnter the number of elements    (n): ");
	printf("\033[0m");
	scanf("%ld", &array_s); 
	printf("\033[0;32m");
	printf("Enter the kth smallest position (k): ");
	printf("\033[0m");
	scanf("%ld", &kth_pos);

	//Condition checks
	if (kth_pos > array_s)
	{
		printf("\033[1;31m");
		printf("\n\nk can't be more than n!\n\n");
		printf("\033[0m");
		return (-1);
	}

	if (array_s < 1)
	{
		printf("\033[1;31m");
		printf("\n\nArray size should be equal or more than 1!\n\n");
		printf("\033[0m");
		return (-1);
	}

	if (kth_pos < 1)
	{
		printf("\033[1;31m");
		printf("\n\nKth position should be equal or more than 1!\n\n");
		printf("\033[0m");
		return (-1);
	}

	total_run_t = 0.0;
	total_begin = clock();
	//Memory allocation for arrays
	mer_array = malloc(array_s * sizeof(int));
	if (!mer_array)
		return (0);
	h_qui_array = malloc(array_s * sizeof(int));
	if (!h_qui_array)
		return (0);
	l_qui_array = malloc(array_s * sizeof(int));
	if (!h_qui_array)
		return (0);
	sel_array = malloc(array_s * sizeof(int));
	if (!sel_array)
		return (0);

	//Random arrays initialization
	srand(time(NULL));
	i  = 0;
	while (i < array_s)
	{
		rand_temp = rand();
		rand_temp <<= 15;
		rand_temp ^= rand();
		rand_temp %= 100000001;
		mer_array[i] = rand_temp;
		h_qui_array[i] = mer_array[i];
		l_qui_array[i] = mer_array[i];
		sel_array[i] = mer_array[i];
		i++;
	}

	//Display the element of array before sorting
	/*
	printf("\033[0;32m");
	printf("\nElements of the array before sorting:\n");
	printf("\033[0m");
	putarray(mer_array, array_s);
	printf("\n");
	*/

	//Merge sort
	m_run_t = 0.0;
	begin = clock();
	merge_sort(mer_array, 0, array_s - 1);
	end = clock();
	m_run_t += (double)(end - begin) / CLOCKS_PER_SEC;

	//Quick sort with Hoare partitioning
	h_q_run_t = 0.0;
	begin = clock();
	quick_sort_hoare(h_qui_array, 0, array_s - 1);
	end = clock();
	h_q_run_t += (double)(end - begin) / CLOCKS_PER_SEC;

	//Quick sort with Lomuto partitioning
	l_q_run_t = 0.0;
	begin = clock();
	quick_sort_lomuto(l_qui_array, 0, array_s - 1);
	end = clock();
	l_q_run_t += (double)(end - begin) / CLOCKS_PER_SEC;

	//Quick select
	s_run_t = 0.0;
	begin = clock();
	kth_element = quick_select(sel_array, 0, array_s - 1, kth_pos);
	end = clock();
	s_run_t += (double)(end - begin) / CLOCKS_PER_SEC;

	//Outputs
	//First k smallest elements in the array resulting from merge sorting algorithm
	printf("\033[0;33m");
	printf("%ld smallest elements from merge sort's array:\n", kth_pos);
	printf("\033[0m");
	i = 0;
	while (i < kth_pos)
	{
		printf("%d", mer_array[i]);
		if (i != kth_pos - 1)
			printf(", ");
		i++;
	}
	printf("\n");

	//First k smallest elements in the array resulting from quick sort with Hoare partitioning algorithm
	printf("\033[0;34m");
	printf("%ld smallest elements from hoare partition quick sort's array:\n", kth_pos);
	printf("\033[0m");
	i = 0;
	while (i < kth_pos)
	{
		printf("%d", h_qui_array[i]);
		if (i != kth_pos - 1)
			printf(", ");
		i++;
	}
	printf("\n");

	//First k smallest elements in the array resulting from quick sort with Lomuto partitioning algorithm
	printf("\033[0;34m");
	printf("%ld smallest elements from lomuto partition quick sort's array:\n", kth_pos);
	printf("\033[0m");
	i = 0;
	while (i < kth_pos)
	{
		printf("%d", l_qui_array[i]);
		if (i != kth_pos - 1)
			printf(", ");
		i++;
	}

	//First k smallest elements in the array resulting from quick selecting algorithm
	printf("\n");
	printf("\033[0;35m");
	printf("%ld smallest elements from quick select's array:\n", kth_pos);
	printf("\033[0m");
	i = 0;
	while (i < kth_pos)
	{
		printf("%d", sel_array[i]);
		if (i != kth_pos - 1)
			printf(", ");
		i++;
	}

	//The kth smallest element from quick sselecting algorithm
	printf("\n");
	printf("\033[0;35m");
	printf("The kth smallest element from quick select function is: ");
	printf("\033[0m");
	printf("%d\n", kth_element);
	
	total_end = clock();
	total_run_t += (double)(total_end - total_begin) / CLOCKS_PER_SEC;

	//Time printing
	print_time(array_s, kth_pos, m_run_t, 'm');
	print_time(array_s, kth_pos, h_q_run_t, 'h');
	print_time(array_s, kth_pos, l_q_run_t, 'l');
	print_time(array_s, kth_pos, s_run_t, 's');
	print_time(array_s, kth_pos, total_run_t, 't');

	//Freeing memories
	free(mer_array);
	free(h_qui_array);
	free(l_qui_array);
	free(sel_array);
	printf("\n\n");
	return (0);
}

void	print_time(size_t array_s, int kth_pos, double run_t, char type)
{
	if (type == 'm')
	{
		printf("\033[0;33m");
		printf("\nTime elapse for merge sort with n = ");
		printf("\033[0;31m");
		printf("%ld", array_s);
		printf("\033[0;33m");
		printf(" and k = ");
		printf("\033[0;31m");
		printf("%d", kth_pos);
		printf("\033[0;33m");
		printf(" is ");
		printf("\033[0;31m");
		printf("%lf", run_t);
		printf("\033[0;33m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 'l')
	{
		printf("\033[0;34m");
		printf("\nTime elapse for quick sort using lomuto partition with n = ");
		printf("\033[0;31m");
		printf("%ld", array_s);
		printf("\033[0;34m");
		printf(" and k = ");
		printf("\033[0;31m");
		printf("%d", kth_pos);
		printf("\033[0;34m");
		printf(" is ");
		printf("\033[0;31m");
		printf("%lf", run_t);
		printf("\033[0;34m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 'h')
	{
		printf("\033[0;34m");
		printf("\nTime elapse for quick sort using hoare partition with n = ");
		printf("\033[0;31m");
		printf("%ld", array_s);
		printf("\033[0;34m");
		printf(" and k = ");
		printf("\033[0;31m");
		printf("%d", kth_pos);
		printf("\033[0;34m");
		printf(" is ");
		printf("\033[0;31m");
		printf("%lf", run_t);
		printf("\033[0;34m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 's')
	{
		printf("\033[0;35m");
		printf("\nTime elapse for quick select with n = ");
		printf("\033[0;31m");
		printf("%ld", array_s);
		printf("\033[0;35m");
		printf(" and k = ");
		printf("\033[0;31m");
		printf("%d", kth_pos);
		printf("\033[0;35m");
		printf(" is ");
		printf("\033[0;31m");
		printf("%lf", run_t);
		printf("\033[0;35m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 't')
	{
		printf("\033[0;32m");
		printf("\nTotal time elapse is ");
		printf("\033[0;31m");
		printf("%lf", run_t);
		printf("\033[0;32m");
		printf(" seconds.");
		printf("\033[0m");
	}
}
