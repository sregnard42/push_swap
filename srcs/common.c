/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 02:00:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_printf.h"

void		print_stacks(t_ps p)
{
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

int			duplicate(t_ps p, int nb)
{
		while(--p.size_a >= 0)
				if (p.a[p.size_a] == nb)
						return (1);
		return (0);
}

void		parse_args(t_ps *p, int ac, char **av)
{
		int	nb;

		p->a = (int *)malloc(--ac);
		p->b = (int *)malloc(ac);
		if (!(p->a && p->b))
				trigger_error(NULL);
		while (ac)
				if (ft_isnumber(av[ac]))
				{
						nb = ft_atoi(av[ac--]);
						if (duplicate(*p, nb))
								trigger_error(NULL);
						else
								p->a[p->size_a++] = nb;
				}
				else
						trigger_error(NULL);
}
