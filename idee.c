/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idee.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:03:14 by acocoual          #+#    #+#             */
/*   Updated: 2025/09/19 20:07:28 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int count_space(char *)
// {
//     int i;
//     int space;
    
//     i = 0;
//     space =0;

//     while (str[i] != '\0')
//     {
//         if (str[i] == ' ')
//             space++;
//         i++;
//     }
//     return (space);
// }

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (n > 0)
	{
		*tmp_s = 0;
		tmp_s++;
		n--;
	}
}

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

int push_str_in_pile_a(char *str, pile **MaPile)
{
    int i;
    int len_char;
    char nbr[100];
    
    i = 0;
    while (str[i] != '\0')
    {
        len_char = 0;
        while (str[i] == ' ')
            i++;
        while (str[i] == '-' || str[i] == '+')
        {
            nbr[len_char] = str[i];
            len_char++;
            i++;
        }
        while (str[i] != '\0' && str[i] != ' ')
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                nbr[len_char] = str[i];
                len_char++;
                i++;
            }
            else 
                return (EXIT_FAILURE);
        }
        if (len_char > 0)
            Push(MaPile, ft_atoi(nbr));
        ft_bzero(nbr, 100);
        i++;
    }
    return (EXIT_SUCCESS);
}

int main()
{
    pile *MaPile = NULL;
    char str[100] = "+++++++++4 -85";
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
