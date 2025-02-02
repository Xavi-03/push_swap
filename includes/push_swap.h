/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:55:00 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:55:03 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_dlist
{
	int				nbr;
	int				index;
	struct s_dlist	*next;	
}					t_dlist;

void	push_swap(t_dlist **a_list, t_dlist **b_list, int size);
int		parser(char **arr, t_dlist **list);
int		ft_parser_char_to_list(char *char_arr, t_dlist **list);
int		char_arr_len(char *char_arr);
int		ft_addnode(t_dlist **list, int nbr);
int		ft_listlen(t_dlist *list);
long	ft_atol(const char *nptr);
int		ft_numb_is_int(long nbr);
t_dlist	*ft_lastnode(t_dlist *list);
int		ft_list_checker(t_dlist *list);
void	ft_list_indexing(t_dlist *list);
void	sa(t_dlist **a_list);
void	sb(t_dlist **b_list);
void	ss(t_dlist **a_list, t_dlist **b_list);
void	pa(t_dlist **a_list, t_dlist **b_list);
void	pb(t_dlist **a_list, t_dlist **b_list);
void	ra(t_dlist **a_list);
void	rb(t_dlist **b_list);
void	rr(t_dlist **a_list, t_dlist **b_list);
void	rra(t_dlist **a_list);
void	rrb(t_dlist **b_list);
void	rrr(t_dlist **a_list, t_dlist **b_list);
int		solver(t_dlist **a_list, t_dlist **b_list, int size);
int		doublepivot_in_list(t_dlist *list, int pivot);
int		singlepivot_in_list(t_dlist *list, int pivot);
int		max_index_in_list(t_dlist *list, int max);
int		pivot_calculator(int size, int pivot_index, int count);
void	second_solver(t_dlist **a_list, t_dlist **b_list, int pivot);
int		pivotup_in_list(int pivot_up, int pivot_low, int flag);
int		if_under_pivot_reverse(int act_index, int flag);
int		no_more(int act_index, int flag);
void	solver_singlepivot(t_dlist **a_l, t_dlist **b_l, int p_min, int p_max);
void	return_pivotup(t_dlist **a_l, t_dlist **b_l, int p_low, int p_up);
void	return_lastpivot(t_dlist **a_l, t_dlist **b_l, int p_low, int p_up);
void	little_solver(t_dlist **a_l, t_dlist **b_l);
void	dellist(t_dlist *list);

#endif
