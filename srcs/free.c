/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:16:32 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/15 17:16:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_all(t_ps *p)
{
    ft_memdel((void**)&p->a);
    ft_memdel((void**)&p->a);
    ft_lstdel(&p->operation_first, del_operation);
}