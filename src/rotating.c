/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:38:16 by abartell          #+#    #+#             */
/*   Updated: 2023/01/02 11:31:50 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Shift up all the elements of stack a/b by 1.
// The first element becomes the last one.
void	ra_rb(t_pswap **lst, char stack)
{
	if ((*lst)->val == NULL || (*lst)->next->val == NULL)
		return ;
	swap_rotate(lst, R);
	ft_printf("r%c\n", stack);
}

// ra and rb at the same time
void	rr(t_pswap **a, t_pswap **b)
{
	if ((*a)->val == NULL || (*a)->next->val == NULL)
		return ;
	swap_rotate(a, R);
	if ((*b)->val == NULL || (*b)->next->val == NULL)
		return ;
	swap_rotate(b, R);
	ft_printf("rr\n");
}

// Shift down all the elements of stack a/b by 1.
// The last element becomes the first one.
void	rra_rrb(t_pswap **lst, char stack)
{
	if ((*lst)->val == NULL || (*lst)->next->val == NULL)
		return ;
	swap_rotate(lst, RR);
	ft_printf("rr%c\n", stack);
}

void	rrr(t_pswap **a, t_pswap **b)
{
	if ((*a)->val == NULL || (*a)->next->val == NULL)
		return ;
	swap_rotate(a, RR);
	if ((*b)->val == NULL || (*b)->next->val == NULL)
		return ;
	swap_rotate(b, RR);
	ft_printf("rrr\n");
}
