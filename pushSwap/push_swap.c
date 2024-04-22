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
  st->len = 0;
  while (ft_split(st->str, ' ')[st->len])
    st->len++;
  st->numbers = malloc(sizeof(int *) * (st->len));
  if (!st->numbers)
    return ;
  i = 0;
  while (i < st->len)
  {
    st->numbers[i] = ft_atoi(ft_split(st->str, ' ')[i]);
    i++;
  }
}

void  ft_check_args(t_stuck *st)
{
  int f;
  int i;
  int j;

  i = 0;
  f = 0;
  while (i < st->len)
  {
    j = i + 1;
    while (j < st->len) 
    {
      if (st->numbers[i] == st->numbers[j])
          ft_error();
      if (st->numbers[i] > st->numbers[i + 1])
          f = 1;
      j++;
    }
    i++;
  }
  if (!f)
    exit(0);
}

int	main(int ac, char *av[])
{
	t_stuck	st;
	
	if (ac == 1)
		return (1);
	ft_create_str(ac, av, &st);
  ft_check_args(&st);
  ft_create_stuck(&st);
  ft_sort_args(&st);
  ft_index(&st);
  if (st.len <= 3)
    ft_sort_three(&st);
  else if (st.len <= 5)
    ft_sort_five(&st);
  else
    ft_big_sort(&st);
  int i = 0;
  printf("%s\n", st.str);
  while (i < st.len)
  {
    printf("%d=%d\n", st.a->num, st.a->idx);
    st.a = st.a->next;
    i++;
  }
  // i = 0;
  // while (i < 5)
  // {
  //   printf("%d=%d\n", st.b->num, st.b->idx);
  //   st.b = st.b->next;
  //   i++;
  // }
  // while (i < 10)
  // {
  //   printf("%d ", st.numbers[i]);
  //   i++;
  // }
} 