/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:05:47 by abartell          #+#    #+#             */
/*   Updated: 2022/12/14 22:19:08 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define SWAP 2
# define R 0
# define RR 1
# define SORT -1

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct s_pswap
{
	int				*val;
	int				label;
	struct s_pswap	*next;
	struct s_pswap	*pre;
}	t_pswap;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//**** SWAPING.C ****//

void				sa_and_sb(t_pswap **lst, char stack);
void				ss(t_pswap **a, t_pswap **b);
void				swap_rotate(t_pswap **lst, int flag);

//**** PUSHING.C ****//

void				pa_and_pb(t_pswap **dst, t_pswap **src, char stack);

//**** SORTING.C ****//

void				sort_two(t_pswap **lst, char stack);
void				sort_two_rev(t_pswap **lst, char stack);

//**** LISTS.C ****//



//**** ROTATING.C ****//

#endif