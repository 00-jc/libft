/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmi_bench.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:57:07 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 22:06:39 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstdint>
#include <cstdlib>

extern "C"
{
    uint64_t 	__hasz64(uint64_t);
    uint64_t 	__populate(uint8_t);

    size_t 		ft_memctz_u64(uint64_t);
    size_t 		ft_memclz_u64(uint64_t);

    uint64_t	ft_bswap64(uint64_t);
    uint64_t	ft_rotl64(uint64_t, size_t);

    size_t		__max_s(size_t, size_t);
    uint64_t	__maxu64(uint64_t, uint64_t);
}

static inline uint64_t next(uint64_t x)
{
    return x * 0x9E3779B97F4A7C15ull + 1;
}

static void bench_ctz64(benchmark::State &state)
{
    uint64_t x = 0x123456789ABCDEF;

    for (auto _ : state)
    {
        x = next(x);
        auto r = ft_memctz_u64(x);
        benchmark::DoNotOptimize(r);
    }
}

static void bench_clz64(benchmark::State &state)
{
    uint64_t x = 0xFEDCBA987654321;

    for (auto _ : state)
    {
        x = next(x);
        auto r = ft_memclz_u64(x);

        benchmark::DoNotOptimize(r);
    }
}

static void bench_bswap64(benchmark::State &state)
{
    uint64_t x = 0x0123456789ABCDEF;

    for (auto _ : state)
    {
        x = next(x);
        x = ft_bswap64(x);

        benchmark::DoNotOptimize(x);
    }
}

static void bench_rotl64(benchmark::State &state)
{
    uint64_t x = 0xCAFEBABEDEADBEEF;
    size_t n = 13;

    for (auto _ : state)
    {
        x = next(x);
        x = ft_rotl64(x, n);

        benchmark::DoNotOptimize(x);
    }
}

static void bench_hasz64(benchmark::State &state)
{
    uint64_t x = 0xFFFFFFFFFFFFFFFF;

    for (auto _ : state)
    {
        x = next(x);
        auto r = __hasz64(x);

        benchmark::DoNotOptimize(r);
    }
}

static void bench_populate(benchmark::State &state)
{
    uint8_t x = 0xAA;

    for (auto _ : state)
    {
        x = (uint8_t)(x * 33 + 1);
        auto r = __populate(x);

        benchmark::DoNotOptimize(r);
    }
}

static void bench_maxu64(benchmark::State &state)
{
    uint64_t a = 1, b = 2;

    for (auto _ : state)
    {
        a = next(a);
        b = next(b);

        auto r = __maxu64(a, b);
        benchmark::DoNotOptimize(r);
    }
}

static void bench_max_s(benchmark::State &state)
{
    size_t a = 1, b = 2;

    for (auto _ : state)
    {
        a = (size_t)next((uint64_t)a);
        b = (size_t)next((uint64_t)b);

        auto r = __max_s(a, b);
        benchmark::DoNotOptimize(r);
    }
}

BENCHMARK(bench_ctz64);
BENCHMARK(bench_clz64);
BENCHMARK(bench_bswap64);
BENCHMARK(bench_rotl64);
BENCHMARK(bench_hasz64);
BENCHMARK(bench_populate);
BENCHMARK(bench_maxu64);
BENCHMARK(bench_max_s);

BENCHMARK_MAIN();
