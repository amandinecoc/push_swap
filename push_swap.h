/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:27 by amandine          #+#    #+#             */
/*   Updated: 2025/10/03 17:17:30 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*INCLUDES*/
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

/* ************************************************************************** */
/*DOUBL_LIST*/
t_list				*list_new(int content);
void				list_add_back(t_list *list, int value);
void				print_list(t_list *list_n);
t_list				*pointer_first(t_list *list);
t_list				*pointer_last(t_list *list);
int					lenght_list(t_list *list);

/* ************************************************************************** */
/*COMMAND*/

// typedef struct s_list
// {
//     size_t length;
//     struct elem *p_last;
//     struct elem *p_first;
// } t_list;

#endif