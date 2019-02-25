/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:58:57 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 12:59:15 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ra(t_ps *p)
{
		if (p->size_a < 3)
				return (0);
		if (p->a[p->size_a - 1] > p->a[0])
				return (rotate_a(p));
		return (0);
}

static int	rb(t_ps *p)
{
		if (p->size_b < 3)
				return (0);
		if (p->b[p->size_b - 1] < p->b[0])
				return (rotate_b(p));
		return (0);
}

int			ps_rotate(t_ps *p)
{
		char	*cmd;
		int		a;
		int		b;

		cmd = NULL;
		a = ra(p);
		b = rb(p);
		if (a && b)
				cmd = "rr";
		else if (a)
				cmd = "ra";
		else if (b)
				cmd = "rb";
		ft_putendl(cmd);
		return (cmd != NULL);
}
