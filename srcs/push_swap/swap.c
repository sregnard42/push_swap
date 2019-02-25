/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:59:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 12:52:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sa(t_ps *p)
{
		if (p->size_a < 2)
				return (0);
		if (p->a[p->size_a - 1] > p->a[p->size_a - 2])
				return (swap_a(p));
		return (0);
}

static int	sb(t_ps *p)
{
		if (p->size_b < 2)
				return (0);
		if (p->b[p->size_b - 1] < p->b[p->size_b - 2])
				return (swap_b(p));
		return (0);
}

int			ps_swap(t_ps *p)
{
		char	*cmd;
		int		a;
		int		b;

		cmd = NULL;
		a = sa(p);
		b = sb(p);
		if (a && b)
				cmd = "ss";
		else if (a)
				cmd = "sa";
		else if (b)
				cmd = "sb";
		ft_putendl(cmd);
		return (cmd != NULL);
}

