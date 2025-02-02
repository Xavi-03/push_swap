/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver-3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:24 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:25 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int static	pivot_low(t_dlist **a_l, t_dlist **b_l, int p_low)
{
	static int	f_low = 0;

	if ((*b_l)->index == p_low)
	{
		pa(&*a_l, &*b_l);
		p_low++;
		if (f_low)
		{
			p_low++;
			f_low = 0;
			rra(&*a_l);
			sa(&*a_l);
			ra(&*a_l);
		}
		ra(&*a_l);
	}
	else if ((*b_l)->index == p_low + 1 && !f_low && ft_listlen(*b_l) > 7)
	{
		f_low = 1;
		pa(&*a_l, &*b_l);
		ra(&*a_l);
	}
	return (p_low);
}

int static	pivot_up(t_dlist **a_l, t_dlist **b_l, int p_up)
{
	static int	f_up = 0;

	if ((*b_l)->index == p_up)
	{
		pa(&*a_l, &*b_l);
		p_up--;
		if (f_up)
		{
			p_up--;
			sa(&*a_l);
			f_up = 0;
		}
	}
	else if ((*b_l)->index == p_up - 1 && !f_up && ft_listlen(*b_l) > 7)
	{
		f_up = 1;
		pa(&*a_l, &*b_l);
	}
	return (p_up);
}

void	return_lastpivot(t_dlist **a_l, t_dlist **b_l, int p_low, int p_up)
{
	if ((*b_l)->index == p_low
		|| ((*b_l)->index == p_low + 1 && ft_listlen(*b_l) > 7))
		p_low = pivot_low(&*a_l, &*b_l, p_low);
	else if ((*b_l)->index == p_up
		|| ((*b_l)->index == p_up - 1 && ft_listlen(*b_l) > 7))
		p_up = pivot_up(&*a_l, &*b_l, p_up);
	else
		rrb(&*b_l);
	if (ft_listlen(*b_l) > 0)
		return_lastpivot(&*a_l, &*b_l, p_low, p_up);
}
