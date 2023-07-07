/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:15:49 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 18:15:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int *index, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (index[i] == val)
			return (i + 1);
		i++;
	}
	return (i + 1);
}

int	ft_storeword(char **str, int *index)
{
	int	i;

	i = 1;
	while (str[i])
	{
		index[i - 1] = ft_atoi(str[i]);
		i++;
	}
	return (i);
}

void	create_list(char **argv, t_sw **element_i, int *index, int len)
{
	t_sw	*tmp;
	int		i;

	i = 2;
	while (argv[i])
	{
		tmp = *element_i;
		*element_i = malloc(sizeof(t_sw));
		(*element_i)->val = ft_atoi(argv[i]);
		(*element_i)->idx = check(index, len, (*element_i)->val);
		(*element_i)->n = NULL;
		(*element_i)->p = tmp;
		tmp->n = *element_i;
		i++;
	}
}

int	checkdouble(int len, int *index)
{
	int	i;

	i = 0;
	while (i < len)
	{
		i++;
		if (index[i] == index[i - 1])
			return (-1);
	}
	return (1);
}

int	circular_struct_build(char **argv, t_sw **a, t_sw ***tail_a)
{
	int		*index;
	int		len;
	t_sw	*element_i;

	element_i = malloc(sizeof(t_sw));
	index = malloc(sizeof(int) * ft_wordlen(argv) - 1);
	len = ft_storeword(argv, index) - 1;
	quicks(index, 0, len - 1);
	if (checkdouble(len, index) == -1)
	{
		free(index);
		free(element_i);
		return (-1);
	}
	element_i->val = ft_atoi(argv[1]);
	element_i->idx = check(index, len, element_i->val);
	element_i->n = NULL;
	*a = element_i;
	create_list(argv, &element_i, index, len);
	(*a)->p = element_i;
	**tail_a = element_i;
	(**tail_a)->n = *a;
	free(index);
	return (len);
}
