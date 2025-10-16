/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:13:48 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:35:57 by amandine         ###   ########.fr       */
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

sort_and_create_list_b(t_list **list_a)
{
    
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
	if (status != Success)
		return (status);
	while (i < len)
	{
		if (i == 0)
		{
			list_a = list_new(tab_index[i++]);
			if (list_a == NULL)
				return (malloc_failure);
		}
		else
			list_add_back(list_a, tab_index[i++]);
	}
    sort_and_create_list_b(&list_a);
	free(tab_index);
	free_list_a(&list_a);
	return (Success);
}

int	main(int argc, char **argv)
{
	char	**tab_str;
	int		status;

	if (argc <= 1)
		return (ft_printerror(status), EXIT_FAILURE);
	status = create_tab_str(argc, argv, &tab_str);
	if (status != Success)
		return (ft_printerror(status), status);
	status = create_list_a(tab_str, status);
	ft_printerror(status);
    
	return (status);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./fichier.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

