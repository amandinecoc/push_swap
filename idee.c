/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idee.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:03:14 by acocoual          #+#    #+#             */
/*   Updated: 2025/09/19 22:50:11 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int len_next_nbr(char *str, int i)
{
    int len;

    len = 0;
    while (str[i] == ' ')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        len++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        len++;
        i++;
    }
    return (len);
}
int nbr_str_for_push(char *str, int *i, int *nbr)
{
    int j;
    int len;
    char *nbr1;
    
    j = 0;
    len = len_next_nbr(str, str[*i]);
    nbr1 = malloc(sizeof(char) * len + 1);
    while (str[*i] == ' ')
        *i = *i + 1;
    while (str[*i] == '-' || str[*i] == '+')
    {
        nbr1[j] = str[*i];
        j++;
        *i = *i + 1;
    }
    while (str[*i] != '\0' && str[*i] != ' ')
    {
        if (str[*i] >= '0' && str[*i] <= '9')
        {
            nbr1[j] = str[*i];
            j++;
            *i = *i + 1;
        }
        else 
            return (EXIT_FAILURE);
    }
    *nbr = ft_atoi(nbr1);
    return (EXIT_SUCCESS);
}

int push_str_in_pile_a(char *str, pile **MaPile)
{
    int i;
    int j;
    int nbr;
    
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if ((nbr_str_for_push(str, &i, &nbr)) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        Push(MaPile, nbr);
        i++;
    }
    return (EXIT_SUCCESS);
}

int main()
{
    pile *MaPile = NULL;
    char str[100] = " -4 52 88";
    int sortie;
    
    sortie = push_str_in_pile_a(str, &MaPile);
    if (sortie == EXIT_FAILURE)
    {
        printf("error\n");
        return (1);
    }
    puts("Affichage de la pile :");
    View(MaPile);       /* Affiche la totalité de la pile. */
    puts("------");

    printf("Nb d'elements : %d\n",Length(MaPile));
    puts("------");
    return (0);
}
