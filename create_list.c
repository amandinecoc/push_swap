/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:33:04 by amandine          #+#    #+#             */
/*   Updated: 2025/09/28 15:49:55 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list_a *list_a_new(void)
{
    list_a *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_first = NULL;
        p_new->p_last = NULL;
    }
    return p_new;
}

list_a *list_a_prepend(list_a *p_list, int value)
{
    if (p_list != NULL)
    {
        struct elem *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->value = value;
            p_new->p_prev = NULL;
            if (p_list->p_last == NULL)
            {
                p_new->p_next = NULL;
                p_list->p_first = p_new;
                p_list->p_last = p_new;
            }
            else
            {
                p_list->p_first->p_prev = p_new;
                p_new->p_next = p_list->p_first;
                p_list->p_first = p_new;
            }
            p_list->length++;
       }
    }
    return p_list;
}

void View(list_a)
{
   elem *pelem = p_first;
   while(pelem)
   {
     printf("%d\n",pelem->value);
     pelem = pelem->p_next;
   }
}
