/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:42:58 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/30 15:22:38 by sregnard         ###   ########.fr       */
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
	return (med);
}

static int		find_target(t_ps *p, char c, int pivot)
{
	t_stack	s;
	int		index;
	int		d;

	s.tab = (c == 'a') ? p->a : p->b;
	s.size = (c == 'a') ? p->size_a : p->size_b;
	d = (c == 'a') ? 1 : -1;
	index = -1;
	while (s.size--)
		if (s.tab[s.size] * d < pivot * d)
		{
			index = s.size;
			break ;
		}
	return (index);
}

static int		quick_sort_stack(t_ps *p, char c, int top, int bottom)
{
	t_stack	s;
	int		pivot;
	int		pos;
	int		nb_pushed;

	s.tab = (c == 'a') ? p->a : p->b;
	s.size = (c == 'a') ? p->size_a : p->size_b;
	if (top - bottom <= 1 || sorted(*p, c, top, bottom))
		return (1);
	nb_pushed = 0;
	pivot = find_median(s.tab[top], s.tab[bottom], s.tab[(top - bottom)/ 2]);
	while ((pos = find_target(p, c, pivot)) != -1)
	{
		goto_pos(p, pos, c); 
		if (c == 'a')
			push(p, 'b');
		else
			push(p, 'a');
		++nb_pushed;
	}
	pos = find_pos(p, pivot, c);
	goto_pos(p, pos, c);
	while (nb_pushed--)
		push(p, c);
	quick_sort_stack(p, c, top, pos + 1);
	quick_sort_stack(p, c, pos - 1, bottom);
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
	if (p->size_a <= 3)
		mini_sort(p, 'a');
	else
		quick_sort_stack(p, 'a', p->size_a - 1, 0); 
	if (p->size_b <= 3)
		mini_sort(p, 'b');
	else
		quick_sort_stack(p, 'b', p->size_b - 1, 0); 
	while (p->size_b)
			push(p, 'a');
	return (1);
}
