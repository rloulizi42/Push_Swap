/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:13:32 by rloulizi          #+#    #+#             */
/*   Updated: 2017/12/05 18:52:28 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				is_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int				check_int(char *str)
{
	ssize_t i;
	ssize_t neg;
	ssize_t res;

	neg = 1;
	i = 0;
	res = 0;
	if (str[i] == '-')
	{
		neg = -1;
		str++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	if ((res < -2147483648) || (res > 2147483647))
		return (0);
	return (1);
}

static int		ft_check_doublons(t_liste **begin_liste)
{
	t_liste *temp;
	t_liste	*temp2;

	temp2 = *begin_liste;
	while (*begin_liste)
	{
		temp = *begin_liste;
		while (temp->next)
		{
			if ((*begin_liste)->nbr == temp->next->nbr)
				return (0);
			temp = temp->next;
		}
		*begin_liste = (*begin_liste)->next;
	}
	*begin_liste = temp2;
	return (1);
}

static int		mainbis(t_liste *begin_liste, t_liste *begin_liste_bis)
{
	char *str;

	str = NULL;
	if (!ft_check_doublons(&begin_liste))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(&begin_liste);
		return (0);
	}
	while (get_next_line(0, &str))
	{
		if (!ft_check(str, &begin_liste, &begin_liste_bis))
		{
			ft_putstr_fd("Error\n", 2);
			free_all(&begin_liste);
			free_all(&begin_liste_bis);
			return (0);
		}
	}
	if (ft_check_sort(&begin_liste, &begin_liste_bis))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_liste *begin_liste;
	t_liste *begin_liste_bis;
	int		i;

	i = 0;
	begin_liste_bis = NULL;
	if (argc < 2)
		return (0);
	else
	{
		while (++i < argc)
		{
			if (is_num(argv[i]) && check_int(argv[i]))
				ft_list_push_back(&begin_liste, ft_atoi(argv[i]));
			else
			{
				ft_putstr_fd("Error\n", 2);
				free_all(&begin_liste);
				free_all(&begin_liste_bis);
				return (0);
			}
		}
		mainbis(begin_liste, begin_liste_bis);
	}
}
