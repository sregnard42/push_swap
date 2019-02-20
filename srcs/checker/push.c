/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:44:26 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 01:28:08 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		push_a(t_ps *p)
{
		if (p->size_b == 0)
				return (1);
		ft_swap(p->a + p->size_a++, p->b + --p->size_b);
		return (1);
}

int		push_b(t_ps *p)
{
		if (p->size_a == 0)
				return (1);
		ft_swap(p->b + p->size_b++, p->a + --p->size_a);
		return (1);
}
