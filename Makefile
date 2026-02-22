# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 15:13:12 by lbolea            #+#    #+#              #
#    Updated: 2026/02/22 18:51:07 by lbolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol

#SOURCES
SRC_DIR		:= src
SRCS		:= main.c \
	controls.c \
	hooks.c \
	color.c \
	parsing.c \
	render.c \
	fractal_set.c
SRCS 		:= $(SRCS:%=$(SRC_DIR)/%)

#INCLUDES
INCS		:= 	include \
	libs/Libft/ \
	libs/printf/include/

#LIBS
LIBS	:= ft ftprintf
LIBS_TARGET :=	\
	libs/Libft/libft.a \
	libs/printf/libftprintf.a
LIB_MLX := mlx_Linux
LIB_MLX_TARGET := libs/minilibx-linux/libmlx_Linux.a

#BUILD
BUILD_DIR 	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#FLAGS
CC 			:= cc
CCFLAGS 	:= -Wall -Wextra -Werror -O3
AR 			:= ar
ARFLAGS		:= rcs
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)) $(dir $(LIB_MLX_TARGET)) /usr/lib)
LDLIBS      := $(addprefix -l,$(LIBS) $(LIB_MLX) Xext X11 m z)

#TOOLS
RM 			:= rm -f
DIR_DUP		= mkdir -p $(@D)
MAX_J 		:= 8

## COLORS
DEF		= \033[0m
GREEN 	= \033[0;32m

##COMMANDES

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET) $(LIB_MLX_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)[OK]$(DEF) CREATED $(NAME)"

$(LIBS_TARGET):
	@$(MAKE) --silent --no-print-directory -C $(@D)

$(LIB_MLX_TARGET):
	@$(MAKE) --silent --no-print-directory -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -O3 -c $< -o $@
	@echo "$(GREEN)[OK]$(DEF) CREATED $@"

-include $(DEPS) -O3

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --silent --no-print-directory -C $$f clean; done
	@$(MAKE) --silent --no-print-directory -C $(dir $(LIB_MLX_TARGET)) clean
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)[OK]$(DEF) CLEANED $(NAME) objs & deps"

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --silent --no-print-directory -C $$f fclean; done
	@$(MAKE) --silent --no-print-directory -C $(dir $(LIB_MLX_TARGET)) clean
	@$(RM) $(NAME)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)[OK]$(DEF) CLEANED $(NAME)"

re:
	@+make --silent --no-print-directory -j$(MAX_J) fclean
	@+make --silent --no-print-directory all
	@echo "$(GREEN)[OK]$(DEF) RECOMPILED $(NAME)"

debug: fclean
	@$(MAKE) --no-print-directory $(OBJS) $(LIBS_TARGET) CCFLAGS="$(CCFLAGS) -g"
	@$(MAKE) --no-print-directory $(OBJS) $(LIB_MLX_TARGET) CCFLAGS="$(CCFLAGS) -g"
	@$(CC) $(CCFLAGS) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o debug
	@echo "$(GREEN)[OK]$(DEF) CREATED debug program"

fdebug : clean
	@rm -rf debug
	@echo "$(GREEN)[OK]$(DEF) CLEANED debug"

.PHONY: all clean fclean re