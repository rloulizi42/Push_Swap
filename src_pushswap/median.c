/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:17:08 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:40:28 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		last_list(t_liste **begin_liste)
{
	int		i;
	t_liste *temp;

	temp = *begin_liste;
	while (*begin_liste && (*begin_liste)->next)
		*begin_liste = (*begin_liste)->next;
	i = (*begin_liste)->nbr;
	*begin_liste = temp;
	return (i);
}

int		median_list(int *tab, t_liste *begin_liste, int i)
{
	int j;

	j = 0;
	while (j < i && j < ft_listesize(begin_liste) - 1)
		j++;
	return (tab[j]);
}

int		checknbrbymedian(t_liste *begin_liste, int median)
{
	while (begin_liste)
	{
		if ((begin_liste)->nbr < median)
			return (1);
		begin_liste = (begin_liste)->next;
	}
	return (0);
}

int		checkposbymedian(t_liste *begin_liste, int median)
{
	int i;

	i = 0;
	while (begin_liste && begin_liste->nbr >= median)
	{
		begin_liste = begin_liste->next;
		i++;
	}
	if (i < ft_listesize(begin_liste))
		return (1);
	else
		return (0);
}
