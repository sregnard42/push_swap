/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 11:54:01 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void		trigger_error(char *error)
{
		if (!error || !DEBUG)
				error = ERR_DEFAULT;
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
}

void		print_stacks(t_ps p)
{
		if (!(p.flags & FLAG_DISPLAY))
				return ;
		ft_printf(" ____________ \t ____________ \n");
		ft_printf("/ %-10s \\\t/ %-10s \\\n", "Stack A", "Stack B");
		ft_printf("--------------\t--------------\n");
		--p.size_a;
		--p.size_b;
		while (p.size_a >= 0 || p.size_b >= 0)
		{
				if (p.size_a >= 0)
						ft_printf("| %-10d |\t", p.a[p.size_a--]);
				else
						ft_printf("| %-10s |\t", "");
				if (p.size_b >= 0)
						ft_printf("| %-10d |\n", p.b[p.size_b--]);
				else
						ft_printf("| %-10s |\n", "");
		}
		ft_printf("--------------\t--------------\n");
}

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
		while (ac)
				if (flag(p, av[ac]))
						--ac;
				else if (ft_isnumber(av[ac]) && ft_isinteger(av[ac]))
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
