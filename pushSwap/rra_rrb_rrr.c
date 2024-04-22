#include "push_swap.h"

void  ft_rra(t_stuck *st, int flag)
{
  t_list	*tmp;
	t_list	*tmp2;

	if (!st->a || !st->a->next)
		return ;
	tmp = st->a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = st->a;
	st->a = tmp2;
	if (flag)
		write(1, "rra\n", 4);
}

void  ft_rrb(t_stuck *st, int flag)
{
  t_list	*tmp;
	t_list	*tmp2;

	if (!st->b || !st->b->next)
		return ;
	tmp = st->b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = st->b;
	st->b = tmp2;
	if (flag)
		write(1, "rrb\n", 4);
}

void  ft_rrr(t_stuck *st, int flag)
{
  ft_rra(st, 0);
  ft_rrb(st, 0);
  if (flag)
    write(1, "rrr\n", 4);
}