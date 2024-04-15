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


char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);

#endif