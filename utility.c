/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:35:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/06 23:35:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	swapq(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_wordlen(char **str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	return (i);
}

void	freelist(t_sw **a)
{
	t_sw	*current;
	t_sw	*next;

	if (a == NULL || *a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		next = current->n;
		free(current);
		current = next;
		if (current == *a)
			break ;
	}
	*a = NULL;
}

void	freeeverything(t_sw **a, t_sw **tail_a, t_sw **tail_b)
{
	if (*a != NULL)
		freelist(a);
	free(tail_a);
	free(tail_b);
	if (storage(0, 1) == -1)
		error();
}
