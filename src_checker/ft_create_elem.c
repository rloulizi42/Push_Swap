/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:08:12 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/10 18:55:52 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
