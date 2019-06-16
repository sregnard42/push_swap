/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/16 18:50:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		trigger_error(t_ps *p, char *error)
{
		if (!error || !DEBUG)
				error = ERR_DEFAULT;
		write(2, error, ft_strlen(error));
		free_all(p);
		exit(EXIT_FAILURE);
}

static void	print_stack(t_stack *s)
{
		int	cols;

		cols = 0;
		while (cols < COLS_LIMIT)
		{
				if (s->size)
						ft_printf("%-4d", s->tab[--s->size]);
				else
						ft_printf("%4s", "");
				++cols;
		}
}

void		print_stacks(t_ps p, char *s, float interval)
{
		t_stack	a;
		t_stack	b;
		int		lines;

		lines = 0;
		a.tab = p.a;
		a.size = p.size_a;
		b.tab = p.b;
		b.size = p.size_b;
		system("clear");
		while (lines < LINES_LIMIT && (a.size || b.size))
		{
				ft_printf(" | ");
				print_stack(&a);
				ft_printf(" | ");
				print_stack(&b);
				ft_printf(" | ");
				lines == 0 ? ft_putendl(s) : ft_putln();
				++lines;
		}
		usleep(interval);
}
