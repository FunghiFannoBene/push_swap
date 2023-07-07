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

int	calculate_chunk_size(int length)
{
	double	chunk_size;

	chunk_size = 0.060 * length + 40.00;
	return (round_up(chunk_size));
}

void	push_up_or_down(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	if ((*a)->idx <= savechunk(0, 1) && (*a)->idx >= savechunk(0, 1)
		- startingchunk(0, 1))
		pb(a, b, tail_a, tail_b);
	else
	{
		pb(a, b, tail_a, tail_b);
		if ((*a) && (*a)->idx <= savechunk(0, 1))
			updownrotate(b, tail_b, "rb", 0);
		else
			rr(a, tail_a, b, tail_b);
	}
}

int	sortphase1(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b)
{
	while ((*a) && (*b) && saveactuallen(0, 1) != 0
		&& (((*tail_a)->idx < (*b)->idx) || (*tail_a)->idx == storage(0, 1))
		&& (*b)->idx != saveactuallen(0, 1))
	{
		pa(b, a, tail_b, tail_a);
		if ((*b)->idx != saveactuallen(0, 1) && fastestpath(b, saveactuallen(0,
					1)) > 0)
			rr(a, tail_a, b, tail_b);
		else
			updownrotate(a, tail_a, "ra", 0);
	}
	while ((*a) && (*tail_a)->idx == saveactuallen(0, 1))
	{
		updownrotate(a, tail_a, "rra", 0);
		saveactuallen(saveactuallen(0, 1) - 1, 0);
	}
	return (saveactuallen(0, 1));
}

int	versebuild(t_sw **b, int len)
{
	if (fastestpath(b, len) > 0)
		return (20);
	else
		return (40);
}
