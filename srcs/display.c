/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/05 17:03:14 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		trigger_error(char *error)
{
		if (!error || !DEBUG)
				error = ERR_DEFAULT;
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
}

void		print_stacks(t_ps p, char *s, float interval)
{
		int	lines;

		lines = 0;
		system("clear");
		ft_putendl(s);
		ft_printf("----------------\t----------------\n");
		ft_printf(": %12s :\t: %-12s :\n", "A", "B");
		ft_printf("----------------\t----------------\n");
		while (lines < LINES_LIMIT && (p.size_a || p.size_b))
		{
				if (p.size_a)
						ft_printf("  %12d :\t", p.a[--p.size_a]);
				else
						ft_printf("  %12s  \t", "");
				if (p.size_b)
						ft_printf(": %-12d  \n", p.b[--p.size_b]);
				else
						ft_printf("  %-12s  \n", "");
				++lines;
		}
		//ft_printf("----------------\t----------------\n");
		sleep(interval);
}
