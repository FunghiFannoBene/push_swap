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

void	chunk_v_shape(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	int	chunk;
	int	count;

	chunk = calculate_chunk_size(storage(0, 1));
	count = startingchunk(chunk / 2, 0);
	while (*a)
	{
		if ((*a)->idx == storage(0, 1) && chunk > (storage(0, 1) / 15 * 14))
		{
			createascending(a, b, tail_a, tail_b);
			break ;
		}
		if (((*a)->idx <= chunk))
		{
			count += 1 + savechunk(chunk, 0);
			push_up_or_down(a, b, tail_a, tail_b);
		}
		else
			updownrotate(a, tail_a, "ra", 0);
		if (count == chunk)
			chunk = chunk + startingchunk(0, 1) + (startingchunk(0, 1) / 2);
	}
}

void	rotate_sort(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	int	verse;
	int	len;

	len = (*a)->idx - 1;
	while (len >= 0)
	{
		len = saveactuallen(len, 0) + sortphase1(a, b, tail_a, tail_b);
		verse = versebuild(b, len);
		while ((*b) && (*b)->idx != len)
		{
			if ((*b)->idx > (*tail_a)->idx && (*b)->idx != len)
			{
				pa(b, a, tail_b, tail_a);
				if ((*b)->idx != len && verse == 20)
					rr(a, tail_a, b, tail_b);
				else
					updownrotate(a, tail_a, "ra", 0);
			}
			else
				updownrotate(b, tail_b, "verse", verse);
		}
		pa(b, a, tail_b, tail_a);
		len--;
	}
}

void	sort_above_5(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	chunk_v_shape(a, b, tail_a, tail_b);
	rotate_sort(a, b, tail_a, tail_b);
}

void	sort_5(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	int	count;
	int	len;

	len = storage(0, 1);
	count = len - 3;
	while (count)
	{
		if ((*a)->idx == 1 || ((*a)->idx == 2 && len == 5))
		{
			pb(a, b, tail_a, tail_b);
			count--;
		}
		else
			updownrotate(a, tail_a, "ra", 0);
	}
	sort_3(a, tail_a);
	count = len - 3;
	while (count--)
		pa(b, a, tail_b, tail_a);
	if ((*a)->idx > (*a)->n->idx)
		sa(&((*a)->val), &((*a)->n->val), &((*a)->idx), &((*a)->n->idx));
}

void	main_sort(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	int	len;

	len = storage(0, 1);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if ((*a)->idx > (*a)->n->idx)
			sa(&((*a)->val), &((*a)->n->val), &((*a)->idx), &((*a)->n->idx));
	}
	else if (len == 3)
		sort_3(a, tail_a);
	else if (len == 4 || len == 5)
		sort_5(a, b, tail_a, tail_b);
	else
		sort_above_5(a, b, tail_a, tail_b);
}

//calculate_chunk_size(len); //ottimale 70 per 500; //46 per 100