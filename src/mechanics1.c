/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:35:19 by abartell          #+#    #+#             */
/*   Updated: 2022/12/29 09:52:39 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_for_sorting(t_pswap **a)
{
	while (1)
	{
		while ((*a)->index == ((*a)->pre->pre->index + 1))
		{
			(*a)->label = SORT;
			ra_rb(a, 'a');
		}
		if ((*a)->next->index == ((*a)->pre->pre->index + 1)
			&& (*a)->index == ((*a)->next->index + 1))
			sa_sb(a, 'a');
		else
			break ;
	}
}

void	is_bigger(int len, int median, t_pswap **dst, t_pswap**src)
{
	int	i;
	int	first_index;

	if ((*dst)->pre->pre->label == 0)
		first_index = 0;
	else
		first_index = (*dst)->pre->pre->index + 1;
	i = 0;
	while ((median + i) < len)
	{
		if ((*src)->index >= (median + first_index))
		{
			pa_pb(dst, src, 'a');
			if (((median / 2) > 1)
				&& ((*dst)->index < ((median / 2) + first_index + median)))
			{
				(*dst)->label++;
				ra_rb(dst, 'a');
			}
			i++;
		}
		else
			ra_rb(src, 'b');
	}
}

int	send_half_big(int len, t_pswap **dst, t_pswap **src)
{
	int	i;
	int	median;

	median = (len % 2) + (len / 2);
	is_bigger(len, median, dst, src);
	i = 0;
	if ((median / 2) > 1)
	{
		while (i < (median / 2))
		{
			rra_rrb(dst, 'a');
			i++;
		}
	}
	return (median);
}

int	send_half_tiny(int len, t_pswap **dst, t_pswap **src)
{
	int	median;
	int	i;

	median = (len % 2) + (len / 2);
	i = 0;
	while (i < median)
	{
		if ((*src)->index < median)
		{
			pa_pb(dst, src, 'b');
			i++;
		}
		else
			ra_rb(src, 'a');
	}
	return (median);
}
