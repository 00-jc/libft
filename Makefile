# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 03:43:49 by jaicastr          #+#    #+#              #
#    Updated: 2026/01/20 06:01:26 by jaicastr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
THRESHOLD	:=  0.40
CC			:=	cc
SCANNER		:=	scan-build
WARNS		:=  -Wall -Wextra -Werror -Wshadow -Wattributes -fstrict-aliasing -Wpedantic -std=c99 \
				-Waddress -Wambiguous-ellipsis -Wambiguous-macro -Wassume -Wpessimizing-move -Wgnu-union-cast \
				-Wgnu-union-cast -Wlanguage-extension-token -Wgnu-statement-expression-from-macro-expansion \
				-Wbounds-safety-counted-by-elt-type-unknown-size -Wstrict-aliasing -Wcast-function-type-strict \
				-Wcast-function-type-mismatch -Wc99-compat -Wbool-conversions -Wbool-operation -Wbitwise-instead-of-logical \
				-Wbitfield-enum-conversion -Warray-bounds-pointer-arithmetic -Wnull-pointer-arithmetic\
				-Wredundant-decls -Wstrict-prototypes -Wnull-dereference -Wundef -Wformat-security -Wformat=2\
				-Wwrite-strings -Wold-style-definition -Wuninitialized -Wloop-analysis -Wpointer-arith\
				-Wcomma -Wover-aligned -Wmissing-prototypes -Wunused -Wtautological-compare -Wunreachable-code -Wvla
CFLAGS 		:=  -ffunction-sections -fdata-sections -fvectorize -finline-functions\
				-fstack-protector-strong -fcf-protection=full -ftrivial-auto-var-init=zero -fno-common -fvisibility=hidden\
				-fstack-clash-protection -O3 -march=native -flto -pipe $(WARNS)
AR			:=	llvm-ar rcs
OBJDIR		:=	build
SRCS		:=	src/ctype/ft_isprint.c\
				src/ctype/ft_isxdigit.c\
				src/ctype/ft_isdigit.c\
				src/ctype/ft_isspace.c\
				src/ctype/ft_isalnum.c\
				src/ctype/ft_isascii.c\
				src/ctype/ft_isalpha.c\
				src/cstr/ft_s_isblob.c\
				src/cstr/ft_substr.c\
				src/cstr/ft_toupper.c\
				src/cstr/ft_strncmp.c\
				src/cstr/ft_strrchr.c\
				src/cstr/ft_strtrim.c\
				src/cstr/ft_strchr.c\
				src/cstr/ft_striteri.c\
				src/cstr/ft_split.c\
				src/cstr/ft_strlen.c\
				src/cstr/ft_strlcat.c\
				src/cstr/ft_strcmp.c\
				src/cstr/ft_strdup.c\
				src/cstr/ft_strmapi.c\
				src/cstr/ft_strnstr.c\
				src/cstr/ft_strlcpy.c\
				src/cstr/ft_isnumeric.c\
				src/cstr/ft_tolower.c\
				src/cstr/ft_strjoin.c\
				src/alloc/ft_realloc.c\
				src/alloc/ft_alloc.c\
				src/alloc/ft_recalloc.c\
				src/alloc/ft_calloc.c\
				src/alloc/ft_free.c\
				src/alloc/ft_extend_zero.c\
				src/alloc/ft_extend.c\
				src/math/ft_pow_signed.c\
				src/math/ft_fabs.c\
				src/math/ft_pow.c\
				src/math/ft_q_sqrt.c\
				src/math/ft_sqrt.c\
				src/math/ft_round.c\
				src/conv/ft_itoa_base.c\
				src/conv/ft_utoa_base.c\
				src/conv/ft_atod.c\
				src/conv/ft_atol.c\
				src/conv/ft_atof.c\
				src/conv/ft_atoi.c\
				src/conv/ft_atoul.c\
				src/conv/ft_itoa.c\
				src/conv/ft_atoi_base.c\
				src/mem/ft_bzero.c\
				src/mem/ft_murmur3.c\
				src/mem/ft_murmur_helpers.c\
				src/mem/ft_memclone.c\
				src/mem/ft_memformat.c\
				src/mem/ft_memtake.c\
				src/mem/ft_memset_portable.c\
				src/mem/__max.c\
				src/mem/__maxs.c\
				src/mem/ft_memctz.c\
				src/mem/ft_memctz_asm.c\
				src/mem/ft_memcpy_portable.c\
				src/mem/ft_memcpy_avx256.c\
				src/mem/ft_memcpy.c\
				src/mem/ft_get512.c\
				src/x86/ft_memcpy.S\
				src/x86/ft_memset.S\
				src/x86/ft_strlen.S\
				src/x86/ft_memchr.S\
				src/mem/ft_membroadcast.c\
				src/mem/ft_get256.c\
				src/mem/ft_get128.c\
				src/mem/ft_memset.c\
				src/mem/ft_memmove.c\
				src/mem/__populate.c\
				src/mem/__hasz.c\
				src/mem/ft_memchr.c\
				src/mem/ft_memcmp.c\
				src/vec/ft_vec_get.c\
				src/vec/ft_vec_extend.c\
				src/vec/ft_vec_push_back.c\
				src/vec/ft_vec_remove.c\
				src/vec/ft_vec_bytesize.c\
				src/vec/ft_vec_free.c\
				src/vec/ft_vec_pop.c\
				src/vec/ft_vec_new.c\
				src/io/ft_putchar_fd.c\
				src/io/ft_putendl_fd.c\
				src/io/ft_putnbr_fd.c\
				src/io/ft_putstr_fd.c\
				src/io/ft_printf.c\
				src/io/ft_printf_helpers.c\
				src/io/ft_printf_helpers2.c\
				src/io/ft_read_file.c\
				src/str/ft_str_extend.c\
				src/str/ft_str_new.c\
				src/str/ft_str_remove.c\
				src/str/ft_str_push_back.c

OBJS		:=	build/ctype/ft_isprint.o\
				build/ctype/ft_isxdigit.o\
				build/ctype/ft_isdigit.o\
				build/ctype/ft_isspace.o\
				build/ctype/ft_isalnum.o\
				build/ctype/ft_isascii.o\
				build/ctype/ft_isalpha.o\
				build/cstr/ft_s_isblob.o\
				build/cstr/ft_substr.o\
				build/cstr/ft_toupper.o\
				build/cstr/ft_strncmp.o\
				build/cstr/ft_strrchr.o\
				build/cstr/ft_strtrim.o\
				build/cstr/ft_strchr.o\
				build/cstr/ft_striteri.o\
				build/cstr/ft_split.o\
				build/cstr/ft_strlen.o\
				build/cstr/ft_strlcat.o\
				build/cstr/ft_strcmp.o\
				build/cstr/ft_strdup.o\
				build/cstr/ft_strmapi.o\
				build/cstr/ft_strnstr.o\
				build/cstr/ft_strlcpy.o\
				build/cstr/ft_isnumeric.o\
				build/cstr/ft_tolower.o\
				build/cstr/ft_strjoin.o\
				build/alloc/ft_realloc.o\
				build/alloc/ft_alloc.o\
				build/alloc/ft_recalloc.o\
				build/alloc/ft_calloc.o\
				build/alloc/ft_free.o\
				build/alloc/ft_extend_zero.o\
				build/alloc/ft_extend.o\
				build/math/ft_pow_signed.o\
				build/math/ft_fabs.o\
				build/math/ft_pow.o\
				build/math/ft_q_sqrt.o\
				build/math/ft_sqrt.o\
				build/math/ft_round.o\
				build/conv/ft_itoa_base.o\
				build/conv/ft_utoa_base.o\
				build/conv/ft_atod.o\
				build/conv/ft_atol.o\
				build/conv/ft_atof.o\
				build/conv/ft_atoi.o\
				build/conv/ft_atoul.o\
				build/conv/ft_itoa.o\
				build/conv/ft_atoi_base.o\
				build/mem/ft_bzero.o\
				build/mem/ft_murmur3.o\
				build/mem/ft_murmur_helpers.o\
				build/mem/ft_memclone.o\
				build/mem/ft_memformat.o\
				build/mem/ft_memtake.o\
				build/mem/ft_memset_portable.o\
				build/mem/__max.o\
				build/mem/__maxs.o\
				build/mem/ft_memctz.o\
				build/mem/ft_memctz_asm.o\
				build/mem/ft_memcpy_portable.o\
				build/mem/ft_memcpy_avx256.o\
				build/x86/ft_memcpy.o\
				build/x86/ft_memset.o\
				build/x86/ft_strlen.o\
				build/x86/ft_memchr.o\
				build/mem/ft_memcpy.o\
				build/mem/ft_get512.o\
				build/mem/ft_membroadcast.o\
				build/mem/ft_get256.o\
				build/mem/ft_get128.o\
				build/mem/ft_memset.o\
				build/mem/ft_memmove.o\
				build/mem/__populate.o\
				build/mem/__hasz.o\
				build/mem/ft_memchr.o\
				build/mem/ft_memcmp.o\
				build/vec/ft_vec_get.o\
				build/vec/ft_vec_extend.o\
				build/vec/ft_vec_push_back.o\
				build/vec/ft_vec_remove.o\
				build/vec/ft_vec_bytesize.o\
				build/vec/ft_vec_free.o\
				build/vec/ft_vec_pop.o\
				build/vec/ft_vec_new.o\
				build/io/ft_putchar_fd.o\
				build/io/ft_putendl_fd.o\
				build/io/ft_putnbr_fd.o\
				build/io/ft_putstr_fd.o\
				build/io/ft_printf.o\
				build/io/ft_printf_helpers.o\
				build/io/ft_printf_helpers2.o\
				build/io/ft_read_file.o\
				build/str/ft_str_extend.o\
				build/str/ft_str_new.o\
				build/str/ft_str_remove.o\
				build/str/ft_str_push_back.o
TOTAL 		:= $(words $(OBJS))
CURRENT 	:= 0

all: $(NAME)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@printf "[$(CURRENT)/$(TOTAL)] "
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ -Iinclude

$(OBJDIR)/%.o: src/%.S
	@mkdir -p $(dir $@)
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@printf "[$(CURRENT)/$(TOTAL)] "
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean full all

static_analysis:
	$(SCANNER) $(CC) $(WARNS) -Xclang -analyzer-output=text --analyze $(filter %.c,$(SRCS)) -Iinclude

analyze: all static_analysis
	@if command -v ast2md >/dev/null 2>&1; then \
		AST2MD_THREADS=$$(nproc) ast2md -L c -i $$(find . -name "*.c") -o stats -t $(THRESHOLD) -- -I include; \
	else \
		echo "ast2md not found, skipping coupling analysis"; \
	fi
	@echo "Running tests..."
	@$(CC) $(CFLAGS) tests/strlen_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_strlen && \
		./test_strlen && rm -f test_strlen
	@$(CC) $(CFLAGS) tests/memchr_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_memchr && \
		./test_memchr && rm -f test_memchr
	@$(CC) $(CFLAGS) tests/memcmp_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_memcmp && \
		./test_memcmp && rm -f test_memcmp
	@$(CC) $(CFLAGS) tests/memmove_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_memmove && \
		./test_memmove && rm -f test_memmove
	@$(CC) $(CFLAGS) tests/membroadcast_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_membroadcast && \
		./test_membroadcast && rm -f test_membroadcast
	@$(CC) $(CFLAGS) tests/memclone_test.c -g $(NAME) -Iinclude -fsanitize=address,alignment,undefined -fsanitize-recover=null -o test_memclone && \
		./test_memclone && rm -f test_memclone
	@echo "All tests passed!"

bonus: all

.PHONY: all clean fclean re bonus full static_analysis analyze native
