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

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-999999);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		error();
	return (mod * i);
}

int	check_error(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == -999999)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_sw	*a;
	t_sw	*b;
	t_sw	**tail_a;
	t_sw	**tail_b;

	if (argc > 1)
	{
		if (check_error(argv) == -1)
			error();
		tail_a = malloc(sizeof(t_sw *));
		tail_b = malloc(sizeof(t_sw *));
		a = NULL;
		b = NULL;
		*tail_a = NULL;
		*tail_b = NULL;
		if (argc == 2)
			argv = ft_split1(argv[1], ' ');
		storage(circular_struct_build(argv, &a, &tail_a), 0);
		if (storage(0, 1) == -1)
			freeeverything(&a, tail_a, tail_b);
		main_sort(&a, &b, tail_a, tail_b);
		freeeverything(&a, tail_a, tail_b);
	}
}
