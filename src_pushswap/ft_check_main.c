/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:03:32 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/16 14:12:53 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	check_int(char *str)
{
	ssize_t i;
	ssize_t neg;
	ssize_t res;

	neg = 1;
	i = 0;
	res = 0;
	if (str[i] == '-')
	{
		neg = -1;
		str++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	if ((res < -2147483648) || (res > 2147483647))
		return (0);
	return (1);
}

int	ft_check_doublons(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste	*temp2;

	temp2 = *begin_liste;
	while (*begin_liste)
	{
		temp = *begin_liste;
		while (temp->next)
		{
			if ((*begin_liste)->nbr == temp->next->nbr)
				return (0);
			temp = temp->next;
		}
		*begin_liste = (*begin_liste)->next;
	}
	*begin_liste = temp2;
	return (1);
}
