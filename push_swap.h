/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:49:00 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct t_sw
{
	int			val;
	int			idx;
	struct t_sw	*n;
	struct t_sw	*p;
}				t_sw;

void			sort_5(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
int				sortphase1(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
void			push_up_or_down(t_sw **a, t_sw **b, t_sw **tail_a,
					t_sw **tail_b);
void			sort_above_5(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
void			sa(int *val1, int *val2, int *ind1, int *ind2);
int				saveactuallen(int val, int save_return);
void			updownrotate(t_sw **head, t_sw **tail, char *d, int verse);
void			double_swap(t_sw **a, t_sw **b);
void			push(t_sw **push, t_sw **take, t_sw **t_push, t_sw **t_take);
void			rotate(t_sw **head, t_sw **tail, int up_down);
void			quicks(int *a, int first, int last);
void			pa(t_sw **pushr, t_sw **take, t_sw **t_push, t_sw **t_take);
void			sb(int *val1, int *val2, int *ind1, int *ind2);
void			pb(t_sw **pushr, t_sw **take, t_sw **t_push, t_sw **t_take);
void			main_sort(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
void			rr(t_sw **head, t_sw **tail, t_sw **head1, t_sw **tail1);
void			rrr(t_sw **head, t_sw **tail, t_sw **head1, t_sw **tail1);
void			chunk_v_shape(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
void			rotate_sort(t_sw **a, t_sw **b, t_sw **tail_a, t_sw **tail_b);
int				versebuild(t_sw **b, int len);
char			**ft_split1(char const *s, char c);
int				ft_wordlen(char **str);
int				startingchunk(int val, int save_return);
int				savechunk(int val, int save_return);
int				storage(int val, int save_return);
void			swapq(int *a, int *b);
int				check(int *index, int len, int val);
void			createascending(t_sw **a, t_sw **b, t_sw **tail_a,
					t_sw **tail_b);
int				calculate_chunk_size(int length);
int				round_up(double number);
int				fastestpath(t_sw **b, int len);
void			freeeverything(t_sw **a, t_sw **tail_a, t_sw **tail_b);
void			sort_3(t_sw **a, t_sw **tail_a);
int				ft_strcmp(char *s1, char *s2);
int				circular_struct_build(char **argv, t_sw **a, t_sw ***tail_a);
int				check(int *index, int len, int val);
int				ft_atoi(const char *str);
int				ft_printf(const char *s, ...);
void			error(void);
#endif
