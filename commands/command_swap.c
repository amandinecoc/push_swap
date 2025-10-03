/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:41 by amandine          #+#    #+#             */
/*   Updated: 2025/10/03 17:16:25 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a. 
// Ne fait rien s’il n’y en a qu’un ou aucun

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b. 
// Ne fait rien s’il n’y en a qu’un ou aucun.

// ss : sa et sb en même temps.

void swap_a(t_list *list_a)
{
    t_list *tmp;

    list_a = pointer_first(list_a);
    if (list_a == NULL && list_a->p_next == NULL)
		return;
    tmp = list_a;
	list_a = list_a->p_next;
	list_a->p_prev = NULL;
	tmp->p_next = list_a->p_next;
	list_a->p_next = tmp;
	tmp->p_prev = list_a;
	ft_putendl_fd("sa", 2);
}