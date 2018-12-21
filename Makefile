# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:28:41 by apion             #+#    #+#              #
#    Updated: 2018/12/21 15:46:26 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:= /bin/sh
RM				:= /bin/rm -f
MAKE			:= make
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror
CINCLUDES		= $(addprefix -I,$(H_DIR))
CPPFLAGS		= -MMD -MP -MF $(D_DIR)/$*.d

LIBFT_PATH		= libft
LIBFT			= $(LIBFT_PATH)/libft.a

NAME			= fillit
C_DIR			=
H_DIR			=
ifdef DEBUG
H_DIR			+= $(LIBFT_PATH)
endif
D_DIR			= .dep
O_DIR			= .obj
C_FILES			:= main.c \
					output.c \
					parser.c \
					solver.c \
					utils.c
ifdef DEBUG
C_FILES			+= dbg_utils.c
endif
O_FILES			:= $(C_FILES:%.c=%.o)
D_FILES			:= $(C_FILES:%.c=%.d)

.SUFFIXES:
.SUFFIXES: .c .o .d

.PHONY: all
all: $(NAME)

.PHONY: $(LIBFT)
$(LIBFT):
	make -C $(LIBFT_PATH)

ifdef DEBUG
$(NAME): $(LIBFT)
endif
$(NAME): $(addprefix $(O_DIR)/, $(O_FILES))
ifdef DEBUG
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^ -L$(LIBFT_PATH) -lft
else
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^
endif

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(D_DIR)/%.d | $(O_DIR) $(D_DIR)
	$(CC) $(CFLAGS) $(CINCLUDES) $(CPPFLAGS) -o $@ -c $<

$(D_DIR)/%.d: ;
.PRECIOUS: $(D_DIR)/%.d

$(O_DIR):
	mkdir -p $@

$(D_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(addprefix $(O_DIR)/, $(O_FILES))
	$(RM) $(addprefix $(D_DIR)/, $(D_FILES))
	rmdir $(O_DIR) 2> /dev/null || true
	rmdir $(D_DIR) 2> /dev/null || true

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(D_DIR)/*.d)
