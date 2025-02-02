/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:50 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:51 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_dlist **a_list)
{
	t_dlist	*last_iteri;
	t_dlist	*new_last_iteri;

	if (!*a_list || !(*a_list)->next)
		return ;
	new_last_iteri = *a_list;
	while (new_last_iteri->next->next)
		new_last_iteri = new_last_iteri->next;
	last_iteri = new_last_iteri->next;
	new_last_iteri->next = NULL;
	last_iteri->next = *a_list;
	*a_list = last_iteri;
	ft_printf("rra\n");
}

void	rrb(t_dlist **b_list)
{
	t_dlist	*last_iteri;
	t_dlist	*new_last_iteri;

	if (!*b_list || !(*b_list)->next)
		return ;
	new_last_iteri = *b_list;
	while (new_last_iteri->next->next)
		new_last_iteri = new_last_iteri->next;
	last_iteri = new_last_iteri->next;
	new_last_iteri->next = NULL;
	last_iteri->next = *b_list;
	*b_list = last_iteri;
	ft_printf("rrb\n");
}

void	rrr(t_dlist **a_list, t_dlist **b_list)
{
	rra(&*a_list);
	rrb(&*b_list);
}
