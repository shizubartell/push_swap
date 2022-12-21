/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:05:58 by abartell          #+#    #+#             */
/*   Updated: 2022/12/21 11:15:48 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_pswap	*stacka;
	t_pswap	*stackb;

	if (argc == 1)
		return ;
	stacka = dlstempty();
	stackb = dlstempty();
	dlstclear(&stacka);
	dlstclear(&stackb);
    // adding successflag, adding args
    // using length of the input
}

// int      inputchecker

// checking for double numbers in the input
// of the given stack a since in the beginning
// stack a is supposed to have an amount of 
// negative/positive numbers which can't be
// doubled
int	doubles(int n, t_pswap **a)
{
	while ((*a)->val != NULL)
	{
		if ((int)n == (*(*a)->val))
			return (NOPE);
		*a = (*a)->next;
	}
	*a = (*a)->next;
	return (SUCCESS);
}

// going through the index and setting up stack a
// from the min number of the given input to the
// index
void	index_setup(int len, t_pswap **a)
{
	t_pswap	*i;
	int		index;

	index = 0;
	while (index < len)
	{
		while ((*a)->index != -1)
			*a = (*a)->next;
		i = *a;
		*a = (*a)->next;
		while ((*a)->val != NULL)
		{
			if (((*a)->index == -1) && (*(i->val) > *((*a)->val)))
				i = *a;
			*a = (*a)->next;
		}
		*a = (*a)->next;
		i->index = index;
		index++;
	}
}
