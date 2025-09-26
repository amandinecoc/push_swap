/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:27 by amandine          #+#    #+#             */
/*   Updated: 2025/09/26 11:51:41 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	check_digit_and_handle_error(char **tab_str);
int	check_sorted_tab(int *tab, int len);
int	check_duplicata_value(int *tab, int len);
int	check_is_not_int_min_max_and_str_to_int(char **tab_str, int len, int *tab_input);
void	ft_printerror(int status);
void	free_tab_str(char **tab_str, int len);
int	len_tab(char **tab);
int	*create_sorted_index_tab(int *tab_input, int *tab_sorted, int len);
int	*sort_int_tab(int *tab_sorted, int len);
int	*tab_index_handler(int *tab_input, int len);

typedef enum
{
    Success,
    digit_failure,
    double_failure,
    already_sorted,
    malloc_failure,
    limit_failure,
}status;


#endif