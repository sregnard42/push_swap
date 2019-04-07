/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/04/07 15:39:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Find the smallest number in the list
**	Or the second smallest
*/

static int	find_min(t_ps *p, short int need_second, int exclude)
{
	int	i;
	int	min;
	int	pos;

	if (p->size_a == 0)
		return (-1);
	i = p->size_a - 1;
	min = p->a[i];
	pos = i;
	while (i--)
		if (min > p->a[i])
		{
			if (!(need_second && p->a[i] == exclude))
			{
				min = p->a[i];
				pos = i;
			}
		}
	return (pos);
}

static int	distance(t_ps *p, int pos)
{
	int	top;
	int	bottom;
	int distance;

	top = p->size_a - 1;
	bottom = 1;
	distance = top - pos < bottom + pos ? top - pos : bottom + pos;
	return (distance);
}

static int	find_next(t_ps *p)
{
	int	pos;
	int	pos2;

	pos = find_min(p, 0, 0);
	if (p->a[pos] < p->b[p->size_b - 1])
		return (pos);
	pos2 = find_min(p, 1, p->a[pos]);
	pos = distance(p, pos) < distance(p, pos2) ? distance(p, pos)
	: distance(p, pos2);
	return (pos);
}

static int	push_min(t_ps *p, int top)
{
	int	pos;
	int	min;
	int	(*f)(t_ps *, char);

	if (sorted(*p, 'a', p->size_a - 1, 0))
		return (1);
	pos = find_next(p);
	min = p->a[pos];
	f = (rotate_function(p, pos, 'a'));
	while (p->a[p->size_a - 1] != min)
	{
		if (sorted(*p, 'a', p->size_a - 1, 0))
			break ;
		if (p->size_a > 1 && p->a[p->size_a - 1] < p->a[p->size_a - 2])
			swap(p, 'a');
		f(p, 'a');
	}
	push(p, 'b');
	if (p->size_b > 1 && p->b[p->size_b - 1] < p->b[p->size_b - 2])
		swap(p, 'b');
	return (push_min(p, --top));
}

int			selection_sort(t_ps *p)
{
	push_min(p, p->size_a - 1);
	while (p->size_b && push(p, 'a'))
		;
	return (1);
}
