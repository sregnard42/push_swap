/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:45:55 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 01:37:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		rotate_a(t_ps *p)
{
		int	i;

		if (p->size_a < 2)
				return (1);
		i = p->size_a;
		while (--i > 0)
			ft_swap(p->a + i, p->a + i - 1);
		return (1);
}

int		rotate_b(t_ps *p)
{
		int	i;

		if (p->size_b < 2)
				return (1);
		i = p->size_b;
		while (--i > 0)
			ft_swap(p->b + i, p->b + i - 1);
		return (1);
}

int		rotate(t_ps *p)
{
		rotate_a(p);
		rotate_b(p);
		return (1);
}
