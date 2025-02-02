/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:31 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:32 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	doublepivot_in_list(t_dlist *list, int pivot)
{
	while (list)
	{
		if (list->index <= pivot || list->index >= (pivot * 2))
			return (1);
		list = list->next;
	}
	return (0);
}

int	singlepivot_in_list(t_dlist *list, int pivot)
{
	while (list)
	{
		if (list->index > pivot && list->index < (pivot * 2))
			return (1);
		list = list->next;
	}
	return (0);
}

int	pivotup_in_list(int pivot_up, int pivot_low, int flag)
{
	static int	pivot_min = 0;
	static int	pivot_max = 0;

	if (flag)
	{
		pivot_min = (flag / 3) * 2;
		pivot_max = flag - 1;
	}
	if (pivot_min - 1 == pivot_low && pivot_max + 1 == pivot_up)
		return (0);
	return (pivot_min / 2);
}

int	if_under_pivot_reverse(int act_index, int flag)
{
	int static	pivot = 0;

	if (flag)
		pivot = flag;
	if (act_index < pivot)
		return (1);
	return (0);
}

int	no_more(int act_index, int flag)
{
	int static	limit = 0;

	if (flag)
	{
		limit = flag;
		return (0);
	}
	if (act_index <= limit)
		return (0);
	return (1);
}
