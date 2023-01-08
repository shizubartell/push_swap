/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:49:52 by abartell          #+#    #+#             */
/*   Updated: 2022/12/29 09:24:13 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// adding to the front of the list
void	slistadd_front(t_pswap **lst, t_pswap *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->pre = *lst;
		(*lst)->next = new;
		(*lst)->pre = new;
		*lst = new;
	}
}

void	slistadd_back(t_pswap **lst, t_pswap *new)
{
	t_pswap	*last;

	if (*lst == NULL)
	{
		last = slistempty();
		*lst = new;
		(*lst)->next = last;
		(*lst)->pre = last;
		last->next = *lst;
		last->pre = *lst;
	}
	else
	{
		(*lst)->pre->pre->next = new;
		new->pre = (*lst)->pre->pre;
		(*lst)->pre->pre = new;
		new->next = (*lst)->pre;
	}
}

t_pswap *slistempty(void)
{
    t_pswap	*empty;

	empty = malloc(sizeof(t_pswap));
	if (empty == NULL)
		return (NULL);
	empty->val = NULL;
	empty->next = empty;
	empty->pre = empty;
	empty->index = -1;
	empty->label = -1;
	return (empty);
}

t_pswap	*slistnew(int value)
{
	t_pswap	*new;

	new = malloc(sizeof(t_pswap));
	if (new == NULL)
		return (NULL);
	new->val = malloc(sizeof(int));
	if (new->val == NULL)
		return (NULL);
	*(new->val) = value;
	new->next = new;
	new->pre = new;
	new->index = -1;
	new->label = 0;
	return (new);
}

void	slistclear(t_pswap **lst)
{
    t_pswap	*temp;

	while ((*lst)->val != NULL)
	{
		temp = (*lst)->next;
		free((*lst)->val);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
}

// adding slistadd_back
// empty slist 
// clearing slist