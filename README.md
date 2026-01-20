# libft

A high-performance C library for 42 school projects with SIMD optimizations.

## Usage

```c
#include "lft.h"  // Includes all public APIs
```

Or include specific headers from `include/` as needed.

## Public API

All public functions use the `ft_` prefix.

### Memory Operations (`mem.h`)

| Function | Description |
|----------|-------------|
| `void ft_bzero(void *ptr, size_t n)` | Set memory to zero |
| `void ft_memset(void *s, t_u8 c, size_t n)` | Fill memory with byte |
| `void ft_memcpy(void *dest, const void *src, size_t n)` | Copy memory (non-overlapping) |
| `void *ft_memmove(void *dest, const void *src, size_t n)` | Copy memory (overlapping safe) |
| `void *ft_memchr(const void *ptr, int c, size_t n)` | Find byte in memory |
| `ssize_t ft_memcmp(const void *dest, const void *src, size_t n)` | Compare memory |
| `void *ft_memclone(void *ptr, size_t size)` | Clone memory block |
| `void ft_membroadcast(void *dst, void *src, size_t chunks, size_t n)` | Broadcast pattern to memory |
| `t_u128a ft_murmur3(const t_u8 *mem, size_t size)` | MurmurHash3 128-bit hash |
| `t_u128a ft_murmur3_with_seed(const t_u8 *mem, t_u64a seed, size_t size)` | MurmurHash3 with custom seed |

### Memory Allocation (`alloc.h`)

| Function | Description |
|----------|-------------|
| `void *ft_alloc(size_t size)` | Allocate memory |
| `void *ft_alloc_align(size_t size, size_t align)` | Allocate aligned memory |
| `void *ft_calloc(size_t n, size_t size)` | Allocate zeroed memory |
| `void ft_free(void **ptr)` | Free and nullify pointer |
| `void ft_free_array(void ***arr)` | Free null-terminated array |
| `void *ft_realloc(void *ptr, size_t n, size_t size)` | Reallocate memory |
| `void *ft_recalloc(void *ptr, size_t n, size_t size)` | Reallocate with zeroing |
| `void *ft_extend(void *ptr, size_t n, size_t size)` | Extend allocation |
| `void *ft_extend_zero(void *ptr, size_t n, size_t size)` | Extend with zeroing |

### C-String Operations (`cstr.h`)

| Function | Description |
|----------|-------------|
| `size_t ft_strlen(const char *str)` | String length |
| `char *ft_strdup(const char *str)` | Duplicate string |
| `char *ft_strchr(const char *s, int c)` | Find char in string |
| `char *ft_strrchr(const char *s, int c)` | Find char from end |
| `size_t ft_strlcpy(char *dst, const char *src, size_t n)` | Safe string copy |
| `size_t ft_strlcat(char *dst, const char *src, size_t n)` | Safe string concat |
| `int ft_strcmp(const char *a, const char *b)` | Compare strings |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compare n chars |
| `char *ft_strnstr(const char *hay, const char *needle, size_t n)` | Find substring |
| `char *ft_strjoin(const char *s1, const char *s2)` | Concatenate strings (new alloc) |
| `char *ft_substr(const char *s, unsigned int start, size_t len)` | Extract substring |
| `char *ft_strtrim(const char *str, const char *set)` | Trim characters |
| `char **ft_split(const char *str, char delim)` | Split string by delimiter |
| `char *ft_strmapi(const char *s, char (*f)(unsigned int, char))` | Map function over string |
| `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Iterate with index |
| `int ft_tolower(int c)` | Convert to lowercase |
| `int ft_toupper(int c)` | Convert to uppercase |
| `t_u8 ft_isnumeric(const char *s)` | Check if string is numeric |

### Character Type (`ctype.h`)

| Function | Description |
|----------|-------------|
| `int ft_isalpha(int c)` | Is alphabetic |
| `int ft_isdigit(int c)` | Is digit |
| `int ft_isalnum(int c)` | Is alphanumeric |
| `int ft_isascii(int c)` | Is ASCII |
| `int ft_isxdigit(int c)` | Is hex digit |
| `int ft_isprint(int c)` | Is printable |
| `int ft_isspace(int c)` | Is whitespace |

### Conversions (`conv.h`)

| Function | Description |
|----------|-------------|
| `int ft_atoi(const char *str)` | String to int |
| `ssize_t ft_atol(const char *str)` | String to long |
| `size_t ft_atoul(const char *str)` | String to unsigned long |
| `float ft_atof(const char *s)` | String to float |
| `double ft_atod(const char *s)` | String to double |
| `int ft_atoi_base(char *str, char *base, int base_len)` | String to int with base |
| `char *ft_itoa(int n)` | Int to string |
| `char *ft_itoa_base(int n, char *base)` | Int to string with base |
| `char *ft_utoa_base(size_t n, char *base)` | Unsigned to string with base |

### Math (`math.h`)

| Function | Description |
|----------|-------------|
| `float ft_sqrt(float x)` | Square root (accurate) |
| `double ft_dsqrt(double x)` | Double square root |
| `float ft_q_sqrt(float x)` | Square root (fast approx) |
| `double ft_q_dsqrt(double x)` | Double square root (fast) |
| `float ft_roundf(float x, t_u8 n)` | Round to n decimals |
| `float ft_floorf(float x)` | Floor |
| `float ft_ceilf(float x)` | Ceiling |
| `double ft_fabs(double x)` | Absolute value |
| `int ft_ipow(int x, t_u64 n)` | Integer power |
| `float ft_fpow(float x, t_u64 n)` | Float power |
| `double ft_dpow(double x, t_u64 n)` | Double power |
| `t_u64 ft_pow_u64(t_u64 x, t_u64 n)` | Unsigned 64-bit power |

### I/O (`io.h`, `put.h`)

```c
typedef struct s_file {
    size_t  size;
    t_u8    *content;
} t_file;
```

| Function | Description |
|----------|-------------|
| `t_file ft_read_file(const char *fname)` | Memory-map file for reading (returns `{0}` on error) |
| `void ft_close_file(t_file *f)` | Unmap file opened with `ft_read_file` |
| `void ft_printf(const char *fmt, ...)` | Formatted print to stdout |
| `void ft_fprintf(int fd, const char *fmt, ...)` | Formatted print to fd |
| `void ft_putchar_fd(char c, int fd)` | Write char to fd |
| `void ft_putstr_fd(const char *s, int fd)` | Write string to fd |
| `void ft_putendl_fd(const char *s, int fd)` | Write string + newline |
| `void ft_putnbr_fd(int n, int fd)` | Write number to fd |

### Dynamic Vector (`vec.h`)

```c
typedef struct s_vec {
    t_u8        *head;
    size_t      capacity;
    const t_u8  *data;
} t_vec;
```

| Function | Description |
|----------|-------------|
| `t_vec ft_vec_new(size_t size, size_t type_size)` | Create vector |
| `int ft_vec_push_back(t_vec *v, const t_u8 *data, size_t type_size)` | Append element |
| `int ft_vec_extend(t_vec *v, const t_u8 *data, size_t type_size, size_t n)` | Append multiple |
| `const void *ft_vec_get(const t_vec *v, size_t idx, size_t type_size)` | Get element (const) |
| `void *ft_vec_get_mut(const t_vec *v, size_t idx, size_t type_size)` | Get element (mutable) |
| `void *ft_vec_get_last(const t_vec *v, size_t type_size)` | Get last element |
| `int ft_vec_pop(t_vec *v, size_t type_size)` | Remove last element |
| `int ft_vec_remove(t_vec *v, size_t i, size_t type_size)` | Remove at index |
| `int ft_vec_reserve(t_vec *v, size_t type_size, size_t n)` | Reserve capacity |
| `size_t ft_vec_len(const t_vec *v, size_t type_size)` | Get length |
| `void ft_vec_clear(t_vec *v)` | Clear (keep capacity) |
| `void ft_vec_free(t_vec *v)` | Free vector |

### Dynamic String (`str.h`)

```c
typedef struct s_string {
    size_t  len;
    size_t  capacity;
    t_u8    *data;
} t_str;
```

| Function | Description |
|----------|-------------|
| `t_str ft_str_new(size_t n)` | Create with capacity |
| `int ft_str_push_back(t_str *s, t_u8 byte)` | Append byte |
| `int ft_str_extend(t_str *s, const t_u8 *data, size_t n)` | Append bytes |
| `int ft_str_remove(t_str *s, size_t idx)` | Remove at index |
| `void ft_str_free(t_str *s)` | Free string |

## Types (`structs.h`)

```c
typedef unsigned char   t_u8;       // 8-bit unsigned
typedef uint32_t        t_u32;      // 32-bit unsigned
typedef uint64_t        t_u64;      // 64-bit unsigned
typedef __uint128_t     t_u128;     // 128-bit unsigned
typedef uintptr_t       t_uptr;     // Pointer-sized unsigned
```

Aligned variants (`t_u32a`, `t_u64a`, `t_u128a`) enforce proper alignment.

## Private API (`lft_private.h`)

Internal functions not intended for external use. Uses `__` prefix.

| Function | Purpose |
|----------|---------|
| `__hasz64()`, `__hasz128()` | Zero byte detection |
| `__populate()` | Broadcast byte to word |
| `__maxu8/32/64/128()` | Max of two values |
| `get_high128/256/512()` | SIMD high-bit masks |
| `get_lones128/256/512()` | SIMD all-ones patterns |
| `get_mask128/256/512()` | SIMD custom masks |
| `ft_memcpy_8x64/128/256/512()` | Vectorized memcpy |
| `ft_memset_8x64/128/256/512()` | Vectorized memset |

SIMD vector types:
```c
t_vu128, t_vu256, t_vu512     // Unaligned SIMD vectors
t_vu128a, t_vu256a, t_vu512a  // Aligned SIMD vectors
```

## Macros (`macros.h`)

ANSI color codes: `RED`, `GREEN`, `BLUE`, `YELLOW`, `CYAN`, `MAGENTA`, `WHITE`, `BLACK` (and bright variants with `B` prefix, backgrounds with `BG_` prefix).

Reset: `ANSI_RESET`

## Building

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove everything
make re     # Rebuild
make analyze # Run static analysis and tests
```

Compiler flags: `-O3 -flto -march=native -std=c99`

Disable SIMD: Define `__LIBFT_SCALAR__` for scalar-only builds.

### `make analyze`

Runs comprehensive code quality checks:

1. **Static Analysis**: Uses `scan-build` (Clang Static Analyzer) to detect potential bugs
2. **Coupling Analysis**: Runs `ast2md` (if installed) to analyze code coupling with a threshold of 0.40
3. **Test Suite**: Compiles and runs tests with AddressSanitizer, UndefinedBehaviorSanitizer, and alignment checks for:
   - `ft_strlen`
   - `ft_memchr`
   - `ft_memcmp`
   - `ft_memmove`
   - `ft_membroadcast`
   - `ft_memclone`

## Architecture-Specific Implementations

The library uses conditional compilation to select optimal implementations based on CPU features.

### x86_64 with AVX-512 (`src/x86/*.S`)

When **all** of these conditions are met:
- `__x86_64__` is defined (64-bit x86)
- `__AVX512VL__` is defined (AVX-512 Vector Length Extensions)
- `__LIBFT_SCALAR__` is **not** defined

The following hand-optimized assembly implementations are used:

| File | Function | Description |
|------|----------|-------------|
| `src/x86/ft_memcpy.S` | `ft_memcpy` | AVX-512 memory copy with non-temporal stores for large buffers |
| `src/x86/ft_memset.S` | `ft_memset` | AVX-512 memory fill with tiered loop unrolling |
| `src/x86/ft_strlen.S` | `ft_strlen` | AVX-512 string length using mask registers |
| `src/x86/ft_memchr.S` | `ft_memchr` | AVX-512 byte search with 256-byte blocks |

### Fallback Implementations (`src/mem/*.c`)

When **any** of these conditions are true:
- Not on x86_64 (`__x86_64__` not defined)
- AVX-512VL not available (`__AVX512VL__` not defined)
- Scalar mode forced (`__LIBFT_SCALAR__` defined)

The C implementations in `src/mem/` are compiled instead:

| Condition | Implementation |
|-----------|----------------|
| AVX2 only (no AVX-512) | Tiered SIMD using 128/256-bit intrinsics (`ft_memcpy_8x128`, `ft_memset_8x256`, etc.) |
| No SIMD or `__LIBFT_SCALAR__` | 64-bit word-at-a-time portable implementations |

The portable C versions use word-based techniques (`t_u64a` aligned 64-bit operations) with zero-byte detection (`__hasz64`) for `ft_memchr` and byte broadcasting (`__populate`) for efficient fills.
