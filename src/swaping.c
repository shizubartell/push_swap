/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:59:50 by abartell          #+#    #+#             */
/*   Updated: 2022/12/13 19:47:13 by abartell         ###   ########.fr       */
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

// swaps, rotates and sets the values based
// on the flag input, so one struct pointer
// further if instead of 1 (Rotate) we have 
// the 2 (ReverseRotate)
// also swaps it and saves it in the pre(vious)
// list step
void	swap_rotate(t_pswap **lst, int flag)
{
	if (flag == R)
		*lst = (*lst)->pre;
	else if (flag == RR)
		*lst = (*lst)->pre->pre;
	(*lst)->next->pre = (*lst)->pre;
	(*lst)->pre->next = (*lst)->next;
	(*lst)->pre = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->pre->next = *lst;
	(*lst)->next->pre = *lst;
	if ((*lst)->val == NULL)
		(*lst) = (*lst)->next;
	if (flag == SWAP)
		*lst = (*lst)->pre;
}
