/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:50:34 by rloulizi          #+#    #+#             */
/*   Updated: 2017/12/05 17:10:36 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			free_all(t_liste **liste)
{
	t_liste		*temp;
	t_liste		*temp2;

	temp = *liste;
	while (temp && temp->next)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
