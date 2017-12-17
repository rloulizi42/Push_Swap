/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:51:13 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:52:05 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste *temp2;

	temp = *begin_liste;
	if (temp)
	{
		temp2 = (*begin_liste)->next;
		while ((*begin_liste)->next)
			*begin_liste = (*begin_liste)->next;
		(*begin_liste)->next = temp;
		temp->next = NULL;
		(*begin_liste) = temp2;
	}
}

void	rb(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste *temp2;

	temp = *begin_liste;
	if (temp)
	{
		temp2 = (*begin_liste)->next;
		while ((*begin_liste)->next)
			*begin_liste = (*begin_liste)->next;
		(*begin_liste)->next = temp;
		temp->next = NULL;
		(*begin_liste) = temp2;
	}
}

void	rra(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste *temp2;

	temp = *begin_liste;
	if (temp && temp->next)
	{
		while ((*begin_liste)->next->next)
			*begin_liste = (*begin_liste)->next;
		temp2 = (*begin_liste)->next;
		(*begin_liste)->next = NULL;
		temp2->next = temp;
		*begin_liste = temp2;
	}
}

void	rrb(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste *temp2;

	temp = *begin_liste;
	if (temp && temp->next)
	{
		while ((*begin_liste)->next->next)
			*begin_liste = (*begin_liste)->next;
		temp2 = (*begin_liste)->next;
		(*begin_liste)->next = NULL;
		temp2->next = temp;
		*begin_liste = temp2;
	}
}
