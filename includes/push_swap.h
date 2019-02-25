/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 02:20:57 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 13:40:30 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

int		ps_swap(t_ps *p);
int		ps_push(t_ps *p);
int		ps_rotate(t_ps *p);
int		ps_rev_rotate(t_ps *p);

#endif
