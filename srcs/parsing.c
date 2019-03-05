/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:35:28 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/04 17:01:10 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	duplicate(t_ps p, int nb)
{
		while(--p.size_a >= 0)
				if (p.a[p.size_a] == nb)
						return (1);
		return (0);
}

static int	flag(t_ps *p, char *s)
{
		if (ft_strequ(s, "-v"))
				return (p->flags |= FLAG_DISPLAY);
		if (ft_strequ(s, "-c"))
				return (p->flags |= FLAG_COLOR);
		return (0);
}

void		parse_args(t_ps *p, int ac, char **av)
{
		int	nb;

		if (--ac < 1)
				trigger_error("No argument.\n");
		ft_bzero(p, sizeof(p));
		p->a = (int *)malloc(ac);
		p->b = (int *)malloc(ac);
		if (!(p->a && p->b))
				trigger_error("Error malloc.\n");
		ft_bzero(p->a, ac);
		ft_bzero(p->b, ac);
		while (ac)
				if (flag(p, av[ac]))
						--ac;
				else if (ft_isinteger(av[ac]))
				{
						nb = ft_atoi(av[ac--]);
						if (duplicate(*p, nb))
								trigger_error("Duplicate number.\n");
						else
								p->a[p->size_a++] = nb;
				}
				else
						trigger_error("Invalid argument.\n");
}
