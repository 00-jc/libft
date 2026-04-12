/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_bench.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 01:53:01 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstdint>
#include <cstdlib>
#include <vector>

extern "C"
{
    typedef struct s_vec
    {
        uint8_t         *head;
        size_t           capacity;
        const uint8_t   *data;
    }   t_vec;

    t_vec       ft_vec_new(size_t size, size_t type_size);
    size_t      ft_vec_bytesize(const t_vec *v);
    int         ft_vec_push_back(t_vec *vec, const uint8_t *data, size_t type_size);
    const void *ft_vec_get(const t_vec *vec, size_t idx, size_t type_size);
    void       *ft_vec_get_mut(const t_vec *vec, size_t idx, size_t type_size);
    int         ft_vec_pop(t_vec *v, size_t type_size);
    int         ft_vec_extend(t_vec *vec, const uint8_t *data, size_t type_size, size_t n);
    void        ft_vec_free(t_vec *v);
    void        ft_vec_clear(t_vec *v);
}

static void bench_vec_push_grow(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint64_t val = 0xCAFEBABEDEADBEEFull;

    for (auto _ : state)
    {
        t_vec v = ft_vec_new(1, sizeof(uint64_t));
        for (size_t i = 0; i < n; i++)
            ft_vec_push_back(&v, (const uint8_t *)&val, sizeof(uint64_t));
        benchmark::DoNotOptimize(v.head);
        ft_vec_free(&v);
    }
    state.SetItemsProcessed(state.iterations() * n);
}

static void bench_std_push_grow(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint64_t val = 0xCAFEBABEDEADBEEFull;

    for (auto _ : state)
    {
        std::vector<uint64_t> v;
        for (size_t i = 0; i < n; i++)
            v.push_back(val);
        benchmark::DoNotOptimize(v.data());
    }
    state.SetItemsProcessed(state.iterations() * n);
}

static void bench_vec_push_steady(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint64_t val = 0xDEADBEEFCAFEBABEull;

    t_vec v = ft_vec_new(n, sizeof(uint64_t));
    for (auto _ : state)
    {
        for (size_t i = 0; i < n; i++)
            ft_vec_push_back(&v, (const uint8_t *)&val, sizeof(uint64_t));
		ft_vec_clear(&v);
        benchmark::DoNotOptimize(v.head);
    }
    ft_vec_free(&v);
    state.SetItemsProcessed(state.iterations() * n);
}

static void bench_std_push_steady(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint64_t val = 0xDEADBEEFCAFEBABEull;

    std::vector<uint64_t> v;
    v.reserve(n);
    for (auto _ : state)
    {
        v.clear();
        for (size_t i = 0; i < n; i++)
            v.push_back(val);
        benchmark::DoNotOptimize(v.data());
    }
    state.SetItemsProcessed(state.iterations() * n);
}

static void bench_vec_extend(benchmark::State &state)
{
    size_t n = state.range(0);
    std::vector<uint64_t> src(n, 0xABCDEF0123456789ull);

    for (auto _ : state)
    {
        t_vec v = ft_vec_new(n, sizeof(uint64_t));
        ft_vec_extend(&v, (const uint8_t *)src.data(), sizeof(uint64_t), n);
        benchmark::DoNotOptimize(v.head);
        ft_vec_free(&v);
    }
    state.SetBytesProcessed(state.iterations() * n * sizeof(uint64_t));
}

static void bench_std_insert(benchmark::State &state)
{
    size_t n = state.range(0);
    std::vector<uint64_t> src(n, 0xABCDEF0123456789ull);

    for (auto _ : state)
    {
        std::vector<uint64_t> v;
        v.reserve(n);
        v.insert(v.end(), src.begin(), src.end());
        benchmark::DoNotOptimize(v.data());
    }
    state.SetBytesProcessed(state.iterations() * n * sizeof(uint64_t));
}

static void bench_vec_get(benchmark::State &state)
{
    size_t   n   = state.range(0);
    uint64_t val = 1;
    t_vec v = ft_vec_new(n, sizeof(uint64_t));
    for (size_t i = 0; i < n; i++)
        ft_vec_push_back(&v, (const uint8_t *)&val, sizeof(uint64_t));

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto *p = ft_vec_get(&v, idx, sizeof(uint64_t));
        benchmark::DoNotOptimize(p);
    }
    ft_vec_free(&v);
}

static void bench_std_get(benchmark::State &state)
{
    size_t n = state.range(0);
    std::vector<uint64_t> v(n, 1);

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto *p = &v[idx];
        benchmark::DoNotOptimize(p);
    }
}

static void bench_vec_pop(benchmark::State &state)
{
    size_t n = state.range(0);

    for (auto _ : state)
    {
        state.PauseTiming();
        t_vec v = ft_vec_new(n, sizeof(uint64_t));
        v.head = (uint8_t *)v.data + n * sizeof(uint64_t);
        state.ResumeTiming();

        for (size_t i = 0; i < n; i++)
            ft_vec_pop(&v, sizeof(uint64_t));
        benchmark::DoNotOptimize(v.head);

        state.PauseTiming();
        ft_vec_free(&v);
        state.ResumeTiming();
    }
    state.SetItemsProcessed(state.iterations() * n);
}

static void bench_std_pop(benchmark::State &state)
{
    size_t n = state.range(0);

    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<uint64_t> v(n, 1);
        state.ResumeTiming();

        for (size_t i = 0; i < n; i++)
            v.pop_back();
        benchmark::DoNotOptimize(v.data());
    }
    state.SetItemsProcessed(state.iterations() * n);
}

#define VEC_SIZES \
    ->Arg(8)->Arg(64)->Arg(256)->Arg(1024)->Arg(4096)->Arg(16384)

BENCHMARK(bench_vec_push_grow)    VEC_SIZES;
BENCHMARK(bench_std_push_grow)    VEC_SIZES;
BENCHMARK(bench_vec_push_steady)  VEC_SIZES;
BENCHMARK(bench_std_push_steady)  VEC_SIZES;
BENCHMARK(bench_vec_extend)       VEC_SIZES;
BENCHMARK(bench_std_insert)       VEC_SIZES;
BENCHMARK(bench_vec_get)          VEC_SIZES;
BENCHMARK(bench_std_get)          VEC_SIZES;
BENCHMARK(bench_vec_pop)          VEC_SIZES;
BENCHMARK(bench_std_pop)          VEC_SIZES;

BENCHMARK_MAIN();
