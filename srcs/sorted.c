/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:39:30 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 17:39:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		sorted(t_ps p)
{
		if (p.size_b != 0)
				return (0);
		while (p.size_a-- > 1)
				if (p.a[p.size_a] > p.a[p.size_a - 1])
						return (0);
		return (1);
}
