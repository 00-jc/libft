# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 03:43:49 by jaicastr          #+#    #+#              #
#    Updated: 2026/03/04 02:57:14 by jaicastr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		:=	libft.a
THRESHOLD	:=  0.40
SCANNER		:=	scan-build
AR			:=	ar rcs
OBJDIR		:=	build
CC_CLANG	:=	clang
CC_GCC		:=	gcc
WARNS_CLANG	:=  -Wall -Wextra -Werror -Wshadow -Wattributes -fstrict-aliasing -Wpedantic -std=c99 \
				-Waddress -Wambiguous-ellipsis -Wambiguous-macro -Wassume -Wpessimizing-move -Wgnu-union-cast \
				-Wgnu-union-cast -Wlanguage-extension-token -Wgnu-statement-expression-from-macro-expansion \
				-Wbounds-safety-counted-by-elt-type-unknown-size -Wstrict-aliasing -Wcast-function-type-strict \
				-Wcast-function-type-mismatch -Wc99-compat -Wbool-conversions -Wbool-operation -Wbitwise-instead-of-logical \
				-Wbitfield-enum-conversion -Warray-bounds-pointer-arithmetic -Wnull-pointer-arithmetic\
				-Wredundant-decls -Wstrict-prototypes -Wnull-dereference -Wundef -Wformat-security -Wformat=2\
				-Wwrite-strings -Wold-style-definition -Wuninitialized -Wloop-analysis -Wpointer-arith\
				-Wcomma -Wover-aligned -Wmissing-prototypes -Wunused -Wtautological-compare -Wunreachable-code -Wvla
WARNS_GCC	:=  -Wall -Wextra -Werror -Wshadow -Wattributes -fstrict-aliasing -Wpedantic -std=c99 \
				-Waddress -Wstrict-aliasing -Wcast-function-type -Wlogical-op \
				-Wredundant-decls -Wstrict-prototypes -Wnull-dereference -Wundef -Wformat-security -Wformat=2 \
				-Wwrite-strings -Wold-style-definition -Wuninitialized -Wpointer-arith \
				-Wmissing-prototypes -Wunused -Wtautological-compare -Wduplicated-cond -Wvla
MARCH		:=	-march=native
CFLAGS_BASE_CLANG := -flto -O3 -pipe -ffunction-sections -fdata-sections -fvectorize -finline-functions \
				-fvisibility=hidden -fstack-protector-strong -fcf-protection=full -ftrivial-auto-var-init=zero \
				-fno-common -fstack-clash-protection
CFLAGS_BASE_GCC   := -flto -O3 -pipe -ffunction-sections -fdata-sections -ftree-vectorize -finline-functions \
				-fvisibility=hidden -fstack-protector-strong -fcf-protection=full -ftrivial-auto-var-init=zero \
				-fno-common -fstack-clash-protection
CFLAGS_BASE_NOOPT := -pipe -ffunction-sections -fdata-sections -fvectorize -finline-functions \
				-fvisibility=hidden -fstack-protector-strong -fcf-protection=full -ftrivial-auto-var-init=zero \
				-fno-common -fstack-clash-protection
CC			:=	$(CC_CLANG)
CFLAGS		:=	$(MARCH) $(CFLAGS_BASE_CLANG) $(WARNS_CLANG)
SRCS		:=	src/alloc/arena/ft_arena_alloc_utils.c \
				src/alloc/arena/ft_arena_alloc_scopes.c \
				src/alloc/arena/ft_arena_alloc.c \
				src/alloc/ft_alloc.c \
				src/alloc/ft_calloc.c \
				src/alloc/ft_extend.c \
				src/alloc/ft_extend_zero.c \
				src/alloc/ft_realloc.c \
				src/alloc/ft_recalloc.c \
				src/alloc/ft_mmap.c \
				src/alloc/ft_free.c \
				src/conv/ft_itoa_base.c \
				src/conv/ft_atoul.c \
				src/conv/ft_atod.c \
				src/conv/ft_atof.c \
				src/conv/ft_atoi.c \
				src/conv/ft_atol.c \
				src/conv/ft_itoa.c \
				src/conv/ft_utoa_base.c \
				src/conv/ft_atoi_base.c \
				src/cstr/ft_strchr.c \
				src/cstr/ft_s_isblob.c \
				src/cstr/ft_isnumeric.c \
				src/cstr/ft_toupper.c \
				src/cstr/ft_strcmp.c \
				src/cstr/ft_strmapi.c \
				src/cstr/ft_striteri.c \
				src/cstr/ft_strlcat.c \
				src/cstr/ft_tolower.c \
				src/cstr/ft_strtrim.c \
				src/cstr/ft_split.c \
				src/cstr/ft_strnstr.c \
				src/cstr/ft_strlcpy.c \
				src/cstr/ft_strlen.c \
				src/cstr/ft_substr.c \
				src/cstr/ft_strncmp.c \
				src/cstr/ft_strrchr.c \
				src/cstr/ft_strdup.c \
				src/cstr/ft_strjoin.c \
				src/ctype/asm/ft_isalnum.c \
				src/ctype/asm/ft_isalpha.c \
				src/ctype/asm/ft_isascii.c \
				src/ctype/asm/ft_isdigit.c \
				src/ctype/asm/ft_isprint.c \
				src/ctype/asm/ft_isxdigit.c \
				src/ctype/asm/ft_isspace.c \
				src/ctype/ft_isascii.c \
				src/ctype/ft_isalnum.c \
				src/ctype/ft_isprint.c \
				src/ctype/ft_isxdigit.c \
				src/ctype/ft_isspace.c \
				src/ctype/ft_isalpha.c \
				src/ctype/ft_isdigit.c \
				src/io/ft_printf_helpers2.c \
				src/io/ft_read_file_portable.c \
				src/io/ft_read_file.c \
				src/io/ft_printf_helpers.c \
				src/io/ft_lockf.c \
				src/io/ft_printf.c \
				src/math/ft_pow.c \
				src/math/ft_round.c \
				src/math/ft_fabs.c \
				src/math/ft_sqrt.c \
				src/math/ft_pow_signed.c \
				src/math/ft_q_sqrt.c \
				src/math/ft_rsqrt.c \
				src/math/ft_drsqrt_xn.c \
				src/math/ft_sqrt_xn.c \
				src/mem/ft_membroadcast.c \
				src/mem/ft_memtake.c \
				src/mem/ft_memclone.c \
				src/mem/dynamic/ft_memcpy_portable.c \
				src/mem/dynamic/ft_memset_portable.c \
				src/mem/dynamic/ft_memcpy_dispatch.c \
				src/mem/dynamic/ft_memset_dispatch.c \
				src/mem/dynamic/ft_memcpy.c \
				src/mem/dynamic/ft_memset.c \
				src/mem/dynamic/ft_memchr.c \
				src/mem/dynamic/ft_memcmp.c \
				src/mem/hash/ft_murmur3.c \
				src/mem/hash/ft_murmur_helpers.c \
				src/mem/ft_memformat.c \
				src/mem/ft_bzero.c \
				src/mem/sse/ft_memcmp.c \
				src/mem/sse/ft_memchr.c \
				src/mem/ft_prefetch_noop.c \
				src/mem/avx512/ft_memcmp_avx512.c \
				src/mem/avx512/ft_memchr_avx512.c \
				src/mem/ft_memmove.c \
				src/mem/avx256/ft_memcmp_avx256.c \
				src/mem/avx256/ft_memchr_avx256.c \
				src/mem/ft_prefetch_intrin.c \
				src/vec/ft_vec_remove.c \
				src/vec/ft_vec_pop.c \
				src/vec/ft_vec_new.c \
				src/vec/ft_vec_free.c \
				src/vec/ft_vec_push_back.c \
				src/vec/ft_vec_get.c \
				src/vec/ft_vec_bytesize.c \
				src/vec/ft_vec_extend.c \
				src/str/ft_str_remove.c \
				src/str/ft_str_push_back.c \
				src/str/ft_str_extend.c \
				src/str/ft_str_new.c \
				src/bmi/__populate.c \
				src/bmi/ft_bswap.c \
				src/bmi/asm/ft_bswap_asm.c \
				src/bmi/asm/ft_memctz_asm.c \
				src/bmi/asm/ft_memclz_asm.c \
				src/bmi/asm/ft_get128.c \
				src/bmi/asm/ft_get256.c \
				src/bmi/asm/ft_get512.c \
				src/bmi/asm/ft_bitpack.c \
				src/bmi/asm/ft_bitpack_intrin.c \
				src/bmi/ft_to_be_from_be.c \
				src/bmi/ft_to_be_from_le.c \
				src/bmi/ft_memctz.c \
				src/bmi/ft_memclz.c \
				src/bmi/__maxs.c \
				src/bmi/__max.c \
				src/bmi/__hasz.c \
				src/env/ft_getenv.c \
				src/swissmap/ft_map_insert.c \
				src/swissmap/ft_map_lookup.c \
				src/swissmap/ft_map_delete.c \
				src/swissmap/ft_map_rehash.c \
				src/swissmap/ft_map_insert_unchecked.c \
				src/swissmap/ft_map.c \
				src/hint/ft_pin_invariant.c \
				src/hint/ft_hardcrash.c \
				src/tokenizer/ft_eat_u128.c \
				src/tokenizer/ft_eat_u256.c \
				src/tokenizer/ft_eat_u512.c \
				src/tokenizer/ft_eat_until.c \
				src/tokenizer/ft_eat_u8.c \
				src/tokenizer/ft_sets.c \
				src/tokenizer/ft_tokenizer.c \
				src/tokenizer/ft_eat_while.c

OBJS		:=	build/alloc/arena/ft_arena_alloc_utils.o \
				build/alloc/arena/ft_arena_alloc_scopes.o \
				build/alloc/arena/ft_arena_alloc.o \
				build/alloc/ft_alloc.o \
				build/alloc/ft_calloc.o \
				build/alloc/ft_extend.o \
				build/alloc/ft_extend_zero.o \
				build/alloc/ft_realloc.o \
				build/alloc/ft_recalloc.o \
				build/alloc/ft_mmap.o \
				build/alloc/ft_free.o \
				build/conv/ft_itoa_base.o \
				build/conv/ft_atoul.o \
				build/conv/ft_atod.o \
				build/conv/ft_atof.o \
				build/conv/ft_atoi.o \
				build/conv/ft_atol.o \
				build/conv/ft_itoa.o \
				build/conv/ft_utoa_base.o \
				build/conv/ft_atoi_base.o \
				build/cstr/ft_strchr.o \
				build/cstr/ft_s_isblob.o \
				build/cstr/ft_isnumeric.o \
				build/cstr/ft_toupper.o \
				build/cstr/ft_strcmp.o \
				build/cstr/ft_strmapi.o \
				build/cstr/ft_striteri.o \
				build/cstr/ft_strlcat.o \
				build/cstr/ft_tolower.o \
				build/cstr/ft_strtrim.o \
				build/cstr/ft_split.o \
				build/cstr/ft_strnstr.o \
				build/cstr/ft_strlcpy.o \
				build/cstr/ft_strlen.o \
				build/cstr/ft_substr.o \
				build/cstr/ft_strncmp.o \
				build/cstr/ft_strrchr.o \
				build/cstr/ft_strdup.o \
				build/cstr/ft_strjoin.o \
				build/ctype/asm/ft_isalnum.o \
				build/ctype/asm/ft_isalpha.o \
				build/ctype/asm/ft_isascii.o \
				build/ctype/asm/ft_isdigit.o \
				build/ctype/asm/ft_isprint.o \
				build/ctype/asm/ft_isxdigit.o \
				build/ctype/asm/ft_isspace.o \
				build/ctype/ft_isascii.o \
				build/ctype/ft_isalnum.o \
				build/ctype/ft_isprint.o \
				build/ctype/ft_isxdigit.o \
				build/ctype/ft_isspace.o \
				build/ctype/ft_isalpha.o \
				build/ctype/ft_isdigit.o \
				build/io/ft_printf_helpers2.o \
				build/io/ft_read_file_portable.o \
				build/io/ft_read_file.o \
				build/io/ft_printf_helpers.o \
				build/io/ft_lockf.o \
				build/io/ft_printf.o \
				build/math/ft_pow.o \
				build/math/ft_round.o \
				build/math/ft_fabs.o \
				build/math/ft_sqrt.o \
				build/math/ft_pow_signed.o \
				build/math/ft_q_sqrt.o \
				build/math/ft_rsqrt.o \
				build/math/ft_drsqrt_xn.o \
				build/math/ft_sqrt_xn.o \
				build/mem/ft_membroadcast.o \
				build/mem/ft_memtake.o \
				build/mem/ft_memclone.o \
				build/mem/dynamic/ft_memcpy_portable.o \
				build/mem/dynamic/ft_memset_portable.o \
				build/mem/dynamic/ft_memcpy_dispatch.o \
				build/mem/dynamic/ft_memset_dispatch.o \
				build/mem/dynamic/ft_memcpy.o \
				build/mem/dynamic/ft_memchr.o \
				build/mem/dynamic/ft_memset.o \
				build/mem/dynamic/ft_memcmp.o \
				build/mem/hash/ft_murmur3.o \
				build/mem/hash/ft_murmur_helpers.o \
				build/mem/ft_memformat.o \
				build/mem/ft_bzero.o \
				build/mem/sse/ft_memcmp.o \
				build/mem/sse/ft_memchr.o \
				build/mem/ft_prefetch_noop.o \
				build/mem/avx512/ft_memcmp_avx512.o \
				build/mem/avx512/ft_memchr_avx512.o \
				build/mem/ft_memmove.o \
				build/mem/avx256/ft_memcmp_avx256.o \
				build/mem/avx256/ft_memchr_avx256.o \
				build/mem/ft_prefetch_intrin.o \
				build/vec/ft_vec_remove.o \
				build/vec/ft_vec_pop.o \
				build/vec/ft_vec_new.o \
				build/vec/ft_vec_free.o \
				build/vec/ft_vec_push_back.o \
				build/vec/ft_vec_get.o \
				build/vec/ft_vec_bytesize.o \
				build/vec/ft_vec_extend.o \
				build/str/ft_str_remove.o \
				build/str/ft_str_push_back.o \
				build/str/ft_str_extend.o \
				build/str/ft_str_new.o \
				build/bmi/__populate.o \
				build/bmi/ft_bswap.o \
				build/bmi/asm/ft_bswap_asm.o \
				build/bmi/asm/ft_memctz_asm.o \
				build/bmi/asm/ft_memclz_asm.o \
				build/bmi/asm/ft_get128.o \
				build/bmi/asm/ft_get256.o \
				build/bmi/asm/ft_get512.o \
				build/bmi/asm/ft_bitpack.o \
				build/bmi/asm/ft_bitpack_intrin.o \
				build/bmi/ft_to_be_from_be.o \
				build/bmi/ft_to_be_from_le.o \
				build/bmi/ft_memctz.o \
				build/bmi/ft_memclz.o \
				build/bmi/__maxs.o \
				build/bmi/__max.o \
				build/bmi/__hasz.o \
				build/env/ft_getenv.o \
				build/swissmap/ft_map_insert.o \
				build/swissmap/ft_map_lookup.o \
				build/swissmap/ft_map_delete.o \
				build/swissmap/ft_map_rehash.o \
				build/swissmap/ft_map_insert_unchecked.o \
				build/swissmap/ft_map.o \
				build/hint/ft_pin_invariant.o \
				build/hint/ft_hardcrash.o \
				build/tokenizer/ft_eat_u128.o \
				build/tokenizer/ft_eat_u256.o \
				build/tokenizer/ft_eat_u512.o \
				build/tokenizer/ft_eat_until.o \
				build/tokenizer/ft_eat_u8.o \
				build/tokenizer/ft_sets.o \
				build/tokenizer/ft_tokenizer.o \
				build/tokenizer/ft_eat_while.o
SANITIZE	:= 	-fsanitize=address,alignment,undefined -fsanitize-recover=null
TEST_SRCS	:=	memchr strlen memcmp memcpy memset vec str map murmur bmi
all: $(NAME)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ -Iinclude

$(NAME): $(OBJS)
	@$(AR) $@ $^

base:
	@$(MAKE) fclean all CFLAGS="$(CFLAGS_BASE_NOOPT) $(WARNS_CLANG)"

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean full all

static_analysis:
	@$(SCANNER) $(CC) $(WARNS_CLANG) $(CFLAGS_CLANG) $(MARCH) \
		-Xclang -analyzer-output=text --analyze $(filter %.c,$(SRCS)) -Iinclude
	@$(SCANNER) $(CC) $(WARNS_CLANG) $(CFLAGS_BASE_CLANG)\
		-Xclang -analyzer-output=text --analyze $(filter %.c,$(SRCS)) -Iinclude
	@$(CC_GCC) $(WARNS_GCC) $(CFLAGS_GCC) $(MARCH)\
		-fanalyzer $(filter %.c,$(SRCS)) -Iinclude -c && rm *.o
	@$(CC_GCC) $(WARNS_GCC) $(CFLAGS_BASE_GCC)\
		-fanalyzer $(filter %.c,$(SRCS)) -Iinclude -c && rm *.o

analyze: all static_analysis
	@if command -v ast2md >/dev/null 2>&1; then \
		AST2MD_THREADS=$$(nproc) ast2md -L c -i $$(find . -name "*.c") \
		-o stats -t $(THRESHOLD) -- -I include; \
	else \
		echo "ast2md not found, skipping coupling analysis"; \
	fi
	@echo "Running tests..."
	@$(foreach test,$(TEST_SRCS), \
		$(CC) $(CFLAGS) tests/$(test)_test.c -O3 -g3 $(NAME) -Iinclude $(SANITIZE) \
		-o test_$(test) && ./test_$(test) && rm -f test_$(test);)
	@echo "All tests passed!"

bonus: all

test: test_clang test_clang_no_march

test_clang:
	$(MAKE) _test_impl _TCFG=clang_march

test_clang_no_march:
	$(MAKE) _test_impl _TCFG=clang

ifdef _TCFG
ifeq ($(_TCFG),clang_march)
  _TCC    := $(CC_CLANG)
  _TFLAGS := $(MARCH) $(CFLAGS_BASE_CLANG) $(WARNS_CLANG)
  _TBDIR  := build_tc_march
  _TAR    := llvm-ar rcs
else ifeq ($(_TCFG),clang)
  _TCC    := $(CC_CLANG)
  _TFLAGS := $(CFLAGS_BASE_CLANG) $(WARNS_CLANG)
  _TBDIR  := build_tc
  _TAR    := llvm-ar rcs
endif

_TAR ?= $(AR)

TOBJS := $(patsubst src/%.c,$(_TBDIR)/%.o,$(SRCS))
TLIB  := libft_test_tmp.a

$(_TBDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(_TCC) $(_TFLAGS) -c $< -o $@ -Iinclude

_test_impl: $(TOBJS)
	$(_TAR) $(TLIB) $(TOBJS)
	@echo "Testing [$(_TCC)$(if $(findstring march,$(_TFLAGS)), +march,)]..."
	@$(foreach test,$(TEST_SRCS), \
		$(_TCC) $(_TFLAGS) tests/$(test)_test.c -O3 -g3 $(TLIB) -Iinclude $(SANITIZE) \
		-o test_$(test) && ./test_$(test) && rm -f test_$(test);)
	@rm -f $(TLIB)
	@rm -rf $(_TBDIR)
	@echo "All tests passed!"
endif

.PHONY: all base clean fclean re bonus full static_analysis analyze test test_clang test_clang_no_march _test_impl
