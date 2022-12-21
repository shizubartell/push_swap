/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:49:52 by abartell          #+#    #+#             */
/*   Updated: 2022/12/21 11:17:09 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// adding to the front of the list
void	dlstadd_front(t_pswap **lst, t_pswap *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->pre = *lst;
		(*lst)->next = new;
		(*lst)->pre = new;
		*lst = new;
	}
}
