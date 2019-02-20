/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 02:03:00 by sregnard         ###   ########.fr       */
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
		if (f)
				return (f(p));
		return (0);
}

int main(int ac, char **av)
{
		t_ps	p;
		char	*input;
		int		ok;

		if (ac <= 1)
				trigger_error(NULL);
		ft_bzero(&p, sizeof(p));
		parse_args(&p, ac, av);
		print_stacks(p);
		while (!(ok = sorted(p)) && get_next_line(1, &input))
		{
				operation(&p, input) ? free(input) : trigger_error(NULL);
				print_stacks(p);
		}
		ok ? ft_putendl("OK") : ft_putendl("KO");
		return (0);
}
