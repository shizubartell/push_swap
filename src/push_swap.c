/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:05:58 by abartell          #+#    #+#             */
/*   Updated: 2023/01/07 07:59:22 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_pswap	*stacka;
	t_pswap	*stackb;
	int		len;
	int		flag;

	if (argc == 1)
		return ;
	stacka = slistempty();
	stackb = slistempty();
	len = argc - 1;
	flag = argchecker(len, argv, &stacka);
	if (flag == SUCCESS)
	{
		index_setup(len, &stacka);
		solution(len, &stacka, &stackb);
	}
	else
		ft_putendl_fd("ERROR", 2);
	slistclear(&stacka);
	slistclear(&stackb);
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

long long	to_int(const char *str)
{
	long long	number;
	int			sign;

	sign = 1;
	if (*str == '+' && *(str + 1) != '\0')
		str++;
	else if (*str == '-' && *(str + 1) != '\0')
	{
		sign = -1;
		str++;
	}
	if (*str == '\0')
		return (NOT_INT);
	number = 0;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (NOT_INT);
		number *= 10;
		number += (*str - '0');
		if (!(number == INT_MAX + 1ll && sign == -1) && (INT_MAX < number))
			return (NOT_INT);
		str++;
	}
	return (number * sign);
}

int	argchecker(int len, char *argv[], t_pswap **a)
{
	long long	i;
	long long	n;
	int			flag;

	i = 1;
	while (i <= len)
	{
		n = to_int(argv[i]);
		if (n == NOT_INT)
			return (NOPE);
		else
		{
			if (i == 1)
				slistadd_front(a, slistnew((int)n));
			else
			{
				flag = doubles((int)n, a);
				if (flag == NOPE)
					return (NOPE);
				slistadd_back(a, slistnew((int)n));
			}
		}
		i++;
	}
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
