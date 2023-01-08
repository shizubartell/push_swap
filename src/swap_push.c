/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:20:21 by abartell          #+#    #+#             */
/*   Updated: 2023/01/07 08:06:59 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_up_to_six(int len, t_pswap **a, t_pswap **b)
{
	int	i;

	if (len <= 3)
		sort_three(a, 'a');
	else
	{
		send_half_tiny(len, b, a);
		sort_three(a, 'a');
		sort_three_rev(b, 'b');
		i = 0;
		while (i < ((len / 2) + (len % 2)))
		{
			pa_pb(a, b, 'a');
			i++;
		}
	}
}

int	sorted(t_pswap **lst)
{
	t_pswap	*head;

	head = *lst;
	while ((*lst)->next->val != NULL)
	{
		if (((*lst)->index + 1 != (*lst)->next->index))
		{
			*lst = head;
			return (NOPE);
		}
		*lst = (*lst)->next;
	}
	*lst = head;
	return (SUCCESS);
}

void	find_three(int len, t_pswap **a, t_pswap **b)
{
	int	j;
	int	label;

	if (len <= 3)
	{
		sort_three(b, 'b');
		j = -1;
		while (++j < len)
		{
			pa_pb(a, b, 'a');
			ra_rb(a, 'a');
		}
		return ;
	}
	label = (*a)->label + 1;
	while ((*b)->val != NULL)
	{
		(*b)->label = label;
		*b = (*b)->next;
	}
	*b = (*b)->next;
	len = send_half_big(len, a, b);
	find_three(len, a, b);
}

void	solution(int len, t_pswap **a, t_pswap **b)
{
	int	limit;
	int	label;

	if (sorted(a) == SUCCESS)
		return ;
	if (len <= 6)
		sort_up_to_six(len, a, b);
	else
	{
		limit = send_half_tiny(len, b, a);
		label = 0;
		while (label != SORT)
		{
			find_three(limit, a, b);
			rotate_for_sorting(a);
			label = (*a)->label;
			limit = 0;
			while (label != SORT && label == (*a)->label)
			{
				pa_pb(b, a, 'b');
				limit++;
			}
		}
	}
}
