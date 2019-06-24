/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:23:48 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/24 12:13:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find the biggest number
** While being inferior to the given value
** Returns index of -1 if none exists
*/

int	find_max_capped(t_ps *p, char c, int cap)
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

/*
** Find the biggest number
*/

int	find_max(t_ps *p, char c)
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
** Find the smallest number
** While being superior to the given value
** Returns index of -1 if none exists
*/

int	find_min_capped(t_ps *p, char c, int cap)
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
	i = size;
	min = cap;
	pos = -1;
	while (i--)
		if ((min > tab[i] || min == cap)
				&& tab[i] > cap)
		{
			min = tab[i];
			pos = i;
		}
	return (pos);
}

/*
** Find the smallest number
*/

int	find_min(t_ps *p, char c)
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

/*
**	Compare two indexes and return the closest one
**	(The one that will use the smaller number of (rev)rotate)
*/

int	find_closest(int top, int tar1, int tar2)
{
	int	target;
	int	d[2];

	if (tar1 < 0)
		return (tar2);
	if (tar2 < 0)
		return (tar1);
	d[0] = tar1 + 1 < top - tar1 ? tar1 + 1 : top - tar1;
	d[1] = tar2 + 1 < top - tar2 ? tar2 + 1 : top - tar2;
	target = d[0] < d[1] ? tar1 : tar2;
	return (target);
}
