/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:33:23 by rloulizi          #+#    #+#             */
/*   Updated: 2017/11/01 15:36:38 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_after_pb(t_liste **begin_liste_bis)
{
	if ((*begin_liste_bis) && (*begin_liste_bis)->next &&
			last_list(begin_liste_bis) > (*begin_liste_bis)->nbr)
	{
		ft_putstr("rb\n");
		rb(begin_liste_bis);
	}
	if ((*begin_liste_bis)->next && (*begin_liste_bis)->nbr
			< (*begin_liste_bis)->next->nbr)
	{
		ft_putstr("sb\n");
		sb(begin_liste_bis);
	}
}

void			quicksort(t_liste **begin_liste, t_liste **begin_liste_bis,
		int median)
{
	if ((*begin_liste)->nbr < median)
	{
		ft_putstr("pb\n");
		pb(begin_liste, begin_liste_bis);
		check_after_pb(begin_liste_bis);
	}
	else if (checkposbymedian(*begin_liste, median))
	{
		ft_putstr("ra\n");
		ra(begin_liste);
	}
	else
	{
		ft_putstr("rra\n");
		rra(begin_liste);
	}
	if (checknbrbymedian(*begin_liste, median))
		quicksort(begin_liste, begin_liste_bis, median);
}
