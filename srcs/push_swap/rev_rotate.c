/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:57:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 13:26:20 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rra(t_ps *p)
{
		if (p->size_a < 3)
				return (0);
		if (p->a[p->size_a - 1] > p->a[0])
				return (rev_rotate_a(p));
		return (0);
}

static int	rrb(t_ps *p)
{
		if (p->size_b < 3)
				return (0);
		if (p->b[p->size_b - 1] < p->b[0])
				return (rev_rotate_b(p));
		return (0);
}

int			ps_rev_rotate(t_ps *p)
{
		char	*cmd;
		int		a;
		int		b;

		cmd = NULL;
		a = rra(p);
		b = rrb(p);
		if (a && b)
				cmd = "rrr";
		else if (a)
				cmd = "rra";
		else if (b)
				cmd = "rrb";
		ft_putendl(cmd);
		return (cmd != NULL);
}
