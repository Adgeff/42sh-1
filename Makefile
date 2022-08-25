# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 10:12:40 by geargenc          #+#    #+#              #
#    Updated: 2022/08/25 21:17:37 by geargenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 42sh

LIBDIRS := libft

LIBARCHIVES := libft/libft.a

SRCDIR := src

SRC := $(shell find $(SRCDIR) -name "*.c" -and -not -name "__*")

BUILDDIR := build

OBJ := $(SRC:%.c=$(BUILDDIR)/%.c.o)

DEP := $(SRC:%.c=$(BUILDDIR)/%.c.d)

INCDIRS := includes libft/includes

INCFLAGS := $(INCDIRS:%=-I%)

CC := clang

CPPFLAGS := $(INCFLAGS) -MMD -MP

CFLAGS := -Wall -Wextra -Werror

LD := clang

LDFLAGS := -lncurses -ltinfo

all : libs $(NAME)

libs : $(LIBDIRS)

.PHONY : $(LIBDIRS) libs clean fclean re all

$(LIBDIRS) :
	$(MAKE) -C $@

$(OBJ) : $(BUILDDIR)/%.c.o : %.c $(BUILDDIR)/%.c.d
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(DEP) :

$(NAME) : $(OBJ) $(LIBARCHIVES)
	$(LD) $(LDFLAGS) $^ -o $@

clean :
	rm -rf $(BUILDDIR)
	for lib in $(LIBDIRS) ; do $(MAKE) -C $$lib clean ; done

fclean :
	rm -rf $(BUILDDIR)
	rm -f $(NAME)
	rm -f $(LNAME)
	rm -f $(HOSTTYPE_LAST_FILE)
	for lib in $(LIBDIRS) ; do $(MAKE) -C $$lib fclean ; done

re : fclean all

-include $(DEP)
