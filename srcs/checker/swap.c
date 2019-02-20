/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:34:15 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 01:29:16 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		swap_a(t_ps *p)
{
		if (p->size_a < 2)
				return (1);
		ft_swap(p->a + p->size_a - 1, p->a + p->size_a - 2);
		return (1);
}

int		swap_b(t_ps *p)
{
		if (p->size_b < 2)
				return (1);
		ft_swap(p->b + p->size_b - 1, p->b + p->size_b - 2);
		return (1);
}

int		swap(t_ps *p)
{
		swap_a(p);
		swap_b(p);
		return (1);
}
