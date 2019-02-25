/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 16:29:57 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		operation(t_ps *p, char *s)
{
		int (*f)(t_ps *);

		f = NULL;
		ft_strequ(s, "sa") ? f = &swap_a : 0;
		ft_strequ(s, "sb") ? f = &swap_b : 0;
		ft_strequ(s, "ss") ? f = &swap : 0;
		ft_strequ(s, "pa") ? f = &push_a : 0;
		ft_strequ(s, "pb") ? f = &push_b : 0;
		ft_strequ(s, "ra") ? f = &rotate_a : 0;
		ft_strequ(s, "rb") ? f = &rotate_b : 0;
		ft_strequ(s, "rr") ? f = &rotate : 0;
		ft_strequ(s, "rra") ? f = &rev_rotate_a : 0;
		ft_strequ(s, "rrb") ? f = &rev_rotate_b : 0;
		ft_strequ(s, "rrr") ? f = &rev_rotate : 0;
		if (f)
				return (f(p));
		return (0);
}

static void	print_result(t_ps *p, int ok)
{
		if (p->flags & FLAG_COLOR)
				ok ? ft_putendl("\033[32mOK\033[0m")
						: ft_putendl("\033[31mKO\033[0m");
		else
				ok ? ft_putendl("OK") : ft_putendl("KO");
		ft_memdel((void **)&p->a);
		ft_memdel((void **)&p->b);
}

int main(int ac, char **av)
{
		t_ps	p;
		char	*line;
		int		ok;

		parse_args(&p, ac, av);
		if (p.flags & FLAG_DISPLAY)
				print_stacks(p, "Init A and B", SLP_SHORT);
		while (!(ok = sorted(p)) && get_next_line(0, &line))
		{
				!(operation(&p, line)) ? trigger_error(NULL) : 0;
				p.flags & FLAG_DISPLAY ? print_stacks(p, line, SLP_SHORT) : 0;
				ft_memdel((void **)&line);
		}
		print_result(&p, ok);
		exit(EXIT_SUCCESS);
}
