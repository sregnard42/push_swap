/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 13:05:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_move(t_ps *p)
{
		if (ps_rotate(p))
				return (1);
		if (ps_rev_rotate(p))
				return (1);
		if (ps_swap(p))
				return (1);
		if (ps_push(p))
				return (1);
		return (0);
}

int			main(int ac, char **av)
{
		t_ps	p;
		int		ok;

		ok = 1;
		parse_args(&p, ac, av);
		while (!sorted(p) && ok)
				ok = next_move(&p);
}
