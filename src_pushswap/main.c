/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:13:32 by rloulizi          #+#    #+#             */
/*   Updated: 2017/12/14 17:02:57 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_listesize(t_liste *begin_liste)
{
	int i;

	i = 0;
	while (begin_liste)
	{
		i++;
		begin_liste = begin_liste->next;
	}
	return (i);
}

static int	mainbis(t_liste *begin_liste, t_liste *begin_liste_bis)
{
	int *tab;
	int i;

	if (ft_listesize(begin_liste) <= 5)
		ft_little(&begin_liste, &begin_liste_bis);
	else
	{
		if (ft_listesize(begin_liste) <= 300)
			i = 9;
		else if (ft_listesize(begin_liste) <= 700)
			i = 22;
		while (begin_liste->next)
		{
			tab = create_tab(begin_liste);
			sort_ins(tab, ft_listesize(begin_liste));
			quicksort(&begin_liste, &begin_liste_bis, median_list(tab,
						begin_liste, i));
		}
		while (begin_liste_bis)
			insertion_sort(&begin_liste, &begin_liste_bis);
	}
	return (0);
}

static int	ret_err(t_liste **begin_liste)
{
	ft_putstr_fd("Error\n", 2);
	free_all(begin_liste);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_liste *begin_liste;
	t_liste *begin_liste_bis;
	int		i;

	begin_liste_bis = NULL;
	i = 0;
	if (argc <= 2)
		return (0);
	else
	{
		while (++i < argc)
		{
			if (is_num(argv[i]) && check_int(argv[i]))
				ft_list_push_back(&begin_liste, ft_atoi(argv[i]));
			else
				ret_err(&begin_liste);
			if (!ft_check_doublons(&begin_liste))
				ret_err(&begin_liste);
		}
		mainbis(begin_liste, begin_liste_bis);
	}
}
