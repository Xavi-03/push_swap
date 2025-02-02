/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:17 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:19 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void static	solver_from_atob(t_dlist **a_l, t_dlist **b_l, int pivot)
{
	if ((*a_l)->index == pivot)
	{
		pb(&*a_l, &*b_l);
		pivot++;
	}
	else
		rra(&*a_l);
	if (ft_listlen(*a_l) > 2)
		solver_from_atob(&*a_l, &*b_l, pivot);
}

void static	return_from_btoa(t_dlist **a_l, t_dlist **b_l, int pivot)
{
	if ((*b_l)->index == pivot)
	{
		pa(&*a_l, &*b_l);
		pivot--;
	}
	else
		rb(&*b_l);
	if (ft_listlen(*b_l) > 0)
		return_from_btoa(&*a_l, &*b_l, pivot);
}

void static	last_condition(t_dlist **a_l)
{
	sa(&*a_l);
	ra(&*a_l);
	ra(&*a_l);
}

void static	three_exception(t_dlist **a_l, t_dlist **b_l)
{
	if ((*a_l)->index == 0)
	{
		pb(&*a_l, &*b_l);
		ra(&*a_l);
		pa(&*a_l, &*b_l);
	}
	else if ((*a_l)->next->index == 0)
	{
		if ((*a_l)->index == 1)
			sa(&*a_l);
		else
			ra(&*a_l);
	}
	else
	{
		if ((*a_l)->index == 1)
		{
			ra(&*a_l);
			ra(&*a_l);
		}
		else
			last_condition(&*a_l);
	}
}

void	little_solver(t_dlist **a_l, t_dlist **b_l)
{
	t_dlist	*iteri;
	int		i;

	i = 0;
	iteri = *a_l;
	while (iteri)
	{
		if (iteri->index != i++)
			break ;
		iteri = iteri->next;
	}
	if (ft_listlen(*a_l) == 1 || ft_listlen(*a_l) == i)
		return ;
	else if (ft_listlen(*a_l) == 2)
	{
		rra(&*a_l);
		return ;
	}
	else if (ft_listlen(*a_l) == 3)
		return (three_exception(&*a_l, &*b_l));
	solver_from_atob(&*a_l, &*b_l, 0);
	if ((*a_l)->index > (*a_l)->next->index)
		rra(&*a_l);
	return_from_btoa(&*a_l, &*b_l, (*a_l)->index - 1);
}
