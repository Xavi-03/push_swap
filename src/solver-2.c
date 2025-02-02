/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver-2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:18 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:20 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int static	pivot_low(t_dlist **a_l, t_dlist **b_l, int p_low)
{
	static int	f_low = 0;

	if ((*b_l)->index == p_low && no_more((*b_l)->index, 0))
	{
		pa(&*a_l, &*b_l);
		p_low--;
		if (f_low)
		{
			sa(&*a_l);
			p_low--;
			f_low = 0;
		}
	}
	else if ((*b_l)->index == p_low - 1
		&& !f_low && no_more((*b_l)->index - 1, 0))
	{
		pa(&*a_l, &*b_l);
		f_low = 1;
	}
	return (p_low);
}

int static	pivot_up(t_dlist **a_l, t_dlist **b_l, int p_low, int p_up)
{
	static int	f_up = 0;

	if ((*b_l)->index == p_up)
	{
		pa(&*a_l, &*b_l);
		p_up++;
		if (f_up)
		{
			rra(&*a_l);
			sa(&*a_l);
			ra(&*a_l);
			f_up = 0;
			p_up++;
		}
		ra(&*a_l);
	}
	else if ((*b_l)->index == p_up + 1 && !f_up
		&& (pivotup_in_list(p_up, p_low, 0) - (p_up - p_low)) > 7)
	{
		pa(&*a_l, &*b_l);
		ra(&*a_l);
		f_up = 1;
	}
	return (p_up);
}

int static	if_condition(t_dlist **b_l, int p_up, int p_low, int flag)
{
	if (!flag)
	{
		return (((*b_l)->index == p_low && no_more((*b_l)->index, 0))
			|| ((*b_l)->index == p_low - 1 && no_more((*b_l)->index - 1, 0)));
	}
	else if (flag)
	{
		return ((*b_l)->index == p_up || ((*b_l)->index == p_up + 1
				&& (pivotup_in_list(p_up, p_low, 0) - (p_up - p_low)) > 7));
	}
	return (0);
}

void	return_pivotup(t_dlist **a_l, t_dlist **b_l, int p_low, int p_up)
{
	static int	flag = 1;

	if ((*b_l)->index != p_low && (*b_l)->index != p_up)
	{
		if (if_under_pivot_reverse((*b_l)->index, 0))
			flag = -flag;
		if (if_under_pivot_reverse((*b_l)->index, 0)
			&& if_under_pivot_reverse((*b_l)->next->index, 0))
			rrb(&*b_l);
	}
	if (if_condition(&*b_l, p_up, p_low, 0))
		p_low = pivot_low(&*a_l, &*b_l, p_low);
	else if (if_condition(&*b_l, p_up, p_low, 1))
		p_up = pivot_up(&*a_l, &*b_l, p_low, p_up);
	else
	{
		if (flag > 0)
			rrb(&*b_l);
		else if (flag < 0)
			rb(&*b_l);
	}
	if (pivotup_in_list(p_up, p_low, 0))
		return_pivotup(&*a_l, &*b_l, p_low, p_up);
}
