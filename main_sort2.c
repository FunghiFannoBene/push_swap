/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:16:26 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 18:16:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_sw **a, t_sw **tail_a)
{
	int	n_idx;
	int	nn_idx;

	n_idx = (*a)->n->idx;
	nn_idx = (*a)->n->n->idx;
	if ((*a)->idx > n_idx && n_idx < nn_idx && (*a)->idx < nn_idx)
		sa(&((*a)->val), &((*a)->n->val), &(*a)->idx, &n_idx);
	else if ((*a)->idx > n_idx && n_idx > nn_idx)
	{
		sa(&((*a)->val), &((*a)->n->val), &(*a)->idx, &n_idx);
		updownrotate(a, tail_a, "rra", 0);
	}
	else if ((*a)->idx > n_idx && n_idx < nn_idx && (*a)->idx > nn_idx)
		updownrotate(a, tail_a, "ra", 0);
	else if ((*a)->idx < n_idx && n_idx > nn_idx && (*a)->idx > nn_idx)
	{
		sa(&((*a)->val), &((*a)->n->val), &(*a)->idx, &n_idx);
		updownrotate(a, tail_a, "ra", 0);
		sa(&((*a)->val), &((*a)->n->val), &(*a)->idx, &n_idx);
	}
	else if ((*a)->idx < n_idx && n_idx > nn_idx)
	{
		updownrotate(a, tail_a, "rra", 0);
		sa(&((*a)->val), &((*a)->n->val), &(*a)->idx, &n_idx);
	}
}

int	fastestpath(t_sw **b, int len)
{
	int		forward_steps;
	int		backward_steps;
	t_sw	*forward;
	t_sw	*backward;

	forward_steps = 0;
	backward_steps = 0;
	if (*b == NULL)
		return (-1);
	forward = *b;
	backward = (*b)->p;
	while (forward_steps < len && backward_steps < len)
	{
		if (forward->idx == len)
			return (forward_steps);
		if (backward->idx == len)
			return (-backward_steps);
		forward = forward->n;
		backward = backward->p;
		forward_steps++;
		backward_steps++;
	}
	return (-1);
}

int	round_up(double number)
{
	int		integer_part;
	double	decimal_part;

	integer_part = (int)number;
	decimal_part = number - integer_part;
	if (decimal_part > 0)
	{
		return (integer_part + 1);
	}
	else
	{
		return (integer_part);
	}
}

void	ch_ascending(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	if ((*a)->n->idx > (*a)->idx)
	{
		if ((*b)->idx < (*b)->n->idx)
			double_swap(a, b);
		else
			sa(&((*a)->val), &((*a)->n->val), &((*a)->idx), &((*a)->n->idx));
	}
	if ((*b) && (*b)->idx > (*a)->idx)
		pa(b, a, tail_b, tail_a);
	if ((*b) && (*b)->idx < (*a)->idx && (*b)->idx > (*a)->n->idx)
	{
		pa(b, a, tail_b, tail_a);
		if ((*b) && (*b)->idx < (*b)->n->idx)
			double_swap(a, b);
		else
			sa(&((*a)->val), &((*a)->n->val), &((*a)->idx), &((*a)->n->idx));
	}
	if ((*b) && (*b)->idx < (*tail_b)->idx)
		rr(a, tail_a, b, tail_b);
	else
		updownrotate(a, tail_a, "ra", 0);
}

void	createascending(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	int	plen;

	plen = (*a)->idx;
	updownrotate(a, tail_a, "ra", 0);
	updownrotate(a, tail_a, "ra", 0);
	while ((*a)->idx != plen)
	{
		if ((*a)->idx != plen && (*a)->idx > (*tail_a)->idx)
		{
			ch_ascending(a, b, tail_a, tail_b);
		}
		else
			pb(a, b, tail_a, tail_b);
		if ((*a)->idx == plen)
			break ;
	}
}
