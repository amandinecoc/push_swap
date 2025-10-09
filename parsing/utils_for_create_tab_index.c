/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_create_tab_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:15:20 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/09 11:16:01 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_tab_str(char **tab_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab_str[i++]);
	free(tab_str);
}

int	len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int create_input_str(char **str, char *argv)
{
	char *tmp;
	
	tmp = ft_strjoin(*str, " ");
	if (tmp == NULL)
		return (malloc_failure);
	free(*str);
	*str = ft_strjoin(tmp, argv);
	if (*str == NULL)
		return (free(tmp), malloc_failure);
	free(tmp);
	return(Success);
}
