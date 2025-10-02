/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:33:04 by amandine          #+#    #+#             */
/*   Updated: 2025/10/02 19:38:58 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *list_new(int content)
{
    t_list *p_new = malloc(sizeof(t_list));
    if (p_new != NULL)
    {
        p_new->value = content;
        p_new->p_next = NULL;
        p_new->p_prev = NULL;
    }
    return p_new;
}

void    list_add_back(t_list **p_list, int value)
{
    t_list *elem;

    if (p_list == NULL)
        return;
    elem = list_new(value);
    if (elem == NULL)
        return;
    while((*p_list)->p_next != NULL)
        (*p_list) = (*p_list)->p_next;
    (*p_list)->p_next = elem;
    elem->p_prev = (*p_list);
}

void print_list(t_list *list)
{
    
    while(list->p_prev != NULL)
        list = list->p_prev;
    while(list->p_next != NULL)
    {
        printf("elem %d\n",list->value);
        list = list->p_next;
    }
    printf("elem %d\n",list->value);
}
