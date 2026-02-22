# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbolea <lbolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 15:13:12 by lbolea            #+#    #+#              #
#    Updated: 2026/02/22 20:43:38 by lbolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol
NAME_BONUS	:= fractol_bonus


#FILES
FILES		:= main.c \
	controls.c \
	hooks.c \
	color.c \
	parsing.c \
	render.c \
	fractal_set.c	


#PATHS
SRC_DIR		:= src
BONUS_DIR 	:= bonus
BUILD_DIR 	:= .build


#SOURCES
SRCS 		:= $(addprefix $(SRC_DIR)/, $(FILES))
SRCS_BONUS 	:= $(addprefix $(BONUS_DIR)/, $(FILES:.c=_bonus.c))


#BUILD
OBJS 		:= $(addprefix $(BUILD_DIR)/, $(FILES:.c=.o))
OBJS_BONUS 	:= $(addprefix $(BUILD_DIR)/, $(FILES:.c=_bonus.o))
DEPS		:= $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

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

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBS_TARGET) $(LIB_MLX_TARGET)
	@$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)[OK]$(DEF) CREATED $(NAME)"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBS_TARGET) $(LIB_MLX_TARGET)
	@$(CC) $(OBJS_BONUS) $(LDFLAGS) $(LDLIBS) -o $(NAME_BONUS)
	@echo "$(GREEN)[OK]$(DEF) CREATED $(NAME_BONUS)"

$(LIBS_TARGET):
	@$(MAKE) --silent --no-print-directory -C $(@D)

$(LIB_MLX_TARGET):
	@$(MAKE) --silent --no-print-directory -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -Iinclude -c $< -o $@
	@echo "$(GREEN)[OK]$(DEF) CREATED $@"

$(BUILD_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -Iinclude -c $< -o $@
	@echo "$(GREEN)[OK]$(DEF) CREATED $@"

-include $(DEPS) -O3

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --silent --no-print-directory -C $$f clean; done
	@$(MAKE) --silent --no-print-directory -C $(dir $(LIB_MLX_TARGET)) clean
	@$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)[OK]$(DEF) CLEANED $(NAME) objs & deps"

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) --silent --no-print-directory -C $$f fclean; done
	@$(MAKE) --silent --no-print-directory -C $(dir $(LIB_MLX_TARGET)) clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)[OK]$(DEF) $(NAME) FULLY CLEANED "

re:
	@+make --silent --no-print-directory -j$(MAX_J) fclean
	@+make --silent --no-print-directory all
	@echo "$(GREEN)[OK]$(DEF) RECOMPILED $(NAME)"

#debug: fclean
#	@$(MAKE) --no-print-directory $(OBJS) $(LIBS_TARGET) CCFLAGS="$(CCFLAGS) -g"
#	@$(MAKE) --no-print-directory $(OBJS) $(LIB_MLX_TARGET) CCFLAGS="$(CCFLAGS) -g"
#	@$(CC) $(CCFLAGS) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o debug
#	@echo "$(GREEN)[OK]$(DEF) CREATED debug program"

#fdebug : clean
#	@rm -rf debug
#	@echo "$(GREEN)[OK]$(DEF) CLEANED debug"

.PHONY: all clean fclean re bonus