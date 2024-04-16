#include "push_swap.h"

void  ft_pb(t_stuck *st, int flag)
{
  t_list *tmp;

  if (!st->a)
    return ;
  tmp = st->a;
  st->a = st->a->next;
  tmp->next = st->b;
  st->b = tmp;
  if (flag)
    write(1, "pb\n", 3);
}

void  ft_pa(t_stuck *st, int flag)
{
  t_list *tmp;
  if (!st->b)
    return ;
  tmp = st->b;
  st->b = st->b->next;
  tmp->next = st->a;
  st->a = tmp;
  if (flag)
    write(1, "pa\n", 3);
}