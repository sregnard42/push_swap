/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/31 15:02:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Find the biggest number in the list
*/

static int find_max(t_ps *p, char c)
{
		int i;
		int max;
		int pos;
		int size;
		int *tab;

		size = c == 'a' ? p->size_a : p->size_b;
		tab = c == 'a' ? p->a : p->b;
		if (size == 0)
				return (-1);
		i = size - 1;
		max = tab[i];
		pos = i;
		while (i--)
				if (max < tab[i])
				{
						max = tab[i];
						pos = i;
				}
		return (pos);
}

/*
**	Find the smallest number in the list
*/

static int	find_min(t_ps *p)
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
			min = p->a[i];
			pos = i;
		}
	return (pos);
}

static int	push_all(t_ps *p, int top)
{
	int	max;
	int	min;
	int	dmin;
	int	dmax;

	if (!p->size_a)
		return (1);
	max = find_max(p, 'a');
	min = find_min(p);
	dmin = min + 1 < top - min ? min + 1 : top - min;
	dmax = max + 1 < top - max ? max + 1 : top - max;
	dmin < dmax ? goto_pos(p, min, 'a') : goto_pos(p, max, 'a');
	push(p, 'b');
	!(dmin < dmax) ? rotate(p, 'b') : 0;
	return (push_all(p, --top));
}

int			selection_sort(t_ps *p)
{
	push_all(p, p->size_a - 1);
	goto_pos(p, find_max(p, 'b'), 'b');
	while (p->size_b && push(p, 'a'))
		;
	return (1);
}
