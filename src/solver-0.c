/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver-0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:09 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:10 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void static	solver_doublepivot_rec(t_dlist **a_list, t_dlist **b_list,
	int pivot_low, int pivot_up)
{
	if ((*a_list)->index <= pivot_low)
		pb(&*a_list, &*b_list);
	else if ((*a_list)->index >= pivot_up)
	{
		pb(&*a_list, &*b_list);
		rb(&*b_list);
	}
	else
		ra(&*a_list);
	if (doublepivot_in_list(*a_list, pivot_low))
		solver_doublepivot_rec(&*a_list, &*b_list, pivot_low, pivot_up);
}

void static	return_singlepivot_rec(t_dlist **a_list, t_dlist **b_list,
	int act_index, int pivot)
{
	if ((*b_list)->index == act_index)
	{
		act_index--;
		pa(&*a_list, &*b_list);
	}
	else
		rrb(&*b_list);
	if (singlepivot_in_list(*b_list, pivot))
		return_singlepivot_rec(&*a_list, &*b_list, act_index, pivot);
}

int	solver(t_dlist **a_list, t_dlist **b_list, int size)
{
	int	pivot_index;

	if (size % 3)
		pivot_index = (size - 1) / 3;
	else
		pivot_index = size / 3;
	solver_doublepivot_rec(&*a_list, &*b_list, pivot_index, pivot_index * 2);
	solver_singlepivot(&*a_list, &*b_list, pivot_index + 1,
		(pivot_index * 2) - 1);
	while ((*b_list)->index != (pivot_index * 2))
		rrb(&*b_list);
	pivotup_in_list(0, 0, size);
	if_under_pivot_reverse(0, pivot_index * 2);
	no_more(0, (pivot_index * 2) - 1);
	return_pivotup(&*a_list, &*b_list, (pivot_index * 2) + (pivot_index / 2),
		(pivot_index * 2) + (pivot_index / 2) + 1);
	while ((*b_list)->index != (pivot_index * 2) - 1)
		rb(&*b_list);
	return_singlepivot_rec(&*a_list, &*b_list,
		(*b_list)->index, pivot_index - 1);
	return_lastpivot(&*a_list, &*b_list, 0, (*a_list)->index - 1);
	while ((*a_list)->index != 0)
		rra(&*a_list);
	return (1);
}
