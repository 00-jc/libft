# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 03:43:49 by jaicastr          #+#    #+#              #
#    Updated: 2026/03/11 01:30:43 by jaicastr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ── Output ────────────────────────────────────────────────────────────────────
NAME       := libft.a
OBJDIR     := build

# ── Toolchain ─────────────────────────────────────────────────────────────────
CC_CLANG   := clang
CC_GCC     := gcc
AR         := ar rcs
SCANNER    := scan-build

# ── Flags ─────────────────────────────────────────────────────────────────────
MARCH      := -march=native
INCLUDES   := -Iinclude

WARNS_COMMON := -Wall -Wextra -Werror -Wshadow -Wattributes -fstrict-aliasing \
	-Wpedantic -std=c99 -Waddress -Wstrict-aliasing -Wredundant-decls         \
	-Wstrict-prototypes -Wnull-dereference -Wundef -Wformat-security -Wformat=2 \
	-Wwrite-strings -Wold-style-definition -Wuninitialized -Wpointer-arith     \
	-Wmissing-prototypes -Wunused -Wtautological-compare -Wvla

WARNS_CLANG := $(WARNS_COMMON)                                                \
	-Wambiguous-ellipsis -Wambiguous-macro -Wassume -Wpessimizing-move         \
	-Wgnu-union-cast -Wlanguage-extension-token                               \
	-Wgnu-statement-expression-from-macro-expansion                            \
	-Wbounds-safety-counted-by-elt-type-unknown-size -Wcast-function-type-strict \
	-Wcast-function-type-mismatch -Wc99-compat -Wbool-conversions              \
	-Wbool-operation -Wbitwise-instead-of-logical -Wbitfield-enum-conversion    \
	-Warray-bounds-pointer-arithmetic -Wnull-pointer-arithmetic                \
	-Wloop-analysis -Wcomma -Wover-aligned -Wunreachable-code

WARNS_GCC  := $(WARNS_COMMON)                                                 \
	-Wcast-function-type -Wlogical-op -Wduplicated-cond

CFLAGS_OPT := -O3 -pipe -ffunction-sections -fdata-sections -finline-functions \
	-fvisibility=hidden -fstack-protector-strong -fcf-protection=full          \
	-ftrivial-auto-var-init=zero -fno-common -fstack-clash-protection -g3

CFLAGS_NOOPT := -pipe -ffunction-sections -fdata-sections -finline-functions   \
	-fvisibility=hidden -fstack-protector-strong -fcf-protection=full          \
	-ftrivial-auto-var-init=zero -fno-common -fstack-clash-protection -g3

SANITIZE   := -fsanitize=address,alignment,undefined -fsanitize-recover=null

# ── Defaults (clang + optimised) ─────────────────────────────────────────────
CC         := $(CC_CLANG)
CFLAGS     := $(MARCH) $(CFLAGS_OPT) $(WARNS_CLANG)

# ── Sources ───────────────────────────────────────────────────────────────────
SRCS_ALLOC := \
	src/alloc/arena/ft_arena_alloc_utils.c \
	src/alloc/arena/ft_arena_alloc_scopes.c \
	src/alloc/arena/ft_arena_alloc.c \
	src/alloc/ft_alloc.c \
	src/alloc/ft_calloc.c \
	src/alloc/ft_extend.c \
	src/alloc/ft_extend_zero.c \
	src/alloc/ft_realloc.c \
	src/alloc/ft_recalloc.c \
	src/alloc/ft_mmap.c \
	src/alloc/ft_free.c

SRCS_CONV := \
	src/conv/ft_itoa_base.c \
	src/conv/ft_atoul.c \
	src/conv/ft_atoul_bounded.c \
	src/conv/ft_atod.c \
	src/conv/ft_atod_bounded.c \
	src/conv/ft_atof.c \
	src/conv/ft_atoi.c \
	src/conv/ft_atol.c \
	src/conv/ft_itoa.c \
	src/conv/ft_utoa_base.c \
	src/conv/ft_atoi_base.c

SRCS_CSTR := \
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
	src/cstr/ft_strjoin.c

SRCS_CTYPE := \
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
	src/ctype/ft_isdigit.c

SRCS_IO := \
	src/io/ft_printf_helpers2.c \
	src/io/ft_read_file_portable.c \
	src/io/ft_read_file.c \
	src/io/ft_printf_helpers.c \
	src/io/ft_lockf.c \
	src/io/ft_printf.c

SRCS_MATH := \
	src/math/3d/ft_3dadd.c \
	src/math/3d/ft_3dsub.c \
	src/math/3d/ft_3dnorm.c \
	src/math/3d/ft_3dunit.c \
	src/math/3d/ft_3dmul.c \
	src/math/3d/ft_3ddiv.c \
	src/math/3d/ft_3ddot.c \
	src/math/ft_pow.c \
	src/math/ft_round.c \
	src/math/ft_fabs.c \
	src/math/ft_sqrt.c \
	src/math/ft_pow_signed.c \
	src/math/ft_q_sqrt.c \
	src/math/ft_rsqrt.c \
	src/math/ft_drsqrt_xn.c \
	src/math/ft_sqrt_xn.c

SRCS_MEM := \
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
	src/mem/ft_prefetch_intrin.c

SRCS_VEC := \
	src/vec/ft_vec_remove.c \
	src/vec/ft_vec_pop.c \
	src/vec/ft_vec_new.c \
	src/vec/ft_vec_free.c \
	src/vec/ft_vec_push_back.c \
	src/vec/ft_vec_get.c \
	src/vec/ft_vec_bytesize.c \
	src/vec/ft_vec_extend.c

SRCS_STR := \
	src/str/ft_str_remove.c \
	src/str/ft_str_push_back.c \
	src/str/ft_str_extend.c \
	src/str/ft_str_new.c

SRCS_BMI := \
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
	src/bmi/__hasz.c

SRCS_ENV := \
	src/env/ft_getenv.c

SRCS_MAP := \
	src/swissmap/ft_map_insert.c \
	src/swissmap/ft_map_lookup.c \
	src/swissmap/ft_map_delete.c \
	src/swissmap/ft_map_rehash.c \
	src/swissmap/ft_map_insert_unchecked.c \
	src/swissmap/ft_map.c

SRCS_HINT := \
	src/hint/ft_pin_invariant.c \
	src/hint/ft_hardcrash.c

SRCS_TOK := \
	src/tokenizer/ft_eat_u128.c \
	src/tokenizer/ft_eat_u256.c \
	src/tokenizer/ft_eat_u512.c \
	src/tokenizer/ft_eat_until.c \
	src/tokenizer/ft_eat_u8.c \
	src/tokenizer/ft_sets.c \
	src/tokenizer/ft_tokenizer.c \
	src/tokenizer/ft_eat_while.c

# ── Aggregate ─────────────────────────────────────────────────────────────────
MODULES := ALLOC CONV CSTR CTYPE IO MATH MEM VEC STR BMI ENV MAP HINT TOK

SRCS := $(foreach m,$(MODULES),$(SRCS_$(m)))
OBJS := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))

# ── Tests ─────────────────────────────────────────────────────────────────────
TEST_SRCS := memchr strlen memcmp memcpy memset vec str map murmur bmi

# ═════════════════════════════════════════════════════════════════════════════
#  Targets
# ═════════════════════════════════════════════════════════════════════════════

all: $(NAME)

# ── Normal build (individual .o → archive) ───────────────────────────────────
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

# ── Convenience ──────────────────────────────────────────────────────────────
base:
	$(MAKE) fclean all CFLAGS="$(CFLAGS_NOOPT) $(WARNS_CLANG)"

bonus: all

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# ── Static analysis ─────────────────────────────────────────────────────────
static_analysis:
	$(SCANNER) $(CC_CLANG) $(WARNS_CLANG) $(CFLAGS_OPT) $(MARCH) $(INCLUDES) \
		-Xclang -analyzer-output=text --analyze $(SRCS)
	$(SCANNER) $(CC_CLANG) $(WARNS_CLANG) $(CFLAGS_OPT) $(INCLUDES) \
		-Xclang -analyzer-output=text --analyze $(SRCS)
	$(CC_GCC) $(WARNS_GCC) $(CFLAGS_OPT) $(MARCH) $(INCLUDES) \
		-fanalyzer $(SRCS) -c && rm -f *.o
	$(CC_GCC) $(WARNS_GCC) $(CFLAGS_OPT) $(INCLUDES) \
		-fanalyzer $(SRCS) -c && rm -f *.o
	norminette

# ── Tests ────────────────────────────────────────────────────────────────────
test: test_clang test_clang_no_march

test_clang:
	$(MAKE) _test_impl _TCFG=clang_march

test_clang_no_march:
	$(MAKE) _test_impl _TCFG=clang

ifdef _TCFG
ifeq ($(_TCFG),clang_march)
  _TCC    := $(CC_CLANG)
  _TFLAGS := $(MARCH) $(CFLAGS_OPT) $(WARNS_CLANG)
  _TBDIR  := build_tc_march
  _TAR    := llvm-ar rcs
else ifeq ($(_TCFG),clang)
  _TCC    := $(CC_CLANG)
  _TFLAGS := $(CFLAGS_OPT) $(WARNS_CLANG)
  _TBDIR  := build_tc
  _TAR    := llvm-ar rcs
endif

_TAR ?= $(AR)
TOBJS := $(patsubst src/%.c,$(_TBDIR)/%.o,$(SRCS))
TLIB  := libft_test_tmp.a

$(_TBDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(_TCC) $(_TFLAGS) $(INCLUDES) -c $< -o $@

_test_impl: $(TOBJS)
	$(_TAR) $(TLIB) $(TOBJS)
	@echo "Testing [$(_TCC)$(if $(findstring march,$(_TFLAGS)), +march,)]..."
	@$(foreach t,$(TEST_SRCS), \
		$(_TCC) $(_TFLAGS) tests/$(t)_test.c -O3 -g3 $(TLIB) $(INCLUDES) $(SANITIZE) \
		-o test_$(t) && ./test_$(t) && rm -f test_$(t);)
	@rm -f $(TLIB)
	@rm -rf $(_TBDIR)
	@echo "All tests passed!"
endif

analyze: all static_analysis test

.PHONY: all base bonus clean fclean re \
        static_analysis analyze test test_clang test_clang_no_march _test_impl
