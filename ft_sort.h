/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:52:35 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:52:37 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SORT_H
# define FT_SORT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}			t_list;

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		checksorted(int *array, int len);
int		lenght(char **str);
int		same_num(int a, int b, int *array);
void	stack_build(int *array, int len);
t_list	*lstnew(int value);
int		lstsize(t_list *head);
t_list	*lstlast(t_list *head);
void	lstadd_back(t_list **stackA, t_list *new);
void	sort(t_list **stackA, t_list **stackB, int len);
void	free_stack(t_list **stack);
int		stack_checksort(t_list **stack);
void	sa(t_list **stackA);
void	sb(t_list **stackB);
void	ra(t_list **stackA);
void	rra(t_list **stackA);
void	pb(t_list **stackA, t_list **stackB);
void	pa(t_list **stackA, t_list **stackB);
void	radix_sort(t_list **stackA, t_list **stackB, int len);
void	little_sort(t_list **stackA);

#endif /* ft_sort_h */
