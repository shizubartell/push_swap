/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:21:42 by abartell          #+#    #+#             */
/*   Updated: 2023/01/07 08:00:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	labelswitch(t_pswap **lst)
{
	(*lst)->label = SORT;
	(*lst)->next->label = SORT;
	(*lst)->next->next->label = SORT;
}

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

void	sort_three(t_pswap **lst, char stack)
{
	if ((*lst)->next->next->val == NULL)
		sort_two(lst, stack);
	else if (*((*lst)->next->val) < *((*lst)->val)
		&&*((*lst)->val) < *((*lst)->next->next->val))
		sa_sb(lst, stack);
	else if (*((*lst)->next->next->val) < *((*lst)->next->val)
		&& *((*lst)->next->val) < *((*lst)->val))
	{
		sa_sb(lst, stack);
		rra_rrb(lst, stack);
	}
	else if (*((*lst)->next->val) < *((*lst)->next->next->val)
		&& *((*lst)->next->next->val) < *((*lst)->val))
		ra_rb(lst, stack);
	else if (*((*lst)->val) < *((*lst)->next->next->val)
		&& *((*lst)->next->next->val) < *((*lst)->next->val))
	{
		sa_sb(lst, stack);
		ra_rb(lst, stack);
	}
	else if (*((*lst)->next->next->val) < *((*lst)->val)
		&& *((*lst)->val) < *((*lst)->next->val))
		rra_rrb(lst, stack);
}

void	sort_three_rev(t_pswap **lst, char stack)
{
	if ((*lst)->next->next->val == NULL)
		sort_two_rev(lst, stack);
	else if (*((*lst)->next->val) > *((*lst)->val)
		&& *((*lst)->val) > *((*lst)->next->next->val))
		sa_sb(lst, stack);
	else if (*((*lst)->next->next->val) > *((*lst)->next->val)
		&& *((*lst)->next->val) > *((*lst)->val))
	{
		sa_sb(lst, stack);
		rra_rrb(lst, stack);
	}
	else if (*((*lst)->next->val) > *((*lst)->next->next->val)
		&& *((*lst)->next->next->val) > *((*lst)->val))
		ra_rb(lst, stack);
	else if (*((*lst)->val) > *((*lst)->next->next->val)
		&& *((*lst)->next->next->val) > *((*lst)->next->val))
	{
		sa_sb(lst, stack);
		ra_rb(lst, stack);
	}
	else if (*((*lst)->next->next->val) > *((*lst)->val)
		&& *((*lst)->val) > *((*lst)->next->val))
		rra_rrb(lst, stack);
	labelswitch(lst);
}
