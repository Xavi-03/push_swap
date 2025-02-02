/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:45 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:47 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_dlist **a_list)
{
	t_dlist	*last_iteri;

	if (!*a_list || !(*a_list)->next)
		return ;
	last_iteri = ft_lastnode(*a_list);
	last_iteri->next = *a_list;
	*a_list = (*a_list)->next;
	last_iteri = last_iteri->next;
	last_iteri->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_dlist **b_list)
{
	t_dlist	*last_iteri;

	if (!*b_list || !(*b_list)->next)
		return ;
	last_iteri = ft_lastnode(*b_list);
	last_iteri->next = *b_list;
	*b_list = (*b_list)->next;
	last_iteri = last_iteri->next;
	last_iteri->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_dlist **a_list, t_dlist **b_list)
{
	ra(&*a_list);
	rb(&*b_list);
}
