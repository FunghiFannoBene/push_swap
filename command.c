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

void	rr(t_sw **head, t_sw **tail, t_sw **head1, t_sw **tail1)
{
	rotate(head, tail, 1);
	rotate(head1, tail1, 1);
	ft_printf("rr\n");
}

void	rrr(t_sw **head, t_sw **tail, t_sw **head1, t_sw **tail1)
{
	rotate(head, tail, -1);
	rotate(head1, tail1, -1);
	ft_printf("rrr\n");
}

void	sa(int *val1, int *val2, int *ind1, int *ind2)
{
	int	tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	tmp = *ind1;
	*ind1 = *ind2;
	*ind2 = tmp;
	ft_printf("sa\n");
}

void	sb(int *val1, int *val2, int *ind1, int *ind2)
{
	int	tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	tmp = *ind1;
	*ind1 = *ind2;
	*ind2 = tmp;
	ft_printf("sb\n");
}

void	double_swap(t_sw **a, t_sw **b)
{
	int	tmp;

	tmp = (*a)->idx;
	(*a)->idx = (*a)->n->idx;
	(*a)->n->idx = tmp;
	tmp = (*a)->val;
	(*a)->val = (*a)->n->val;
	(*a)->n->val = tmp;
	tmp = (*b)->idx;
	(*b)->idx = (*b)->n->idx;
	(*b)->n->idx = tmp;
	tmp = (*b)->val;
	(*b)->val = (*b)->n->val;
	(*b)->n->val = tmp;
	ft_printf("ss\n");
}
