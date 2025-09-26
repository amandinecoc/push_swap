/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_doublement_chainee.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:04:33 by amandine          #+#    #+#             */
/*   Updated: 2025/09/26 22:52:07 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct nbr
{
    int data;
    struct nbr *p_next;
    struct nbr *p_prev;
};

typedef struct list_a
{
    size_t length;
    struct nbr *p_last;
    struct nbr *p_first;
} list_a;

//list_a *list = NULL; /* Déclaration d'une liste vide */

//Allouer une nouvelle liste

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

//int *p_data = malloc(sizeof *p_data);

//Ajout en fin de liste

list_a *list_a_append(list_a *p_list, int data)
{
    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct nbr *p_new = malloc(sizeof *p_new); /* Création d'un nouveau nbr */
        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new->data = data; /* On 'enregistre' notre donnée */
            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
            if (p_list->p_last == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
            {
                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
                p_list->p_first = p_new; /* On fait pointer la tête de liste vers le nouvel élément */
                p_list->p_last = p_new; /* On fait pointer la fin de liste vers le nouvel élément */
            }
            else /* Cas où des éléments sont déjà présents dans notre liste */
            {
                p_list->p_last->p_next = p_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
                p_new->p_prev = p_list->p_last; /* On fait pointer p_prev vers le dernier élément de la liste */
                p_list->p_last = p_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
            }
            p_list->length++; /* Incrémentation de la taille de la liste */
        }
    }
    return p_list; /* on retourne notre nouvelle liste */
}

//Ajout en début de liste

list_a *list_a_prepend(list_a *p_list, int data)
{
    if (p_list != NULL)
    {
        struct nbr *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
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

//Insérer un élément

list_a *list_a_insert(list_a *p_list, int data, int position)
{
    if (p_list != NULL)
    {
        struct nbr *p_temp = p_list->p_first;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = list_a_append(p_list, data);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = list_a_prepend(p_list, data);
                }
                else
                {
                    struct nbr *p_new = malloc(sizeof *p_new);;
                    if (p_new != NULL)
                    {
                        p_new->data = data;
                        p_temp->p_next->p_prev = p_new;
                        p_temp->p_prev->p_next = p_new;
                        p_new->p_prev = p_temp->p_prev;
                        p_new->p_next = p_temp;
                        p_list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

//Liberer une liste

void list_a_delete(list_a **p_list)
{
    if (*p_list != NULL)
    {
        struct nbr *p_temp = (*p_list)->p_first;
        while (p_temp != NULL)
        {
            struct nbr *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}

//taille de la liste chainee

size_t list_a_length(list_a *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

//Recherche un élément selon sa valeur

list_a *list_a_find(list_a *p_list, int data)
{
    list_a *ret = NULL;
    if (p_list != NULL)
    {
        struct nbr *p_temp = p_list->p_first;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->data == data)
            {
                ret = list_a_new();
                ret = list_a_append(ret, data);
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return ret;
}
//Recherche un ensemble d'éléments selon une même valeur

list_a *list_a_find_all(list_a *p_list, int data)
{
    list_a *ret = NULL;
    if (p_list != NULL)
    {
        struct nbr *p_temp = p_list->p_first;
        while (p_temp != NULL)
        {
            if (p_temp->data == data)
            {
                if (ret == NULL)
                {
                    ret = list_a_new();
                }
                ret = list_a_append(ret, data);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}
