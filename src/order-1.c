/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:34 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:37 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_dlist **a_list, t_dlist **b_list)
{
	t_dlist	*first_iteri;

	if (!*b_list)
		return ;
	first_iteri = *b_list;
	if ((*b_list)->next)
		*b_list = (*b_list)->next;
	else
		*b_list = NULL;
	first_iteri->next = *a_list;
	*a_list = first_iteri;
	ft_printf("pa\n");
}

void	pb(t_dlist **a_list, t_dlist **b_list)
{
	t_dlist	*first_iteri;

	if (!*a_list)
		return ;
	first_iteri = *a_list;
	if ((*a_list)->next)
		*a_list = (*a_list)->next;
	else
		*a_list = NULL;
	first_iteri->next = *b_list;
	*b_list = first_iteri;
	ft_printf("pb\n");
}
