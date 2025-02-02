/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:54:35 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/30 16:54:36 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	long	ft_asigner(char nptr, long nb)
{
	nb *= 10;
	nb += ((long)nptr - '0');
	return (nb);
}

long	ft_atol(char const *nptr)
{
	long	nb;
	long	sign;

	nb = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (*nptr && (*nptr >= 48 && *nptr <= 57))
		nb = ft_asigner(*nptr++, nb);
	if (nb == 0)
		return (0);
	return (sign * nb);
}

int	ft_numb_is_int(long nbr)
{
	if (nbr <= INT_MAX && nbr >= INT_MIN)
		return (0);
	return (1);
}

int	ft_list_checker(t_dlist *list)
{
	int		nbr;
	t_dlist	*iteri;

	if (!list)
		return (1);
	iteri = list->next;
	nbr = list->nbr;
	while (iteri)
	{
		if (nbr == iteri->nbr)
			return (1);
		iteri = iteri->next;
	}
	if (list->next)
	{
		if (ft_list_checker(list->next))
			return (1);
	}
	return (0);
}
