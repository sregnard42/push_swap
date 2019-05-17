/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:41:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/17 22:19:06 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Find the max value that is inferior to the given cap
 */

static int find_max_capped(t_ps *p, char c, int cap)
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
		i = size;
		max = cap;
		pos = -1;
		while (i--)
				if ((max < tab[i] || max == cap)
								&& tab[i] < cap)
				{
						max = tab[i];
						pos = i;
				}
		return (pos);
}

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

static int find_min(t_ps *p, char c)
{
		int i;
		int min;
		int pos;
		int size;
		int *tab;

		size = c == 'a' ? p->size_a : p->size_b;
		tab = c == 'a' ? p->a : p->b;
		if (size == 0)
				return (-1);
		i = size - 1;
		min = tab[i];
		pos = i;
		while (i--)
				if (min > tab[i])
				{
						min = tab[i];
						pos = i;
				}
		return (pos);
}

static int insert_nb(t_ps *p, int nb)
{
		int min;
		int max;
		int	target;
		int	i;

		i = p->size_b;
		if (i < 2)
				return push(p, 'b');
		min = find_min(p, 'b');
		max = find_max(p, 'b');
		if (nb < p->b[min] || nb > p->b[max])
				target = max;
		else
				target = find_max_capped(p, 'b', nb);
		goto_pos(p, target, 'b');
		push(p, 'b');
		return (1);
}

/* 
 **	Use only if p->size_a > 3
 */

int insertion_sort(t_ps *p)
{
		int max[3];

		max[0] = p->a[find_max(p, 'a')];
		max[1] = p->a[find_max_capped(p, 'a', max[0])];
		max[2] = p->a[find_max_capped(p, 'a', max[1])];
		while (p->size_a > 3)
		{
				while (p->a[p->size_a - 1] == max[0]
								|| p->a[p->size_a - 1] == max[1]
								|| p->a[p->size_a - 1] == max[2])
						rotate(p, 'a');
				insert_nb(p, p->a[p->size_a - 1]);
		}
		mini_sort(p, 'a');
		goto_pos(p, find_max(p, 'b'), 'b');
		while (p->size_b)
				push(p, 'a');
		goto_pos(p, find_min(p, 'a'), 'a');
		return (1);
}
