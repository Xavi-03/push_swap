/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:27 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:28 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_dlist **a_list)
{
	t_dlist	*first_iteri;
	t_dlist	*second_iteri;

	if (!*a_list || !(*a_list)->next)
		return ;
	first_iteri = *a_list;
	second_iteri = (*a_list)->next;
	first_iteri->next = first_iteri->next->next;
	second_iteri->next = first_iteri;
	*a_list = second_iteri;
	ft_printf("sa\n");
}

void	sb(t_dlist **b_list)
{
	t_dlist	*first_iteri;
	t_dlist	*second_iteri;

	if (!*b_list || !(*b_list)->next)
		return ;
	first_iteri = *b_list;
	second_iteri = (*b_list)->next;
	first_iteri->next = first_iteri->next->next;
	second_iteri->next = first_iteri;
	*b_list = second_iteri;
	ft_printf("sb\n");
}

void	ss(t_dlist **a_list, t_dlist **b_list)
{
	sa(&*a_list);
	sb(&*b_list);
}
