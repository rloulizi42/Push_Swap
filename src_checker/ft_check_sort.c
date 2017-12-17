/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:55:42 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:53:19 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_sort(t_liste **begin_liste, t_liste **begin_liste_bis)
{
	if (!(*begin_liste_bis))
	{
		while ((*begin_liste)->next)
		{
			if ((*begin_liste)->nbr < (*begin_liste)->next->nbr)
				*begin_liste = (*begin_liste)->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
