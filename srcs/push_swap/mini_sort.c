/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:00:02 by sregnard          #+#    #+#             */
/*   Updated: 2019/04/07 10:40:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_rev_rotate(int top, int mid, int bot, int d)
{
	top *= d;
	mid *= d;
	bot *= d;
	return (top < mid && mid > bot && bot < top);
}

static int	mini_rotate(int top, int mid, int bot, int d)
{
	top *= d;
	mid *= d;
	bot *= d;
	return (top > mid && mid < bot && bot < top);
}

/*
**		Use if size <= 3
*/

int			mini_sort(t_ps *p, char c)
{
	int		*tab;
	int		size;
	int		d;

	tab = c == 'a' ? p->a : p->b;
	size = c == 'a' ? p->size_a : p->size_b;
	d = c == 'a' ? 1 : -1;
	if (sorted(*p, c, size - 1, 0))
		return (1);
	if (size == 2)
		return (swap(p, c));
	if (mini_rotate(tab[2], tab[1], tab[0], d))
		return (rotate(p, c));
	if (mini_rev_rotate(tab[2], tab[1], tab[0], d))
		return (rev_rotate(p, c));
	swap(p, c);
	if (mini_rotate(tab[2], tab[1], tab[0], d))
		return (rotate(p, c));
	if (mini_rev_rotate(tab[2], tab[1], tab[0], d))
		return (rev_rotate(p, c));
	return (1);
}
