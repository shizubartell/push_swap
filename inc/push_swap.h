/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:05:47 by abartell          #+#    #+#             */
/*   Updated: 2023/01/07 08:05:58 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

# define NOPE 0
# define SUCCESS 1
# define SWAP 2
# define R 0
# define RR 1
# define SORT -1
# define NOT_INT INT_MAX + 1ll

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct s_pswap
{
	int				*val;
	int				label;
	int				index;
	struct s_pswap	*next;
	struct s_pswap	*pre;
}	t_pswap;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//**** SWAPING.C ****//

void				sa_sb(t_pswap **lst, char stack);
void				ss(t_pswap **a, t_pswap **b);
void				swap_rotate(t_pswap **lst, int flag);

//**** PUSHING.C ****//

void				pa_pb(t_pswap **dst, t_pswap **src, char stack);

//**** SORTING.C ****//

void				labelswitch(t_pswap **lst);
void				sort_two(t_pswap **lst, char stack);
void				sort_two_rev(t_pswap **lst, char stack);
void				sort_three(t_pswap **lst, char stack);
void				sort_three_rev(t_pswap **lst, char stack);

//**** LISTS.C ****//

void				slistadd_front(t_pswap **lst, t_pswap *new);
void				slistadd_back(t_pswap **lst, t_pswap *new);
t_pswap				*slistempty(void);
t_pswap				*slistnew(int value);
void				slistclear(t_pswap **lst);

//**** ROTATING.C ****//

void				ra_rb(t_pswap **lst, char stack);
void				rr(t_pswap **a, t_pswap **b);
void				rra_rrb(t_pswap **lst, char stack);
void				rrr(t_pswap **a, t_pswap **b);

//**** PUSH_SWAP.C ****//

void				push_swap(int argc, char *argv[]);
int					argchecker(int len, char *argv[], t_pswap **a);
void				index_setup(int len, t_pswap **a);

//**** MECHANICS01.C ****//

void				rotate_for_sorting(t_pswap **a);
void				is_bigger(int len, int median, t_pswap **dst, t_pswap**src);
int					send_half_big(int len, t_pswap **dst, t_pswap **src);
int					send_half_tiny(int len, t_pswap **dst, t_pswap **src);

//**** SWAP_PUSH.C ****//

void				solution(int len, t_pswap **a, t_pswap **b);
void				find_three(int len, t_pswap **a, t_pswap **b);
int					sorted(t_pswap **lst);
void				sort_up_to_six(int len, t_pswap **a, t_pswap **b);

#endif