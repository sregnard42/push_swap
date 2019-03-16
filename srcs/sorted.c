/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:39:30 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/14 11:40:40 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted_a(t_ps p)
{
		if (p.size_a < 2)
				return (1);
		while (--p.size_a)
				if (p.a[p.size_a] > p.a[p.size_a - 1])
						return (0);
		return (1);
}

static int	sorted_b(t_ps p)
{
		if (p.size_b < 2)
				return (1);
		while (--p.size_b)
				if (p.a[p.size_b] < p.a[p.size_b - 1])
						return (0);
		return (1);
}

int		sorted(t_ps p, char c)
{
		if (c == 'a')
				return (sorted_a(p));
		if (c == 'b')
				return (sorted_b(p));
		return (p.size_b == 0 && sorted_a(p));
}
