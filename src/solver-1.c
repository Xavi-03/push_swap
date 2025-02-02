/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:13 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:15 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int static	pivot_min(t_dlist **a_l, t_dlist **b_l, int p_min, int p_max)
{
	static int	f_min = 0;

	if ((*a_l)->index == p_min)
	{
		pb(&*a_l, &*b_l);
		p_min++;
		if (f_min)
		{
			p_min++;
			sb(&*b_l);
			f_min = 0;
		}
	}
	else if ((*a_l)->index == p_min + 1 && !f_min && (p_max - p_min) > 6)
	{
		pb(&*a_l, &*b_l);
		f_min = 1;
	}
	return (p_min);
}

int static	pivot_max(t_dlist **a_l, t_dlist **b_l, int p_min, int p_max)
{
	static int	f_max = 0;

	if ((*a_l)->index == p_max)
	{
		pb(&*a_l, &*b_l);
		p_max--;
		if (f_max)
		{
			p_max--;
			rrb(&*b_l);
			sb(&*b_l);
			rb(&*b_l);
			f_max = 0;
		}
		rb(&*b_l);
	}
	else if ((*a_l)->index == p_max - 1 && !f_max && (p_max - p_min) > 6)
	{
		pb(&*a_l, &*b_l);
		rb(&*b_l);
		f_max = 1;
	}
	return (p_max);
}

void	solver_singlepivot(t_dlist **a_l, t_dlist **b_l, int p_min, int p_max)
{
	if (((*a_l)->index == p_min)
		|| ((*a_l)->index == p_min + 1 && (p_max - p_min) > 6))
		p_min = pivot_min(&*a_l, &*b_l, p_min, p_max);
	else if (((*a_l)->index == p_max)
		|| ((*a_l)->index == p_max - 1 && (p_max - p_min) > 6))
		p_max = pivot_max(&*a_l, &*b_l, p_min, p_max);
	else
		rra(&*a_l);
	if (ft_listlen(*a_l) > 0)
		solver_singlepivot(&*a_l, &*b_l, p_min, p_max);
}
