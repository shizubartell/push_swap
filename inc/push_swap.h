/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:05:47 by abartell          #+#    #+#             */
/*   Updated: 2022/12/13 11:14:58 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define SWAP 2

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


#endif