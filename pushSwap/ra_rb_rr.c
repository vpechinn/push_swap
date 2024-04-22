#include "push_swap.h"

void  ft_ra(t_stuck *st, int flag)
{
  t_list *tmp;
  t_list *tmp2;
  
  if (!st->a || !st->a->next)
    return ;
  
  tmp2 = st->a;
  while (tmp2->next)
    tmp2 = tmp2->next;
  
  tmp = st->a;
  st->a = st->a->next;
  tmp2->next = tmp;
  tmp->next = 0;
  if (flag)
    write(1, "ra\n", 3);
}

void  ft_rb(t_stuck *st, int flag)
{
  t_list *tmp;
  t_list *tmp2;
  
  if (!st->b || !st->b->next)
    return ;
  
  tmp2 = st->b;
  while (tmp2->next)
    tmp2 = tmp2->next;
  
  tmp = st->b;
  st->b = st->b->next;
  tmp2->next = tmp;
  tmp->next = 0;
  if (flag)
    write(1, "rb\n", 3);
}

void  ft_rr(t_stuck *st, int flag)
{
  ft_ra(st, 0);
  ft_rb(st, 0);
  if (flag)
    write(1, "rr\n", 3);
}