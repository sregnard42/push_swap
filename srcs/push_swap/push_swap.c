/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/16 18:11:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
		t_ps	p;

		parse_args(&p, ac, av);
		p.flags |= FLAG_SOLVER;
		quick_sort(&p, p.size_a - 1, 0);
//		selection_sort(&p);
		exit(EXIT_SUCCESS);
}
