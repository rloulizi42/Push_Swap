/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:17:40 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:39:09 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_push_back(t_liste **begin_liste, int nbr)
{
	t_liste *new;

	new = *begin_liste;
	if (new)
	{
		while (new->next != NULL)
			new = new->next;
		new->next = ft_create_elem(nbr);
	}
	else
		*begin_liste = ft_create_elem(nbr);
}
