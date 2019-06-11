/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/11 12:38:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation(t_ps *p, char *s)
{
	int		(*f)(t_ps *, char c);
	char	c;

	c = s[ft_strlen(s) - 1];
	f = NULL;
	ft_strequ(s, "pa") ? f = &push : 0;
	ft_strequ(s, "pb") ? f = &push : 0;
	ft_strequ(s, "sa") ? f = &swap : 0;
	ft_strequ(s, "sb") ? f = &swap : 0;
	ft_strequ(s, "ss") ? f = &swap : 0;
	ft_strequ(s, "ra") ? f = &rotate : 0;
	ft_strequ(s, "rb") ? f = &rotate : 0;
	ft_strequ(s, "rr") ? f = &rotate : 0;
	ft_strequ(s, "rra") ? f = &rev_rotate : 0;
	ft_strequ(s, "rrb") ? f = &rev_rotate : 0;
	ft_strequ(s, "rrr") ? f = &rev_rotate : 0;
	if (f)
		return (f(p, c));
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

int			main(int ac, char **av)
{
	t_ps	p;
	char	*line;

	parse_args(&p, ac, av);
	if (p.size_a < 1)
			exit(EXIT_SUCCESS);
	if (p.flags & FLAG_DISPLAY)
		print_stacks(p, "Init", SLP_LONG);
	while (get_next_line(0, &line))
	{
		if (!(operation(&p, line)))
				break ;
		p.flags & FLAG_DISPLAY ? print_stacks(p, line, SLP_NONE) : 0;
		ft_memdel((void **)&line);
	}
	print_result(&p, sorted(p, 0, 0, 0));
	exit(EXIT_SUCCESS);
}
