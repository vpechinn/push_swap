/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:51:14 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/15 21:35:31 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				idx;
	int				flag;
	struct s_list	*next;
} t_list;

typedef struct s_stuck
{
	int		len;
	int		next;
	int		*numbers;
	char	*str;
	t_list	*a;
	t_list	*b;
} t_stuck;

t_list  *ft_read_list(t_list *st);


char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int   ft_atoi(const char *str);
int ft_check_next(t_stuck *st);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);

void  ft_error(void);
void  ft_create_stuck(t_stuck *st);
void  ft_sort_args(t_stuck *st);
void  ft_index(t_stuck *st);
void  ft_sort_three(t_stuck *st);
void  ft_sort_five(t_stuck *st);
void  ft_big_sort(t_stuck *st);

void  ft_ra(t_stuck *st, int flag);
void  ft_rb(t_stuck *st, int flag);
void  ft_rr(t_stuck *st, int flag);
void  ft_sa(t_stuck *st, int flag);
void  ft_sb(t_stuck *st, int flag);
void  ft_ss(t_stuck *st, int flag);
void  ft_rra(t_stuck *st, int flag);
void  ft_rrb(t_stuck *st, int flag);
void  ft_rrr(t_stuck *st, int flag);
void  ft_pa(t_stuck *st, int flag);
void  ft_pb(t_stuck *st, int flag);


#endif