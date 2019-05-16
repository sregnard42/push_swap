/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:41:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/16 11:41:27 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	soft_min(t_ps *p, char c, int cap)
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
	min = cap;
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
	min = find_min(p, 'b');
	max = find_max(p, 'b');
	if (nb < p->b[min] || nb > p->b[max])
		target = max;
	else
	{
		target = min;
		while (i--)
			if (p->b[i] < nb && p->b[i] > p->b[target])
				target = i;
	}
	goto_pos(p, target, 'b');
	push(p, 'b');
	return (1);
}

/* 
**	Use only if p->size_a > 3
*/

int insertion_sort(t_ps *p)
{
	push(p, 'b');
	push(p, 'b');
	while (p->size_a)
		insert_nb(p, p->a[0]);
	while (p->size_b)
		push(p, 'a');
	goto_pos(p, find_min(p, 'a'), 'a');
	return (1);
}
