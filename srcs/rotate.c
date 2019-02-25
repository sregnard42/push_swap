/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:45:55 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/21 14:15:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		rotate_a(t_ps *p)
{
		int	i;

		if (p->size_a < 2)
				return (1);
		i = p->size_a;
		while (--i > 0)
			ft_swap(&p->a[i], &p->a[i - 1]);
		return (1);
}

int		rotate_b(t_ps *p)
{
		int	i;

		if (p->size_b < 2)
				return (1);
		i = p->size_b;
		while (--i > 0)
			ft_swap(&p->b[i], &p->b[i - 1]);
		return (1);
}

int		rotate(t_ps *p)
{
		return (rotate_a(p) && rotate_b(p));
}
