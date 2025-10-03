# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amandine <amandine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 00:07:50 by amandine          #+#    #+#              #
#    Updated: 2025/10/03 03:03:35 by amandine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT:= libft.a
NAME := push_swap

#Source#####################################
#PATH_SRCS = Libft/

SOURCES_LIBFT += libft/ft_atoi.c
SOURCES_LIBFT += libft/ft_bzero.c
SOURCES_LIBFT += libft/ft_calloc.c
SOURCES_LIBFT += libft/ft_isalnum.c
SOURCES_LIBFT += libft/ft_isalpha.c
SOURCES_LIBFT += libft/ft_isascii.c
SOURCES_LIBFT += libft/ft_isdigit.c
SOURCES_LIBFT += libft/ft_isprint.c
SOURCES_LIBFT += libft/ft_memchr.c
SOURCES_LIBFT += libft/ft_memcmp.c
SOURCES_LIBFT += libft/ft_memcpy.c
SOURCES_LIBFT += libft/ft_memmove.c
SOURCES_LIBFT += libft/ft_memset.c
SOURCES_LIBFT += libft/ft_strchr.c
SOURCES_LIBFT += libft/ft_strdup.c
SOURCES_LIBFT += libft/ft_strlcat.c
SOURCES_LIBFT += libft/ft_strlcpy.c
SOURCES_LIBFT += libft/ft_strlen.c
SOURCES_LIBFT += libft/ft_strncmp.c
SOURCES_LIBFT += libft/ft_strnstr.c
SOURCES_LIBFT += libft/ft_tolower.c
SOURCES_LIBFT += libft/ft_toupper.c
SOURCES_LIBFT += libft/ft_strrchr.c
SOURCES_LIBFT += libft/ft_itoa.c
SOURCES_LIBFT += libft/ft_putchar_fd.c
SOURCES_LIBFT += libft/ft_putendl_fd.c
SOURCES_LIBFT += libft/ft_putnbr_fd.c
SOURCES_LIBFT += libft/ft_putstr_fd.c
SOURCES_LIBFT += libft/ft_split.c
SOURCES_LIBFT += libft/ft_striteri.c
SOURCES_LIBFT += libft/ft_strjoin.c
SOURCES_LIBFT += libft/ft_strmapi.c
SOURCES_LIBFT += libft/ft_strtrim.c
SOURCES_LIBFT += libft/ft_substr.c
SOURCES_LIBFT += libft/ft_atoll.c

SOURCES_PUSH_SWAP += *.c
SOURCES_PUSH_SWAP += parsing/*.c
SOURCES_PUSH_SWAP += doubl_list/*.c

#Objets#####################################
#PATH = obj/
#OBJ = $(SOURCES: .c= .o)

OBJ = *.o

#Includes###################################
INCLUDES_LIBFT =
# Libft/libft.h
INCLUDES =
# push_swap.h

#Compilation################################
CC = cc

CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g3
#Rules######################################

all:
	$(MAKE) all_libft
	$(MAKE) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES_PUSH_SWAP) $(INCLUDES) $(INCLUDES_LIBFT) $(NAME_LIBFT) -o $(NAME)

clean: fclean_libft

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE) all
	

all_libft: $(NAME_LIBFT)
 
#$(OBJ):
#	mkdir $(PATH)
#	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDES) -o $(PATH)

$(NAME_LIBFT): $(SOURCES_LIBFT)
	mkdir ./obj/
	$(CC) $(CFLAGS) -c $(SOURCES_LIBFT) $(INCLUDES_LIBFT)
	mv *.o obj/
	ar rcs $(NAME_LIBFT) ./obj/$(OBJ)

clean_libft:
	rm -rf obj

fclean_libft: clean_libft
	rm -rf $(NAME_LIBFT)

relibft: fclean_libft
	$(MAKE) all_libft

.PHONY : all re clean fclean fclean_libft clean_libft relibft all_libft