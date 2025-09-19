/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:54:12 by acocoual          #+#    #+#             */
/*   Updated: 2025/09/19 22:58:45 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct pile
{
    int valeur;
    struct pile *prec;
} pile;

/*  Push empile une valeur sur la pile. */
void Push(pile **, int);
/*  Pop retire la dernière valeur empilée sur la pile. */
 int Pop(pile **);
/*  Clear vide la pile. */
void Clear(pile **);
/*  Length retourne le nombre d'éléments de la pile. */
int Length(pile *p);
/*  Affiche la totalité de la pile en commençant par le sommet. */
void View(pile *);

#endif
