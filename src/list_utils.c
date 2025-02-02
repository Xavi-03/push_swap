/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:12 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:14 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_listlen(t_dlist *list)
{
	int	i;

	i = 1;
	if (!list)
		return (0);
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_dlist	*ft_lastnode(t_dlist *list)
{
	t_dlist	*iteri;

	iteri = list;
	while (iteri->next)
		iteri = iteri->next;
	return (iteri);
}

int	ft_addnode(t_dlist **list, int nbr)
{
	t_dlist	*iteri;
	t_dlist	*new_node;

	iteri = *list;
	if (!nbr && !(nbr == 0))
		return (1);
	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (1);
	new_node->nbr = nbr;
	new_node->index = -1;
	new_node->next = NULL;
	if (!iteri)
	{
		*list = new_node;
		return (0);
	}
	while (iteri->next)
		iteri = iteri->next;
	iteri->next = new_node;
	return (0);
}

void	dellist(t_dlist *list)
{
	t_dlist	*iteri;

	while (list)
	{
		iteri = list;
		list = list->next;
		free(iteri);
	}
}
