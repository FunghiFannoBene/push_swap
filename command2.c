/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:02:36 by marvin            #+#    #+#             */
/*   Updated: 2023/07/07 02:02:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_sw **pushr, t_sw **take, t_sw **t_push, t_sw **t_take)
{
	push(pushr, take, t_push, t_take);
	ft_printf("pa\n");
}

void	pb(t_sw **pushr, t_sw **take, t_sw **t_push, t_sw **t_take)
{
	push(pushr, take, t_push, t_take);
	ft_printf("pb\n");
}

void	updownrotate(t_sw **head, t_sw **tail, char *d, int verse)
{
	int	up_down;

	if (ft_strcmp("rra", d) == 0 || ft_strcmp("rrb", d) == 0 || verse == 40)
		up_down = -1;
	else if (ft_strcmp("ra", d) == 0 || ft_strcmp("rb", d) == 0 || verse == 20)
		up_down = 1;
	rotate(head, tail, up_down);
	if (verse == 20)
		ft_printf("rb\n");
	else if (verse == 40)
		ft_printf("rrb\n");
	else
		ft_printf("%s\n", d);
}
