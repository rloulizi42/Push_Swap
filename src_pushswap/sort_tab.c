/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:15:11 by rloulizi          #+#    #+#             */
/*   Updated: 2017/10/13 18:43:40 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_tab(t_liste *begin_liste)
{
	int i;
	int *tab;

	tab = malloc(sizeof(int) * ft_listesize(begin_liste));
	i = 0;
	while (begin_liste)
	{
		tab[i] = begin_liste->nbr;
		begin_liste = begin_liste->next;
		i++;
	}
	return (tab);
}

void	ins(int *tab, int n, int elem)
{
	int i;

	i = n;
	while ((i != 0) && (elem < tab[i - 1]))
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[i] = elem;
}

void	sort_ins(int *tab, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		ins(tab, i, tab[i]);
		i++;
	}
}

void	print_tab(t_liste *begin_liste, int *tab)
{
	int i;

	i = 0;
	while (i < ft_listesize(begin_liste))
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
}
