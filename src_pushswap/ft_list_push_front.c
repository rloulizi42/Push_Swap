/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:30:05 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:39:19 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_push_front(t_liste **begin_liste, int nbr)
{
	t_liste *new;

	if (*begin_liste)
	{
		new = ft_create_elem(nbr);
		new->next = *begin_liste;
		*begin_liste = new;
	}
	else
		*begin_liste = ft_create_elem(nbr);
}
