#include "push_swap.h"

void  ft_index(t_stuck *st)
{
  int		i;
	t_list	*tmp;

	tmp = st->a;
	while (tmp)
	{
		i = 0;
		while (i < st->len)
    {
			if (tmp->num == st->numbers[i])
				tmp->idx = i;
      i++;
    }
		tmp = tmp->next;
	}
}

void  ft_sort_args(t_stuck *st)
{
  int i;
  int tmp;
  int f;

  f = 1;
  while (f == 1)
  {
    i = 0;
    f = 0;
    while (i < st->len - 1)
    {
      if (st->numbers[i] > st->numbers[i + 1])
      {
        tmp = st->numbers[i];
        st->numbers[i] = st->numbers[i + 1];
        st->numbers[i + 1] = tmp;
        f = 1;
      }
      i++;
    }
  }
}

t_list *ft_init_list(int n)
{
  t_list *tmp;

  tmp = malloc(sizeof(t_list));
  if (!tmp)
    ft_error();
  tmp->flag = 0;
  tmp->num = n;
  tmp->next = NULL;
  return (tmp);
}

void  ft_create_stuck(t_stuck *st)
{
  int i;
  t_list *tmp;

  i = 0;
  st->a = ft_init_list(st->numbers[i]);
  tmp = st->a;
  i++;
  while (i < st->len)
  {
    tmp->next = ft_init_list(st->numbers[i]);
    tmp = tmp->next;
    i++;
  }
}