/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:13:48 by amandine          #+#    #+#             */
/*   Updated: 2025/10/17 01:52:27 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ARG="2 3 A"; ./push_swap $ARG | ./checker_linux $ARG
// je recois une liste de chaine de caractère ou une chaine de caractère
// la fonction push_swap est lancé avec ARG 
// Puis le programme checker est lancée avec ARG 
// lire le fd 1 (sortie standart)
// parser ARG
// créer liste a et liste b
// gnl fd 1 et créer une chaine de caractère
// split la chaine créer
// foret de if pour appliquer les commandes sur list a
// si un element n'est pas une commande return error
// verif si list a trié et list b vide 

#include "checker.h"

int check_sort_list(t_list *list_a, int len)
{
	int newlen;

	newlen = lenght_list(list_a);
	if (len != newlen)
		return (EXIT_FAILURE);
	list_a = pointer_first(list_a);
	while (list_a != NULL)
	{
		if (list_a->value > list_a->p_next->value)
			return (EXIT_FAILURE);
		else
			list_a = list_a->p_next;
	}
	return (EXIT_SUCCESS);
}

int create_list_a(char **tab_str, int status)
{
    int		len;
	int		i;
	int		*tab_index;
	t_list	*list_a;

	i = 0;
	len = len_tab(tab_str);
	status = sorted_tab_index(tab_str, &tab_index, len);
	if (status != EXIT_SUCCESS)
		return (status);
	while (i < len)
	{
		if (i == 0)
		{
			list_a = list_new(tab_index[i++]);
			if (list_a == NULL)
				return (EXIT_FAILURE);
		}
		else
			list_add_back(list_a, tab_index[i++]);
	}
	len = lenght_list(list_a);
    if (create_and_sort_list_b_and_a(&list_a) != EXIT_SUCCESS)
		return (free(tab_index), free_list_a(&list_a), EXIT_FAILURE);
	if (check_sort_list(list_a, len) != EXIT_SUCCESS)
		return (free(tab_index), free_list_a(&list_a), EXIT_FAILURE);
	free(tab_index);
	free_list_a(&list_a);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char	**tab_str;
	int		status;

	if (argc <= 1)
		return (ft_putendl_fd("Error", 2), EXIT_FAILURE);
	status = create_tab_str(argc, argv, &tab_str);
	if (status != EXIT_SUCCESS)
		return (ft_putendl_fd("Error", 2), EXIT_FAILURE);
	status = create_list_a(tab_str, status);
	if (status != EXIT_SUCCESS)
		return (ft_putendl_fd("Error", 2), EXIT_FAILURE);
    
	return (status);
}
