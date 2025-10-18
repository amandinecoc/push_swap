# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amandine <amandine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 00:07:50 by amandine          #+#    #+#              #
#    Updated: 2025/10/18 18:54:48 by amandine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT:= libft.a
NAME := push_swap
NAME_BONUS := checker

#Source#####################################
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

SOURCES_PUSH_SWAP += push_swap.c
SOURCES_PUSH_SWAP += parsing/checker_and_print_error.c
SOURCES_PUSH_SWAP += parsing/create_sorted_index_tab.c
SOURCES_PUSH_SWAP += parsing/utils_for_create_tab_index.c
SOURCES_PUSH_SWAP += doubl_list/create_list.c
SOURCES_PUSH_SWAP += doubl_list/list_utils.c
SOURCES_PUSH_SWAP += commands/command_push.c
SOURCES_PUSH_SWAP += commands/command_reverse.c
SOURCES_PUSH_SWAP += commands/command_rotate.c
SOURCES_PUSH_SWAP += commands/command_swap.c
SOURCES_PUSH_SWAP += algo/algo.c
SOURCES_PUSH_SWAP += algo/manag_three_last_elem.c
SOURCES_PUSH_SWAP += algo/sort_five.c

SOURCES_BONUS += checker_bonus/checker.c
SOURCES_BONUS += checker_bonus/execute_command.c
SOURCES_BONUS += checker_bonus/parsing_bonus/checker_and_print_error.c
SOURCES_BONUS += checker_bonus/parsing_bonus/create_sorted_index_tab.c
SOURCES_BONUS += checker_bonus/parsing_bonus/utils_for_create_tab_index.c
SOURCES_BONUS += checker_bonus/get_next_line/get_next_line_utils.c
SOURCES_BONUS += checker_bonus/get_next_line/get_next_line.c
SOURCES_BONUS += checker_bonus/doubl_list_bonus/create_list.c
SOURCES_BONUS += checker_bonus/doubl_list_bonus/list_utils.c
SOURCES_BONUS += checker_bonus/commands_bonus/command_push.c
SOURCES_BONUS += checker_bonus/commands_bonus/command_reverse.c
SOURCES_BONUS += checker_bonus/commands_bonus/command_rotate.c
SOURCES_BONUS += checker_bonus/commands_bonus/command_swap.c

#Objets#####################################

OBJ := ft_atoi.o \
	ft_atoll.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strmapi.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strtrim.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o
	
DIR = obj/

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
	
bonus:
	$(MAKE) all_libft
	$(MAKE) $(NAME_BONUS)
	$(MAKE) all

$(NAME_BONUS):
	$(CC) $(CFLAGS) $(SOURCES_BONUS) $(NAME_LIBFT) -o $(NAME_BONUS)
	
fclean_bonus:
	$(MAKE) fclean
	rm checker
	
re_bonus: fclean_bonus
	$(MAKE) bonus

all_libft: $(NAME_LIBFT)

$(NAME_LIBFT): $(SOURCES_LIBFT)
	mkdir ./obj/
	$(CC) $(CFLAGS) -c $(SOURCES_LIBFT) $(INCLUDES_LIBFT)
	ar rcs $(NAME_LIBFT) $(OBJ)
	mv $(OBJ) $(DIR) 

clean_libft:
	rm -rf obj

fclean_libft: clean_libft
	rm -rf $(NAME_LIBFT)

relibft: fclean_libft
	$(MAKE) all_libft

.PHONY : all re clean fclean fclean_libft clean_libft relibft all_libft