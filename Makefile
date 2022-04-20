NAME = fractol

FILES = \
	fractol render fractals utils input

OFILES = $(FILES:%=%.o)
CFLAGS = -Wall -Wextra
OPTIM = -O3
export OPTIM
INC = -I.
LIBS= -lgf -lft -lmlx -lXext -lX11 -lm
LIBS_FILES = libft/libft.a libgf/libgf.a mlx/libmlx.a
LIBS_DIRS = $(addprefix -L, $(dir $(LIBS_FILES)))

all: $(NAME)

$(NAME): $(OFILES) $(LIBS_FILES)
	gcc $(LIBS_DIRS) $(OFILES) $(LIBS) -o $@

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

clean_libs:
	make clean -C libft
	make clean -C libgf
	make clean -C mlx

re_libs:
	make re -C libft
	make re -C libgf
	make re -C mlx

.PHONY: clean clean_ fclean fclean_ re re_ re_libs clean_libs FORCE
