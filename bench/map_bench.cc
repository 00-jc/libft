/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bench.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 22:08:04 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 00:00:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <cstring>
#include <cstdint>

extern "C"
{
	typedef struct s_bucket
	{
		size_t		key_len;
		uint8_t		*key;
		uint8_t		*value;
	}	t_bucket;

	typedef struct s_map
	{
		size_t		table_size;
		size_t		count;
		t_bucket	*buckets;
		uint8_t		*meta;
	}	t_map;

	t_map		ft_map_with(size_t capacity);
	t_map		ft_map_new(void);
	void		*ft_map_lookup(const t_map *map, uint8_t *mem, size_t size);
	uint32_t	ft_map_insert(t_map *map, uint8_t *key, size_t keylen, uint8_t *value);
	void		ft_map_destroy(t_map *map);
	void		ft_map_delete(t_map *map, uint8_t *key, size_t keylen);
	void		ft_map_clear(t_map *map);
}

static std::vector<std::vector<uint8_t>> make_keys(size_t n, size_t len)
{
    std::vector<std::vector<uint8_t>> keys(n, std::vector<uint8_t>(len));
    std::mt19937_64 rng(123);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < len; j++)
            keys[i][j] = rng() & 0xFF;

    return keys;
}

/* ── ft_map benchmarks ───────────────────────────────────────────────────── */

static void bench_lookup_hit(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    t_map map = ft_map_with(n * 2);
    for (size_t i = 0; i < n; i++)
        ft_map_insert(&map, keys[i].data(), 16, keys[i].data());

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto *r = ft_map_lookup(&map, keys[idx].data(), 16);
        benchmark::DoNotOptimize(r);
    }
    ft_map_destroy(&map);
}

static void bench_lookup_miss(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);
    auto   miss = make_keys(n, 16);

    t_map map = ft_map_with(n * 2);
    for (size_t i = 0; i < n; i++)
        ft_map_insert(&map, keys[i].data(), 16, keys[i].data());

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto *r = ft_map_lookup(&map, miss[idx].data(), 16);
        benchmark::DoNotOptimize(r);
    }
    ft_map_destroy(&map);
}

static void bench_insert_grow(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    for (auto _ : state)
    {
        t_map map = ft_map_new();
        for (size_t i = 0; i < n; i++)
            ft_map_insert(&map, keys[i].data(), 16, keys[i].data());
        ft_map_destroy(&map);
    }
}

static void bench_insert_steady(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    t_map map = ft_map_with(n * 2);
    for (size_t i = 0; i < n; i++)
        ft_map_insert(&map, keys[i].data(), 16, keys[i].data());

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        ft_map_insert(&map, keys[idx].data(), 16, keys[idx].data());
    }
    ft_map_destroy(&map);
}

static void bench_delete(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    for (auto _ : state)
    {
        t_map map = ft_map_with(n * 2);
        for (size_t i = 0; i < n; i++)
            ft_map_insert(&map, keys[i].data(), 16, keys[i].data());
        for (size_t i = 0; i < n; i++)
            ft_map_delete(&map, keys[i].data(), 16);
        ft_map_destroy(&map);
    }
}

/* ── std::unordered_map comparison ──────────────────────────────────────── */

static void bench_std_lookup_hit(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    std::unordered_map<std::string, void *> map;
    map.reserve(n * 2);

    std::vector<std::string> str_keys;
    str_keys.reserve(n);
    for (size_t i = 0; i < n; i++)
    {
        str_keys.emplace_back(keys[i].begin(), keys[i].end());
        map[str_keys[i]] = keys[i].data();
    }

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto it = map.find(str_keys[idx]);
        benchmark::DoNotOptimize(it);
    }
}

static void bench_std_lookup_miss(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);
    auto   miss = make_keys(n, 16);

    std::unordered_map<std::string, void *> map;
    map.reserve(n * 2);

    std::vector<std::string> str_keys;
    std::vector<std::string> miss_keys;
    str_keys.reserve(n);
    miss_keys.reserve(n);
    for (size_t i = 0; i < n; i++)
    {
        str_keys.emplace_back(keys[i].begin(), keys[i].end());
        miss_keys.emplace_back(miss[i].begin(), miss[i].end());
        map[str_keys[i]] = keys[i].data();
    }

    size_t idx = 0;
    for (auto _ : state)
    {
        idx = (idx + 1) % n;
        auto it = map.find(miss_keys[idx]);
        benchmark::DoNotOptimize(it);
    }
}

static void bench_std_insert_grow(benchmark::State &state)
{
    size_t n    = state.range(0);
    auto   keys = make_keys(n, 16);

    std::vector<std::string> str_keys;
    str_keys.reserve(n);
    for (size_t i = 0; i < n; i++)
        str_keys.emplace_back(keys[i].begin(), keys[i].end());

    for (auto _ : state)
    {
        std::unordered_map<std::string, void *> map;
        for (size_t i = 0; i < n; i++)
            map[str_keys[i]] = keys[i].data();
        benchmark::DoNotOptimize(map.size());
    }
}

/* ── Registration ────────────────────────────────────────────────────────── */

#define MAP_SIZES \
    ->Arg(64)->Arg(256)->Arg(1024)->Arg(4096)->Arg(16384)

BENCHMARK(bench_lookup_hit)       MAP_SIZES;
BENCHMARK(bench_lookup_miss)      MAP_SIZES;
BENCHMARK(bench_insert_grow)      MAP_SIZES;
BENCHMARK(bench_insert_steady)    MAP_SIZES;
BENCHMARK(bench_delete)           MAP_SIZES;

BENCHMARK(bench_std_lookup_hit)   MAP_SIZES;
BENCHMARK(bench_std_lookup_miss)  MAP_SIZES;
BENCHMARK(bench_std_insert_grow)  MAP_SIZES;

BENCHMARK_MAIN();
