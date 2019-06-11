/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/11 12:34:45 by sregnard         ###   ########.fr       */
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
		int	cols;

		lines = 0;
		system("clear");
		while (lines < LINES_LIMIT && (p.size_a || p.size_b))
		{
				cols = 0;
				while (cols < COLS_LIMIT)
				{
						if (p.size_a)
								ft_printf("%4d", p.a[--p.size_a]);
						else
								ft_printf("%4s", "");
						++cols;
				}
				cols = 0;
				ft_printf(" | ");
				while (cols < COLS_LIMIT)
				{
						if (p.size_b)
								ft_printf("%-4d", p.b[--p.size_b]);
						else
								ft_printf("%-4s", "");
						++cols;
				}
				lines == 0 ? ft_putendl(s) : ft_putln();
				++lines;
		}
		sleep(interval);
}
