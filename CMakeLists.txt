cmake_minimum_required(VERSION 3.22)
project(Push_swap3 C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)

add_compile_definitions(NDEBUG)
add_compile_options(-Wall -Wextra -Werror)

add_executable(push_swap
        includes/push_swap.h
        libft/includes/ft_printf.h
        libft/includes/libft.h
        libft/src/ft_is/ft_isalnum.c
        libft/src/ft_is/ft_isalpha.c
        libft/src/ft_is/ft_isascii.c
        libft/src/ft_is/ft_isdigit.c
        libft/src/ft_is/ft_isprint.c
        libft/src/ft_lst/ft_lstadd_back.c
        libft/src/ft_lst/ft_lstadd_front.c
        libft/src/ft_lst/ft_lstclear.c
        libft/src/ft_lst/ft_lstdelone.c
        libft/src/ft_lst/ft_lstiter.c
        libft/src/ft_lst/ft_lstlast.c
        libft/src/ft_lst/ft_lstnew.c
        libft/src/ft_lst/ft_lstsize.c
        libft/src/ft_mem/ft_bzero.c
        libft/src/ft_mem/ft_calloc.c
        libft/src/ft_mem/ft_memchr.c
        libft/src/ft_mem/ft_memcmp.c
        libft/src/ft_mem/ft_memcpy.c
        libft/src/ft_mem/ft_memmove.c
        libft/src/ft_mem/ft_memset.c
        libft/src/ft_printf/countargs.c
        libft/src/ft_printf/decimal.c
        libft/src/ft_printf/dispatch.c
        libft/src/ft_printf/ft_printf.c
        libft/src/ft_printf/hexa.c
        libft/src/ft_printf/hexastr.c
        libft/src/ft_printf/putstrarg.c
        libft/src/ft_printf/udecimal.c
        libft/src/ft_printf/uitoa.c
        libft/src/ft_put/ft_putchar.c
        libft/src/ft_put/ft_putchar_fd.c
        libft/src/ft_put/ft_putendl.c
        libft/src/ft_put/ft_putendl_fd.c
        libft/src/ft_put/ft_putnbr.c
        libft/src/ft_put/ft_putnbr_fd.c
        libft/src/ft_put/ft_putstr.c
        libft/src/ft_put/ft_putstr_fd.c
        libft/src/ft_str/ft_split.c
        libft/src/ft_str/ft_strchr.c
        libft/src/ft_str/ft_strdup.c
        libft/src/ft_str/ft_striteri.c
        libft/src/ft_str/ft_strjoin.c
        libft/src/ft_str/ft_strlcat.c
        libft/src/ft_str/ft_strlcpy.c
        libft/src/ft_str/ft_strlen.c
        libft/src/ft_str/ft_strmapi.c
        libft/src/ft_str/ft_strncmp.c
        libft/src/ft_str/ft_strnstr.c
        libft/src/ft_str/ft_strrchr.c
        libft/src/ft_str/ft_strtrim.c
        libft/src/ft_str/ft_substr.c
        libft/src/ft_to/ft_atoi.c
        libft/src/ft_to/ft_itoa.c
        libft/src/ft_to/ft_tolower.c
        libft/src/ft_to/ft_toupper.c
        src/push_swap/push_swap.c
        src/shared/check_args.c
        src/shared/stack_management.c
        src/shared/median.c
        src/shared/push_b.c
        src/shared/fill_stack.c
        src/shared/push_a.c
        src/algo/five.c
        src/algo/hundred.c)

