/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:21:42 by abartell          #+#    #+#             */
/*   Updated: 2022/12/14 22:18:56 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_pswap **lst, char stack)
{
	if ((*lst)->val == NULL || (*lst)->next->val == NULL)
		return ;
	else if (*((*lst)->val) > *((*lst)->next->val))
		sa_sb(lst, stack);
	(*lst)->label = SORT;
	(*lst)->next->label = SORT;
}

void	sort_two_rev(t_pswap **lst, char stack)
{
	if ((*lst)->val == NULL || (*lst)->next->val == NULL)
		return ;
	else if (*((*lst)->val) < *((*lst)->next->val))
		sa_sb(lst, stack);
	(*lst)->label = SORT;
	(*lst)->next->label = SORT;
}
