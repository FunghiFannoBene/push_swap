/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:48:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:48:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkpush(t_sw **push, t_sw **t_push)
{
	if ((*push)->n != *push)
	{
		*push = (*push)->n;
		(*t_push)->n = *push;
		(*push)->p = *t_push;
	}
	else
	{
		*push = NULL;
		*t_push = NULL;
	}
}

void	push(t_sw **push, t_sw **take, t_sw **t_push, t_sw **t_take)
{
	t_sw	*curr;

	if (*push == NULL)
		return ;
	curr = *push;
	checkpush(push, t_push);
	if (*take != NULL)
	{
		curr->n = *take;
		curr->p = (*take)->p;
		(*take)->p->n = curr;
		(*take)->p = curr;
		*take = curr;
	}
	else
	{
		curr->n = curr;
		curr->p = curr;
		*t_take = curr;
		*take = curr;
	}
	if (*t_take == NULL)
		*t_take = *take;
	(*t_take)->n = *take;
	(*take)->p = *t_take;
}

void	rotate(t_sw **head, t_sw **tail, int up_down)
{
	if (*head == NULL)
		return ;
	if (up_down == 1)
	{
		*tail = *head;
		*head = (*head)->n;
	}
	else if (up_down == -1)
	{
		*head = *tail;
		*tail = (*head)->p;
	}
}
