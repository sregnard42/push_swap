/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:12 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/16 14:27:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		partition(t_ps *p, int start, int end)
{
		int		pivot;
		int		pivot_index;

		pivot = p->a[end];
		pivot_index = end;
		while (start++ < p->size_a - 1)
				rotate_a(p);
		while (p->a[p->size_a - 1] != pivot)
				if (p->a[p->size_a - 1] > pivot)
				{
						push_b(p);
						++pivot_index;
				}
				else
						rotate_a(p);
		if (p->size_b)
		{
				rotate_a(p);
				while (p->size_b)
						push_a(p);
		}
		while (p->a[pivot_index] != pivot)
				rev_rotate_a(p);
		return (pivot_index);
}

int				quick_sort(t_ps *p, int start, int end)
{
		int		pindex;

		if (start < 0 || end < 0 || start >= p->size_a || end >= p->size_a)
				return (1);
		if (!(start > end))
				return (1);
		/*
		   if (end != 0 || start != p->size_a - 1)
		   {
		   ft_putchar('[');
		   ft_putnbr(p->a[start]);
		   ft_putchar(']');
		   ft_putchar('[');
		   ft_putnbr(p->a[end]);
		   ft_putchar(']');
		   ft_putln();
		   }
		 */
		pindex = partition(p, start, end);
		/*
		   ft_putstr("[pivot=");
		   ft_putnbr(p->a[pindex]);
		   ft_putchar(']');
		 */
		quick_sort(p, start, pindex + 1);
		quick_sort(p, pindex - 1, end);
		return (1);
}
