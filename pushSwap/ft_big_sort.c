#include "push_swap.h"

int ft_count(t_list *st)
{
  int i;
  
  i = 0;
  while (st)
  {
    i++;
    st = st->next;
  }
  return (i);
}

int ft_push_to_sort(t_stuck *st, int f)
{
  if (f)
    ft_pa(st, 1);
  st->a->flag = -1;
  ft_ra(st, 1);
  st->next++;
  ft_check_next(st);
  return (1);
}

int ft_check_next(t_stuck *st)
{
  if (st->a->idx == st->next)
    return (ft_push_to_sort(st, 0));
  if (ft_count(st->b) > 0 && st->b->idx == st->next)
    return (ft_push_to_sort(st, 1));
  if (ft_count(st->b) >= 3 && ft_read_list(st->b)->idx == st->next)
  {
    ft_rrb(st, 1);
    return (ft_push_to_sort(st, 1));
  }
  if (ft_count(st->b) > 1 && st->b->next->idx == st->next + 1
  && st->a->next->idx == st->next)
  {
    ft_ss(st, 1);
    st->a->flag = -1;
    ft_ra(st, 1);
    st->next++;
    return (ft_push_to_sort(st, 1));
  }
  return (0);
}

void  ft_void_b(t_stuck *st, int f)
{
  int i;
  int k;
  int mid;
  
  while (st->b)
  {
    i = 0;
    f++;
    k = ft_count(st->b);
    mid = k / 2 + st->next + 2;
    while (st->b && i < k)
    {
      st->b->flag = f;
      if (st->b->idx >= mid || st->b->idx == st->next)
      {
        ft_pa(st, 1);
        ft_check_next(st);
      }
      else
        ft_rb(st, 1);
      i++;
    }
  }
}

void  ft_big_sort(t_stuck *st)
{
  int i;
  int f;

  i = 0;
  st->next = 0;
  while (i < st->len)
  {
    if (st->a->idx <= st->len / 2)
      ft_pb(st, 1);
    else
      ft_ra(st, 1);
    i++;
  }
  while (st->next < st->len)
  {
    f = st->a->flag;
    while (st->a && st->a->flag == f && st->next > 0)
        if (!ft_check_next(st))
            ft_pb(st, 1);
    ft_void_b(st, f);
  }
}