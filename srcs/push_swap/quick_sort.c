/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:12 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/29 11:55:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		quick_sort_stack(t_ps *p, char c, int top, int bottom)
{
	int		d;
	int		pivot;

	d = (c == 'a') ? 1 : -1;
	pivot = (c == 'a') ? p->a[bottom] : p->b[bottom];
	rev_rotate(p, c);
	push(p, c);
	--top;
	return (1);
}	

int				quick_sort(t_ps *p, int top, int bottom)
{
	int		pivot;

	pivot = p->a[bottom];
	while (p->a[top] != pivot)
	{
		if (p->a[top] < pivot)
		{
			push(p, 'b');
			--top;
		}
		else
			rotate(p, 'a');
	}
	quick_sort_stack(p, 'a', p->size_a - 1, 0); 
	quick_sort_stack(p, 'b', p->size_b - 1, 0); 
	//while (p->size_b)
	//		push(p, 'a');
	return (1);
}
