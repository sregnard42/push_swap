/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:47:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/24 12:12:40 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		partition(int **tab, int left, int right)
{
	int		pivot;
	int		p_index;
	int		i;
	int		j;

	j = left - 1;
	i = left;
	p_index = right;
	pivot = (*tab)[p_index];
	while (i < right)
	{
		if ((*tab)[i] < pivot)
			ft_swap(*tab + i, *tab + ++j);
		++i;
	}
	ft_swap(*tab + ++j, *tab + p_index);
	return (j);
}

static int		quick_sort(int **tab, int size, int left, int right)
{
	int		p_index;

	if (left < 0 || right < 0 || left >= size || right >= size)
		return (1);
	if (left >= right)
		return (1);
	p_index = partition(tab, left, right);
	quick_sort(tab, size, left, p_index - 1);
	quick_sort(tab, size, p_index + 1, right);
	return (1);
}

int				*sort_tab(int *tab, int size)
{
	int		*sort;
	int		i;

	sort = (int *)malloc(size * sizeof(int));
	i = size;
	while (i--)
		sort[size - i - 1] = tab[i];
	quick_sort(&sort, size, 0, size - 1);
	return (sort);
}
