/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:57:47 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/31 13:58:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
