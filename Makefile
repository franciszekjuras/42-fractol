NAME = fractol

FILES = \
	fractol render fractals utils utils2 input

OFILES = $(FILES:%=%.o)
CFLAGS = -Wall -Wextra -Werror
OPTIM = -O3
export OPTIM
INC = -I. -I/usr/X11/include
LIBS= -lgf -lft -lmlx -lXext -lX11 -lm
X11_LDIR = -L/usr/X11/lib
LIBS_FILES = libft/libft.a libgf/libgf.a mlx/libmlx.a
LIBS_DIRS = $(addprefix -L, $(dir $(LIBS_FILES)))

all: $(NAME)

$(NAME): $(OFILES) $(LIBS_FILES)
	gcc $(LIBS_DIRS) $(X11_LDIR) $(OFILES) $(LIBS) -o $@

$(OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) $(INC) -c $< -o $@

$(LIBS_FILES): FORCE
	make -C $(dir $@)

FORCE: ;

clean_:
	rm -f $(OFILES)

clean: clean_libs clean_

fclean_: clean_
	rm -f $(NAME)

fclean: fclean_ clean
	rm -f $(LIBS_FILES)

re_: fclean_ all

re: re_libs re_

mlx_clean_gen:
	rm -f mlx/makefile.gen
	rm -f mlx/test/makefile.gen

clean_libs:
	make clean -C libft
	make clean -C libgf
	make clean -C mlx

re_libs:
	make re -C libft
	make re -C libgf
	make re -C mlx

.PHONY: clean clean_ fclean fclean_ re re_ re_libs clean_libs mlx_clean_gen FORCE
