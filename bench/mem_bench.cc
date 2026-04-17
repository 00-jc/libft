/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bench.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:47:16 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 22:53:31 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <sys/types.h>

extern "C"
{
    void    ft_bzero(void *ptr, size_t n);
    void    ft_memset(void *s, unsigned char c, size_t n);
    void    ft_memcpy(void *dest, const void *src, size_t n);
    void   *ft_memmove(void *dest, const void *src, size_t n);
    void   *ft_memchr(const void *ptr, int c, size_t n);
    ssize_t ft_memcmp(const void *a, const void *b, size_t n);
}

static constexpr size_t BUF_SIZE = 1 << 22;
static constexpr size_t ALIGN    = 64;

static uint8_t *alloc_buf(uint8_t fill)
{
    void *raw = nullptr;
    (void)posix_memalign(&raw, ALIGN, BUF_SIZE);
	benchmark::DoNotOptimize(raw);
    memset(raw, fill, BUF_SIZE);
    return (uint8_t *)raw;
}

static uint8_t *src_buf()
{
    static uint8_t *p = alloc_buf(0xAB);
    return p;
}

static uint8_t *dst_buf()
{
    static uint8_t *p = alloc_buf(0x00);
    return p;
}

static inline size_t get_offset(benchmark::State &state)
{
    return (state.iterations() * 64) & (BUF_SIZE / 2 - 1);
}

static void ft_memcpy_unaligned(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off + 3;
        uint8_t *src = src_buf() + off + 5;
        ft_memcpy(dst, src, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void libc_memcpy_unaligned(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off + 3;
        uint8_t *src = src_buf() + off + 5;
        memcpy(dst, src, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memcpy_aligned(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state) & ~(size_t)63;
        uint8_t *dst = dst_buf() + off;
        uint8_t *src = src_buf() + off;
        ft_memcpy(dst, src, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void libc_memcpy_aligned(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state) & ~(size_t)63;
        uint8_t *dst = dst_buf() + off;
        uint8_t *src = src_buf() + off;
        memcpy(dst, src, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memset_bench(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off;
        ft_memset(dst, 0xCC, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void libc_memset_bench(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off;
        memset(dst, 0xCC, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_bzero_bench(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off;
        ft_bzero(dst, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void libc_bzero_bench(benchmark::State &state)
{
    size_t n = state.range(0);
	benchmark::DoNotOptimize(n);
    for (auto _ : state)
    {
        size_t   off = get_offset(state);
        uint8_t *dst = dst_buf() + off;
        memset(dst, 0, n);
        benchmark::DoNotOptimize(dst);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memcmp_worst(benchmark::State &state)
{
    size_t   n = state.range(0);
    uint8_t *a = dst_buf();
    uint8_t *b = src_buf();
    memcpy(a, b, n);

    for (auto _ : state)
        benchmark::DoNotOptimize(ft_memcmp(a, b, n));

    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memcmp_early(benchmark::State &state)
{
    size_t   n = state.range(0);
    uint8_t *a = dst_buf();
    uint8_t *b = src_buf();
    memcpy(a, b, n);
    a[0] ^= 1;

    for (auto _ : state)
        benchmark::DoNotOptimize(ft_memcmp(a, b, n));

    state.SetBytesProcessed(state.iterations() * n);
}

static void libc_memcmp_worst(benchmark::State &state)
{
    size_t   n = state.range(0);
    uint8_t *a = dst_buf();
    uint8_t *b = src_buf();
    memcpy(a, b, n);

    for (auto _ : state)
        benchmark::DoNotOptimize(memcmp(a, b, n));

    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memchr_worst(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = src_buf();
    memset(buf, 0xAA, n);
    buf[n - 1] = 0xFF;

    for (auto _ : state)
        benchmark::DoNotOptimize(ft_memchr(buf, 0xFF, n));

    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memchr_early(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = src_buf();
    memset(buf, 0xAA, n);
    buf[0] = 0xFF;

    for (auto _ : state)
        benchmark::DoNotOptimize(ft_memchr(buf, 0xFF, n));

    state.SetBytesProcessed(state.iterations() * n);
}

static void ft_memmove_fwd(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = dst_buf();

    for (auto _ : state)
    {
        ft_memmove(buf + 1, buf, n - 1);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * (n - 1));
}

static void ft_memmove_bwd(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = dst_buf();

    for (auto _ : state)
    {
        ft_memmove(buf, buf + 1, n - 1);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * (n - 1));
}

static void libc_memmove_fwd(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = dst_buf();

    for (auto _ : state)
    {
        memmove(buf + 1, buf, n - 1);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * (n - 1));
}

static void libc_memmove_bwd(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint8_t *buf = dst_buf();

    for (auto _ : state)
    {
        memmove(buf, buf + 1, n - 1);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(state.iterations() * (n - 1));
}

#define MEM_SIZES                         \
    ->Arg(1)->Arg(2)->Arg(4)->Arg(8)	  \
	->Arg(16)->Arg(32)->Arg(64)			  \
    ->Arg(128)->Arg(256)->Arg(512)        \
    ->Arg(1024)->Arg(2048)->Arg(4096)     \
    ->Arg(8192)->Arg(16384)->Arg(32768)   \
    ->Arg(65536)->Arg(262144)->Arg(1<<20)

BENCHMARK(ft_memcpy_unaligned)   MEM_SIZES;
BENCHMARK(libc_memcpy_unaligned) MEM_SIZES;
BENCHMARK(ft_memcpy_aligned)     MEM_SIZES;
BENCHMARK(libc_memcpy_aligned)   MEM_SIZES;

BENCHMARK(ft_memset_bench)       MEM_SIZES;
BENCHMARK(libc_memset_bench)     MEM_SIZES;

BENCHMARK(ft_bzero_bench)        MEM_SIZES;
BENCHMARK(libc_bzero_bench)      MEM_SIZES;

BENCHMARK(ft_memcmp_worst)       MEM_SIZES;
BENCHMARK(ft_memcmp_early)       MEM_SIZES;
BENCHMARK(libc_memcmp_worst)     MEM_SIZES;

BENCHMARK(ft_memchr_worst)       MEM_SIZES;
BENCHMARK(ft_memchr_early)       MEM_SIZES;

BENCHMARK(ft_memmove_fwd)        MEM_SIZES;
BENCHMARK(ft_memmove_bwd)        MEM_SIZES;
BENCHMARK(libc_memmove_fwd)      MEM_SIZES;
BENCHMARK(libc_memmove_bwd)      MEM_SIZES;

BENCHMARK_MAIN();
