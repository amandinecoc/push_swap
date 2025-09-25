/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/09/25 13:46:39 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_digit_and_handle_error(char *str)
{
    int i;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 1)
		    i++;
        else
            return (digit_failure);
    }
    return (Success);
}

int len_tab(char **tab)
{
    int len;
    
    len = 0;
    while (tab[len] != NULL)
        len++;
    return (len);
}

int check_sorted_tab(int *tab, int len)
{
    int i;

    i = 0;
    while (i != len)
    {
        if (tab[i] > tab[i + 1])
            return (Success);
        i++;
    }
    return (already_sorted);
}

int check_duplicata_value(int *tab, int len)
{
    int i;
    int j;
    
    i = 0;
    while (i != len)
    {
        j = i + 1 ;
        while (j != len)
        {
            if (tab[i] == tab[j])
                return (double_failure);
            j++;
        }
        i++;
    }
    return (Success);
}

int *sort_int_tab(int *tab_sorted, int len)
{
    int i;
    int j;
    int temp;
    
    i = 0;
    temp = 0;
    while (i <= (len - 1))
    {
        j = i + 1;
        while (j <= (len - 1))
        {
            temp = tab_sorted[i];
            while (temp > tab_sorted[j] && j <= (len - 1))
            {
                temp = tab_sorted[j];
                tab_sorted[j] = tab_sorted[i];
                tab_sorted[i] = temp;
                j++;
            }
            j++;
        }
        i++;
    }
    return (tab_sorted);
}

int *create_sorted_index_tab(int *tab_input, int *tab_sorted, int len)
{
    int i;
    int j;
    int *tab_index;

    i = 0;
    tab_index = malloc(sizeof(int) * len);
    if (!tab_index)
        return (NULL);
    while (i <= (len - 1))
    {
        j = 0;
        while (j <= (len - 1))
        {
            if(tab_input[i] == tab_sorted[j])
            {
                tab_index[i] = j;
                printf("tab_index[%d] = %d\n", i, j);
            }
            j++;
        }
        i++;
    }
    return (tab_index);
}

int *tab_index_handler(int *tab_input, int len)
{
    int *tab_index;
    int *tab_sorted;
    int i;

    i = 0;
    tab_sorted = malloc(sizeof(char) * len);
    if (!tab_sorted)
        return (NULL);
    while (i < len)
    {
        tab_sorted[i] = tab_input[i];
        i++;
    }
    sort_int_tab(tab_sorted, len); 
    tab_index = create_sorted_index_tab(tab_input, tab_sorted, len);
    free(tab_input);
    free(tab_sorted);
    return (tab_index);
}

int push_swap(char **tab_str)
{
    int i;
    int len;
    int *tab_input;
    int *tab_index;

    i = 0;
    len = len_tab(tab_str);
    tab_input = malloc(sizeof(int) * len);
    if (!tab_input)
        return (malloc_failure);
    while (tab_str[i] != NULL)
    {
        if (check_digit_and_handle_error(tab_str[i]) == Success)
            i++;
        else
            return (digit_failure);
    }
    i = 0;
    while (i < len)
    {
        tab_input[i] = ft_atoll(tab_str[i]);         //gerer int min et int max const char *nptr
        i++;
    }
    if (check_duplicata_value(tab_input, len) == double_failure)
        return (double_failure);
    if (check_sorted_tab(tab_input, len) == already_sorted)
        return (already_sorted);
    tab_index = tab_index_handler(tab_input, len);
    if (tab_index == NULL)
        return (malloc_failure);
    free(tab_input);
    return (Success);
}

void ft_printerror(int status)
{
    if (status == digit_failure)
        ft_putendl_fd("ERROR : not a digit input", 2);
    if (status == double_failure)
        ft_putendl_fd("ERROR : number duplicata", 2);
    if (status == malloc_failure)
        ft_putendl_fd("ERROR : memory allocation", 2);
}

int main(int argc, char **argv)
{
    int i;
    char *str;
    char *temp;
    char **tab_str;
    int status;
    
    i = 2;
    if (argc <= 1)
        return (EXIT_FAILURE);
    str = ft_strdup(argv[1]);
    if (argc > 2)
    {
        while(i != argc)
        {
            temp = ft_strjoin(str," ");
            free(str);
            str = ft_strjoin(temp, argv[i++]);
            free(temp);
        }
    }
    tab_str = ft_split(str, ' ');
    free(str);
    if (tab_str == NULL)
        return (malloc_failure);
    status = push_swap(tab_str);
    ft_printerror(status);
    return (status);
}
