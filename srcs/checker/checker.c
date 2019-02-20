/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 10:50:37 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		sorted(t_ps p)
{
		if (p.size_b != 0)
				return (0);
		while (p.size_a-- > 1)
				if (p.a[p.size_a] > p.a[p.size_a - 1])
						return (0);
		return (1);
}

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
		p->flags & FLAG_DISPLAY ? ft_putendl(s) : 0;
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
		char	*input;
		int		ok;

		parse_args(&p, ac, av);
		if (p.flags & FLAG_DISPLAY)
		{
				system("clear");
				ft_putendl("Init a and b");
		}
		print_stacks(p);
		while (!(ok = sorted(p)) && get_next_line(0, &input))
		{
				if (p.flags & FLAG_DISPLAY)
				{
						sleep(LONG_SLEEP);
						system("clear");
				}
				operation(&p, input) ? ft_memdel((void **)&input)
						: trigger_error(NULL);
				print_stacks(p);
		}
		print_result(&p, ok);
		exit(EXIT_SUCCESS);
}
