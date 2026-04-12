/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_bench.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 01:50:51 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <random>

extern "C"
{
    struct t_buffer { size_t size; uint8_t *mem; };

    uint64_t        ft_xxh3_64bits(t_buffer input, uint64_t seed);
    __uint128_t     ft_murmur3(const uint8_t *mem, size_t size);
    __uint128_t     ft_murmur3_with_seed(const uint8_t *mem, uint64_t seed, size_t size);
}

static constexpr size_t HASH_BUF = 1 << 20;
static constexpr uint64_t SEED   = 0;

static uint8_t *rand_buf()
{
    static uint8_t *p = nullptr;
    if (p)
        return p;
    p = (uint8_t *)malloc(HASH_BUF);
    std::mt19937_64 rng(42);
    for (size_t i = 0; i < HASH_BUF; i += 8)
    {
        uint64_t v = rng();
        __builtin_memcpy(p + i, &v, 8);
    }
    return p;
}

static inline uint8_t *next_ptr(benchmark::State &state, size_t n)
{
    size_t off = (state.iterations() * 64) & (HASH_BUF / 2 - 1);
    return rand_buf() + off;
}

static void bench_xxh3(benchmark::State &state)
{
    size_t n = state.range(0);
    for (auto _ : state)
    {
        uint8_t         *p = next_ptr(state, n);
        t_buffer         b = {n, p};
        uint64_t         r = ft_xxh3_64bits(b, SEED);
        benchmark::DoNotOptimize(r);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_murmur3(benchmark::State &state)
{
    size_t n = state.range(0);
    for (auto _ : state)
    {
        uint8_t     *p = next_ptr(state, n);
        __uint128_t  r = ft_murmur3(p, n);
        benchmark::DoNotOptimize(r);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_murmur3_seeded(benchmark::State &state)
{
    size_t n = state.range(0);
    for (auto _ : state)
    {
        uint8_t     *p = next_ptr(state, n);
        __uint128_t  r = ft_murmur3_with_seed(p, 0xDEADBEEFCAFEBABEull, n);
        benchmark::DoNotOptimize(r);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

#define HASH_SIZES                                            \
    ->Arg(4)->Arg(8)->Arg(16)->Arg(17)->Arg(32)->Arg(64)     \
    ->Arg(128)->Arg(129)->Arg(240)->Arg(256)->Arg(1024)      \
    ->Arg(4096)->Arg(65536)->Arg(1 << 20)

BENCHMARK(bench_xxh3)           HASH_SIZES;
BENCHMARK(bench_murmur3)        HASH_SIZES;
BENCHMARK(bench_murmur3_seeded) HASH_SIZES;

BENCHMARK_MAIN();
