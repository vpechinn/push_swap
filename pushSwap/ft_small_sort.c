#include "push_swap.h"

t_list  *ft_read_list(t_list *st)
{
    t_list *tmp;
  
    tmp = st;
    while (tmp->next)
      tmp = tmp->next;
    return(tmp);
}

int ft_check_sort(t_stuck *st)
{
  t_list *tmp;

  tmp = st->a;
  if (!st->a)
    return (0);
  while (tmp->next)
  {
      if (tmp->idx > tmp->next->idx)
        return (0);
      tmp = tmp->next;
  }
  return (1);
}

void  ft_sort_three(t_stuck *st)
{
    while(!ft_check_sort(st))
    {
      if (st->a->idx > st->a->next->idx
        && st->a->idx > ft_read_list(st->a)->idx)
        ft_ra(st, 1);
      else if (st->a->idx > st->a->next->idx)
        ft_sa(st, 1);
      else
        ft_rra(st, 1);
    }
}

int ft_order(int min, t_stuck *st)
{
  int i;
  t_list *tmp;

  i = 1;
  tmp = st->a;
  while (tmp)
  {
    if (tmp->idx == min)
      return (i);
    tmp = tmp->next;
    i++;
  }
  return (1);
}

void  ft_sort_five(t_stuck *st)
{
  int len;

  st->next = 0;
  len = st->len;
  while (len != 3)
  {
    while (st->a->idx != st->next)
    {
      if (ft_order(st->next, st) <= 3)
        ft_ra(st, 1);
      else
        ft_rra(st, 1);
    }
    ft_pb(st, 1);
    st->next++;
    len--;
  }
  ft_sort_three(st);
  while (st->b)
    ft_pa(st,1);
}