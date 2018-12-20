# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 10:18:24 by apion             #+#    #+#              #
#    Updated: 2018/12/20 12:44:04 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		:= libft/
LIBFT			:= $(LIBFT_PATH)/libft.a

CINCLUDES		= $(addprefix -I, $(HEADER_PATH))
CLIB			:= -L$(LIBFT_PATH) -lft

HEADER_PATH		:= $(LIBFT_PATH)
C_FILES			:= parser.c main.c dbg_utils.c

.PHONY: $(LIBFT)
$(LIBFT):
	make -C $(LIBFT_PATH)

test: $(C_FILES) $(LIBFT)
	gcc $(CINCLUDES) $^ $(CLIB)

parser: $(LIBFT)
	gcc $(CINCLUDES) $(C_FILES) $(CLIB)
