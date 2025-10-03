/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:41:14 by amandine          #+#    #+#             */
/*   Updated: 2025/10/03 16:03:13 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*pointer_first(t_list *list)
{
	while (list->p_prev != NULL)
		list = list->p_prev;
	return (list);
}

t_list	*pointer_last(t_list *list)
{
	while (list->p_next != NULL)
		list = list->p_next;
	return (list);
}

int	lenght_list(t_list *list)
{
	int len;

	len = 0;
	list = pointer_first(list);
	while (list->p_next != NULL)
	{
		list = list->p_next;
		len++;
	}
	return (len);
}
