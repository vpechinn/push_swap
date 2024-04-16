#include "push_swap.h"

void  ft_sa(t_stuck *st, int flag)
{
  t_list *tmp;

  if (!st->a || !st->a->next)
    return ;
  tmp = st->a;
  st->a = st->a->next;
  tmp->next = st->a->next;
  st->a->next = tmp;
  if (flag)
    write(1, "sa\n", 3);
}

void  ft_sb(t_stuck *st, int flag)
{
  t_list  *tmp;

  if (!st->b || !st->b->next)
    return ;
  tmp = st->b;
  st->b = st->b->next;
  tmp->next = st->b->next;
  st->b->next = tmp;
  if (flag)
    write(1, "sb\n", 3);
}

void  ft_ss(t_stuck *st, int flag)
{
  ft_sa(st, 0);
  ft_sb(st, 0);
  if (flag)
    write(1, "ss\n", 3);
}