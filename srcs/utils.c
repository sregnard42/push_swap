/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:39:30 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/16 18:24:23 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_pos(t_ps *p, int val, char c)
{
		int		*tab;
		int		size;
		int		pos;

		tab = c == 'a' ? p->a : p->b;
		size = c == 'a' ? p->size_a : p->size_b;
		pos = 0;
		while (pos < size)
				if (tab[pos++] == val)
						return (--pos);
		return (-1);
}

int		goto_pos(t_ps *p, int pos, char c)
{
		int		*tab;
		int		size;
		int		top;
		int		val;

		tab = c == 'a' ? p->a : p->b;
		size = c == 'a' ? p->size_a : p->size_b;
		top = size - 1;
		val = tab[pos];
		while (tab[top] != val)
				((size / 2) / (pos + 1) < 2) ? rotate_a(p)
						: rev_rotate_a(p);
		return (1);
}

/*
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
 */

int		sorted(t_ps p, char c)
{
		int	*tab;
		int	size;
		int	order;

		order = 1;
		if (c == 'b')
		{
				tab = p.b;
				size = p.size_b;
				order = -1;
		}
		else
		{
				tab = p.a;
				size = p.size_a;
				if (!(c == 'a') && p.size_b != 0)
						return (0);
		}
		if (size < 2)
				return (1);
		while (--size)
				if (tab[size] * order > tab[size - 1] * order)
						return (0);
		return (1);

		/*
		   if (c == 'a')
		   return (sorted_a(p));
		   if (c == 'b')
		   return (sorted_b(p));
		   return (p.size_b == 0 && sorted_a(p));
		 */
}
