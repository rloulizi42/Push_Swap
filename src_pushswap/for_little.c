/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_little.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:21:44 by rloulizi          #+#    #+#             */
/*   Updated: 2017/12/14 17:03:32 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_three(t_liste **begin_liste)
{
	if ((*begin_liste)->nbr > (*begin_liste)->next->nbr &&
			(*begin_liste)->nbr > last_list(begin_liste))
	{
		ft_putstr("ra\n");
		ra(begin_liste);
	}
	if ((*begin_liste)->nbr > (*begin_liste)->next->nbr &&
			(*begin_liste)->nbr < last_list(begin_liste))
	{
		ft_putstr("sa\n");
		sa(begin_liste);
	}
	if ((*begin_liste)->nbr < (*begin_liste)->next->nbr &&
			(*begin_liste)->next->nbr > last_list(begin_liste))
	{
		ft_putstr("rra\n");
		rra(begin_liste);
	}
	if ((*begin_liste)->nbr > (*begin_liste)->next->nbr)
	{
		ft_putstr("sa\n");
		sa(begin_liste);
	}
	return (0);
}

static int	ft_five(t_liste **begin_liste, t_liste **begin_liste_bis)
{
	if (ft_listesize(*begin_liste_bis) == 2)
		return (0);
	if ((*begin_liste)->nbr < (*begin_liste)->next->nbr &&
			(*begin_liste)->nbr < last_list(begin_liste))
	{
		ft_putstr("pb\n");
		pb(begin_liste, begin_liste_bis);
	}
	else if (last_list(begin_liste) < (*begin_liste)->nbr &&
			last_list(begin_liste) < (*begin_liste)->next->nbr)
	{
		ft_putstr("rra\n");
		rra(begin_liste);
	}
	else
	{
		ft_putstr("ra\n");
		ra(begin_liste);
	}
	ft_five(begin_liste, begin_liste_bis);
	return (0);
}

int			ft_little(t_liste **begin_liste, t_liste **begin_liste_bis)
{
	if (ft_listesize(*begin_liste) <= 3)
	{
		ft_three(begin_liste);
		return (0);
	}
	else if (ft_listesize(*begin_liste) <= 5)
	{
		ft_five(begin_liste, begin_liste_bis);
		ft_three(begin_liste);
		insertion_sort(begin_liste, begin_liste_bis);
		insertion_sort(begin_liste, begin_liste_bis);
		return (0);
	}
	return (0);
}
