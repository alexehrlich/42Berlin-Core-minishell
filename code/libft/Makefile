# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 11:21:05 by lbaumann          #+#    #+#              #
#    Updated: 2023/07/06 17:57:36 by lbaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

ifeq ($(DEBUG), 1)
CFLAGS = -g
endif

SRCDIR = srcs/
INCDIR = includes/
OBJDIR = objs/

#CFLAGS += -I $(HEADERS)

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
PU	= \033[35;1m
BL	= \033[34;1m
RC	= \033[0m

SRC = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line.c \
get_next_line_utils.c ft_printf.c ft_printf_utils.c ft_free_set_null.c \
ft_free_split_arr.c ft_strcmp.c ft_lst_insert_before.c ft_lstremove.c \
ft_lstfindprev.c ft_strjoin_free.c ft_dict_add_node.c ft_dict_get_node.c \
ft_dict_get_value.c ft_dict_modify_value.c ft_dict_node_del.c \
ft_dict_rm_node.c ft_dict_print.c ft_dict_from_strarr.c \
ft_dict_to_strarr.c ft_is_str_nbr.c ft_argc_from_argv.c ft_fd_printf.c

SRCS := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@printf "\n$(RE)=== Compiled [$(CC) $(CFLAGS)] ===$(RC)\n$(BL)---$(SRC)$(RC)\n"
	@printf "$(PU)+++ libft.a created [ar -cr] $(RC)\n"
	@ar -cr $(NAME) $(OBJS)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GR)o$(RC)"

clean:
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
