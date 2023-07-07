/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_nation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/07/07 06:03:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	storage(int val, int save_return)
{
	static int	value;

	if (save_return == 0)
		value = val;
	else if (value)
		return (value);
	return (0);
}

int	startingchunk(int val, int save_return)
{
	static int	value;

	if (save_return == 0)
		value = val;
	else if (value)
		return (value);
	return (0);
}

int	savechunk(int val, int save_return)
{
	static int	value;

	if (save_return == 0)
		value = val;
	else if (value)
		return (value);
	return (0);
}

int	saveactuallen(int val, int save_return)
{
	static int	value;

	if (save_return == 0)
		value = val;
	else if (value)
		return (value);
	return (0);
}
