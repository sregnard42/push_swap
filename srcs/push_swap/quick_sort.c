/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:42:58 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/29 15:47:39 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_median(int a, int b, int c)
{
	int		min;
	int		max;
	int		med;

	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}
	if (max < c)
		med = max;
	else
	{
		if (c > min)
			med = c;
		else
			med = min;
	}
	ft_printf("a = %d\tb = %d\tc = %d\tmed = %d\n", a, b, c, med);
	return (med);
}

static int		find_target(t_ps *p, char c, int pivot)
{
	int		index;
	int		*tab;
	int		d;
	int		i;

	index = -1;
	tab = (c == 'a') ? p->a : p->b;
	d = (c == 'a') ? 1 : -1;
	i = (c == 'a') ? p->size_a : p->size_b ;
	while (i--)
		if (tab[i] < pivot * d)
		{
			index = i;
			break ;
		}
	return (index);
}

static int		quick_sort_stack(t_ps *p, char c, int top, int bottom)
{
	int		*tab;
	int		size;
	int		pivot;
	int		pos;
	int		nb_pushed;

	tab = (c == 'a') ? p->a : p->b;
	size = (c == 'a') ? p->size_a : p->size_b;
	if (top - bottom <= 3)
		return (1);
	pivot = find_median(tab[top], tab[bottom], tab[top / 2]);
	nb_pushed = 0;
	while ((pos = find_target(p, c, pivot)) != -1)
	{
		goto_pos(p, pos, c); 
		if (c == 'a')
			push(p, 'b');
		else
			push(p, 'a');
		++nb_pushed;
	}
	goto_pos(p, find_pos(p, pivot, c) + 1, c);
	while (nb_pushed--)
		push(p, c);
	rev_rotate(p, c);
	quick_sort_stack(p, c, top, find_pos(p, pivot, c) + 1);
	quick_sort_stack(p, c, find_pos(p, pivot, c) - 1, bottom);
	return (1);
}	

int				quick_sort(t_ps *p, int top, int bottom)
{
	int		pivot;
	int		pos;

	pivot = find_median(p->a[top], p->a[bottom], p->a[top / 2]);
	while ((pos = find_target(p, 'a', pivot)) != -1)
	{
		goto_pos(p, pos, 'a'); 
		push(p, 'b');
	}
	//goto_pos(p, find_pos(p, pivot, 'a'), 'a');
	if (p->size_a <= 3)
		mini_sort(p, 'a');
	else
		quick_sort_stack(p, 'a', p->size_a - 1, 0); 
	if (p->size_b <= 3)
		mini_sort(p, 'b');
	else
		quick_sort_stack(p, 'b', p->size_b - 1, 0); 
	print_stacks(*p, 0, 0);
	//while (p->size_b)
	//		push(p, 'a');
	return (1);
}
