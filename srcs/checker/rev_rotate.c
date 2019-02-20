/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:46:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 01:36:56 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		rev_rotate_a(t_ps *p)
{
		int	i;

		if (p->size_a < 2)
				return (1);
		i = 0;
		while (++i < p->size_a)
			ft_swap(p->a + i, p->a + i - 1);
		return (1);
}

int		rev_rotate_b(t_ps *p)
{
		int	i;

		if (p->size_b < 2)
				return (1);
		i = 0;
		while (++i < p->size_b)
			ft_swap(p->b + i, p->b + i - 1);
		return (1);
}

int		rev_rotate(t_ps *p)
{
		rev_rotate_a(p);
		rev_rotate_b(p);
		return (1);
}
