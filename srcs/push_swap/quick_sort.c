/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:12 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/21 14:27:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		go_back(t_ps *p, int pivot, int p_index)
{
		int		(*f)(t_ps *, char c);
		int		rot;
		int		rev;

		rot = 0;
		rev = 0;
		while (get_val(p, p_index - rot, 'a') != pivot
						&& (get_val(p, p_index + rev, 'a') != pivot))
		{
				++rot;
				++rev;
		}
		f = get_val(p, p_index + rev, 'a') ? rev_rotate : rotate;
		while (p->a[p_index] != pivot)
				f(p, 'a');
		return (1);
}

static int		push_back(t_ps *p)
{
		if (p->size_b)
		{
				if (p->size_a > 1)
						rotate(p, 'a');
				while (p->size_b)
						push(p, 'a');
		}
		return (1);
}

static int		partition(t_ps *p, int top, int bottom)
{
		int		pivot;
		int		p_index;

		if (sorted(*p, 'a', top, bottom))
						return (bottom);
		pivot = p->a[bottom];
		p_index = bottom;
		goto_pos(p, top, 'a');
		bottom += p->size_a - 1 - top;
		top = p->size_a - 1;
		while (top > bottom)
		{
				while (p->a[top] > pivot)
				{
						push(p, 'b');
						++p_index;
						--top;
				}	
				while (p->a[top] < pivot)
						--top;
				goto_pos(p, top, 'a');
				bottom += p->size_a - 1 - top;
				top = p->size_a - 1;
		}
		push_back(p);
		go_back(p, pivot, p_index);
		return (p_index);
}

int				quick_sort(t_ps *p, int top, int bottom)
{
		int		p_index;

		if (top < 0 || bottom < 0 || top >= p->size_a || bottom >= p->size_a)
				return (1);
		if (top < bottom)
				return (1);
		if (sorted(*p, 0, 0, 0))
				return (1);
		p_index = partition(p, top, bottom);
		quick_sort(p, top, p_index + 1);
		quick_sort(p, p_index - 1, bottom);
		return (1);
}
