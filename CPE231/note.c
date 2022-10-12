/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 03:34:42 by tponark           #+#    #+#             */
/*   Updated: 2022/10/10 09:50:49 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projlib.h"

void	ft_print_time(size_t array_s, int kth_pos, double run_t, char type);

/*
unsigned long x;
x = rand();
x <<= 15;
x ^= rand();
x %= 10000001;
*/

int	main(void)
{
	size_t			i;
	size_t			kth_pos;
	size_t			array_s;
	double			m_run_t;
	double			h_q_run_t;
	double			l_q_run_t;
	double			s_run_t;
	unsigned long	x;
	int				*mer_array;
	int				*h_qui_array;
	int				*l_qui_array;
	int				*sel_array;
	clock_t			begin;
	clock_t			end;
	int				kth_element;

	i  = 0;
	printf("\033[0;32m");
	printf("\nEnter the number of elements    (n): ");
	printf("\033[0m");
	scanf("%ld", &array_s); 
	printf("\033[0;32m");
	printf("Enter the kth smallest position (k): ");
	printf("\033[0m");
	scanf("%ld", &kth_pos);
	if (kth_pos > array_s)
	{
		printf("\033[1;31m");
		printf("\n\nk can't be more than n!\n\n");
		printf("\033[0m");
		return (-1);
	}
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
	srand(time(NULL));
	while (i < array_s)
	{
		x = rand();
		x <<= 15;
		x ^= rand();
		x %= 10000001;
		//x %= 100;
		mer_array[i] = x;
		h_qui_array[i] = mer_array[i];
		l_qui_array[i] = mer_array[i];
		sel_array[i] = mer_array[i];
		i++;
	}
	printf("\033[0;32m");
	printf("\nElements of the array before sorting:\n");
	printf("\033[0m");
	ft_putarray(mer_array, array_s);
	printf("\n");
	/*
	ft_putarray(h_qui_array, array_s);
	printf("\n");
	ft_putarray(l_qui_array, array_s);
	printf("\n");
	ft_putarray(sel_array, array_s);
	printf("\n");
	*/
	m_run_t = 0.0;
	begin = clock();
	ft_merge_sort(mer_array, 0, array_s - 1);
	end = clock();
	m_run_t += (double)(end - begin) / CLOCKS_PER_SEC;
	/*
	printf("\033[0;33m");
	printf("\nElements of the array after merge-sorting:\n\n");
	printf("\033[0m");
	ft_putarray(mer_array, array_s);
	*/
	h_q_run_t = 0.0;
	begin = clock();
	ft_quick_sort_hoare(h_qui_array, 0, array_s - 1);
	end = clock();
	h_q_run_t += (double)(end - begin) / CLOCKS_PER_SEC;
	/*
	printf("\033[0;34m");
	printf("\nElements of the array after quick-sorting using hoare partition:\n\n");
	printf("\033[0m");
	ft_putarray(h_qui_array, array_s);
	*/
	l_q_run_t = 0.0;
	begin = clock();
	ft_quick_sort_hoare(l_qui_array, 0, array_s - 1);
	end = clock();
	l_q_run_t += (double)(end - begin) / CLOCKS_PER_SEC;
	/*
	printf("\033[0;34m");
	printf("\nElements of the array after quick-sorting using lomuto partition:\n\n");
	printf("\033[0m");
	ft_putarray(l_qui_array, array_s);
	*/
	s_run_t = 0.0;
	begin = clock();
	kth_element = ft_quick_select(sel_array, 0, array_s - 1, kth_pos);
	end = clock();
	s_run_t += (double)(end - begin) / CLOCKS_PER_SEC;
	/*
	printf("\033[0;34m");
	printf("\nElements of the array after quick-selection:\n\n");
	printf("\033[0m");
	ft_putarray(sel_array, array_s);
	*/
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
	//ft_putarray(mer_array, array_s);
	printf("\n");
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
	//ft_putarray(h_qui_array, array_s);
	printf("\n");
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
	//ft_putarray(l_qui_array, array_s);
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
	//ft_putarray(sel_array, array_s);
	printf("\n");
	printf("\033[0;35m");
	printf("The kth smallest element from quick select function is: ");
	printf("\033[0m");
	printf("%d\n", kth_element);
	ft_print_time(array_s, kth_pos, m_run_t, 'm');
	ft_print_time(array_s, kth_pos, h_q_run_t, 'h');
	ft_print_time(array_s, kth_pos, l_q_run_t, 'l');
	ft_print_time(array_s, kth_pos, s_run_t, 's');
	free(mer_array);
	free(h_qui_array);
	free(l_qui_array);
	free(sel_array);
	printf("\n\n");
	return (0);
}

void	ft_print_time(size_t array_s, int kth_pos, double run_t, char type)
{
	if (type == 'm')
	{
		printf("\033[0;33m");
		printf("\nTime elapse for merge sort with n = ");
		printf("\033[1;31m");
		printf("%ld", array_s);
		printf("\033[0;33m");
		printf(" and k = ");
		printf("\033[1;31m");
		printf("%d", kth_pos);
		printf("\033[0;33m");
		printf(" is ");
		printf("\033[1;31m");
		printf("%lf", run_t);
		printf("\033[0;33m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 'l')
	{
		printf("\033[0;34m");
		printf("\nTime elapse for quick sort using lomuto partition with n = ");
		printf("\033[1;31m");
		printf("%ld", array_s);
		printf("\033[0;34m");
		printf(" and k = ");
		printf("\033[1;31m");
		printf("%d", kth_pos);
		printf("\033[0;34m");
		printf(" is ");
		printf("\033[1;31m");
		printf("%lf", run_t);
		printf("\033[0;34m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 'h')
	{
		printf("\033[0;34m");
		printf("\nTime elapse for quick sort using hoare partition with n = ");
		printf("\033[1;31m");
		printf("%ld", array_s);
		printf("\033[0;34m");
		printf(" and k = ");
		printf("\033[1;31m");
		printf("%d", kth_pos);
		printf("\033[0;34m");
		printf(" is ");
		printf("\033[1;31m");
		printf("%lf", run_t);
		printf("\033[0;34m");
		printf(" seconds.");
		printf("\033[0m");
	}
	else if (type == 's')
	{
		printf("\033[0;35m");
		printf("\nTime elapse for quick sort with n = ");
		printf("\033[1;31m");
		printf("%ld", array_s);
		printf("\033[0;35m");
		printf(" and k = ");
		printf("\033[1;31m");
		printf("%d", kth_pos);
		printf("\033[0;35m");
		printf(" is ");
		printf("\033[1;31m");
		printf("%lf", run_t);
		printf("\033[0;35m");
		printf(" seconds.");
		printf("\033[0m");
	}
}
