/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:13:44 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:26:23 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* ************************************************************************** */
/*INCLUDES*/
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

/* ************************************************************************** */
/*TYPEDEF*/
typedef enum e_status
{
	Success,
	digit_failure,
	double_failure,
	already_sorted,
	malloc_failure,
	limit_failure,
}					t_status;

typedef struct s_list
{
	int				value;
	struct s_list	*p_prev;
	struct s_list	*p_next;
}					t_list;

typedef enum e_write_status
{
	yes_write = 1,
	not_write = 0,
}					t_write_status;

/* ************************************************************************** */
/*GET_NEXT_LINE*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
char	*get_next_line(int fd);
int		check_n_in_remaining_line(char **line, char *buffer);
int		check_n_in_next_line(char **line, char *buffer, int fd, int len_buf);
int		fill_remain_in_buffer(int i, char **tmp, char *buffer, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, int n);

/* ************************************************************************** */
/*PARSING*/
int					check_digit_and_handle_error(char **tab_str);
int					check_sorted_tab(int *tab, int len);
int					check_duplicata_value(int *tab, int len);
int					check_is_not_int_min_max_and_str_to_int(char **tab_str,
						int len, int *tab_input);
void				ft_printerror(int status);
void				free_tab_str(char **tab_str, int len);
int					len_tab(char **tab);
int					*create_sorted_index_tab(int *tab_input, int *tab_sorted,
						int len);
int					*sort_int_tab(int *tab_sorted, int len);
int					*tab_index_handler(int *tab_input, int len);
int					sorted_tab_index(char **tab_str, int **tab_index, int len);
int					create_input_str(char **str, char *argv);
int					create_tab_str(int argc, char **argv, char ***tab_str);

/* ************************************************************************** */
/*DOUBL_LIST*/
t_list				*list_new(int content);
void				list_add_back(t_list *list, int value);
t_list				*pointer_first(t_list *list);
t_list				*pointer_last(t_list *list);
int					lenght_list(t_list *list);
void	free_list_a(t_list **list_a);

/* ************************************************************************** */
/*COMMAND*/
void				swap_a(t_list **list_a, t_write_status status);
void				swap_b(t_list **list_b, t_write_status status);
void				swap_swap(t_list **list_a, t_list **list_b);
void				rotate_a(t_list **list_a, t_write_status status);
void				rotate_b(t_list **list_b, t_write_status status);
void				rotate_rotate(t_list **list_a, t_list **list_b);
void				reverse_rotate_a(t_list **list_a, t_write_status status);
void				reverse_rotate_b(t_list **list_b, t_write_status status);
void				reverse_rotate_rotate(t_list **list_a, t_list **list_b);
void				push_a(t_list **list_a, t_list **list_b);
void				push_b(t_list **list_a, t_list **list_b);

/* ************************************************************************** */
/*CHECKER*/


#endif