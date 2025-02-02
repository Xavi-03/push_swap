/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:55 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:56 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	static	char_to_int(char *str, int *nbr, int i, int flag)
{
	if (i > 10 || i == 0)
		return (1);
	if (flag)
	{
		if (ft_strncmp(str, "2147483648", 11) > 0 && i == 10)
			return (1);
		return (*nbr = -ft_atoi(str), 0);
	}
	if (ft_strncmp(str, "2147483647", 11) > 0 && i == 10)
		return (1);
	return (*nbr = ft_atoi(str), 0);
}

int static	arg_to_list(char *str, int *nbr)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = 1;
		str++;
	}
	while (str[0] == '0' && str[1] != '\0')
		str++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (char_to_int(str, &*nbr, i, flag));
}

int	parser(char **arr, t_dlist **list)
{
	int	i;
	int	nbr;

	i = 0;
	while (arr[++i])
	{
		if (arg_to_list(arr[i], &nbr))
			return (1);
		ft_addnode(&*list, nbr);
	}
	return (ft_list_checker(*list));
}
