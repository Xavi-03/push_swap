/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:59 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:00 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_dlist **a_list, t_dlist **b_list, int size)
{
	if (size > 15)
		solver(&*a_list, &*b_list, size);
	else
		little_solver(&*a_list, &*b_list);
}

int	main(int argc, char **argv)
{
	t_dlist	*a_list;
	t_dlist	*b_list;

	if (argc < 2)
		return (0);
	a_list = NULL;
	b_list = NULL;
	if (parser(argv, &a_list))
	{
		write(2, "Error\n", 6);
		if (a_list)
			dellist(a_list);
		return (1);
	}
	ft_list_indexing(a_list);
	push_swap(&a_list, &b_list, ft_listlen(a_list));
	dellist(a_list);
	dellist(b_list);
	return (0);
}
