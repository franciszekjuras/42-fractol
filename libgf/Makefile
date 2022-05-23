NAME = libgf.a

FILES = \
	gf_basics gf_camera gf_color gf_img gf_line gf_lineclip\
	gf_point gf_grad gf_vector gf_vector2 gf_vector3 \
	gf_strtodouble \
	cplx cplx2 cplx3 \
	gf_int_pxput gf_int_utils

OFILES = $(FILES:%=%.o)

CFLAGS = -Wall -Wextra -Werror

OPTIM = -O3

INC = -I. -I..

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $?

$(OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) $(INC) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
