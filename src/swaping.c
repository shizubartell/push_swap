/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:59:50 by abartell          #+#    #+#             */
/*   Updated: 2022/12/13 11:17:43 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// swap the first two elements of stack a or
// stack b; does nothing if the stack is empty
void	sa_and_sb(t_pswap **lst, char stack)
{
	if ((*lst)->val == NULL || (*lst)->next->val == NULL)
		return ;
	swap_rotate(lst, SWAP);
	ft_printf("s%c\n", stack);
}

// does both parts of the sa_and_sb function
// at the same time
void	ss(t_pswap **a, t_pswap **b)
{
	if ((*a)->val == NULL || (*a)->next->val == NULL)
		return ;
	swap_rotate(a, SWAP);
	if ((*b)->val == NULL || (*b)->next->val == NULL)
		return ;
	swap_rotate(b, SWAP);
	ft_printf("ss\n");
}