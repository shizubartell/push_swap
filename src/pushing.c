/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:15:39 by abartell          #+#    #+#             */
/*   Updated: 2023/01/07 08:06:24 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// takes the first element of a/b at the top of
// a/b and put it on b/a. Does nothing if its
// empty
void	pa_pb(t_pswap **dst, t_pswap **src, char stack)
{
	if ((*src)->val == NULL)
		return ;
	(*src)->pre->next = (*src)->next;
	(*src)->next->pre = (*src)->pre;
	(*dst)->pre->next = *src;
	(*src)->pre = (*dst)->pre;
	(*dst)->pre = *src;
	*src = (*src)->next;
	(*dst)->pre->next = *dst;
	*dst = (*dst)->pre;
	ft_printf("p%c\n", stack);
}
