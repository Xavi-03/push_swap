/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:52:59 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:10 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dlist	*ft_indexator(t_dlist *list)
{
	static long long	min_index = LLONG_MIN;
	long long			min;
	t_dlist				*act_min;

	min = LLONG_MAX;
	act_min = NULL;
	while (list)
	{
		if (min > list->nbr && list->nbr > min_index && list->index < 0)
		{
			min = list->nbr;
			if (min_index < min)
				act_min = list;
		}
		list = list->next;
	}
	if (min_index < min)
	{
		min_index = act_min->nbr;
		return (act_min);
	}
	return (NULL);
}

void	ft_list_indexing(t_dlist *list)
{
	t_dlist	*iteri;
	int		i;
	int		max_loops;

	i = 0;
	iteri = list;
	max_loops = ft_listlen(list);
	while (i < max_loops)
	{
		iteri = ft_indexator(list);
		if (iteri)
			iteri->index = i;
		i++;
	}
}
