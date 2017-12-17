/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:08:12 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:38:54 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_create_elem(int nbr)
{
	t_liste *new;

	new = malloc(sizeof(t_liste));
	if (new)
	{
		new->nbr = nbr;
		new->next = NULL;
	}
	return (new);
}
