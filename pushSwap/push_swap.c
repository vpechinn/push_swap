/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:13:41 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:19 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_str(int	ac, char **av, t_stuck *st)
{
	int	i;

	i = 2;
	st->str = ft_strdup(av[1]);
	while (i < ac)
	{
		st->str = ft_strjoin(ft_strjoin(st->str, " "), av[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_stuck	st;
	
	if (ac == 1)
		return (1);
	ft_create_str(ac, av, &st);
}