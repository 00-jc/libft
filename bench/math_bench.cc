/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bench.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 01:52:03 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstdint>
#include <cmath>

extern "C"
{
    struct __attribute__((aligned(32))) t_4packd { double x, y, z, w; };
    struct __attribute__((aligned(64))) t_8packd { double x, y, z, w, a, b, c, d; };
    typedef t_4packd t_3dcoords;
    struct __attribute__((aligned(64))) t_3dcoordsx8 {
        t_3dcoords a, b, c, d, e, f, g, h;
    };

    float   ft_sqrt(float x);
    double  ft_dsqrt(double x);
    float   ft_q_sqrt(float x);
    float   ft_rsqrt(float x);
    double  ft_drsqrt(double x);

    t_4packd ft_drsqrt_x4(t_4packd d);
    t_8packd ft_drsqrt_x8(t_8packd d);
    t_8packd ft_dsqrt_x8(t_8packd d);

    float    ft_fpow(float x, uint64_t n);
    double   ft_dpow(double x, uint64_t n);

    double  ft_fabs(double x);

    t_3dcoords ft_3dadd(t_3dcoords a, t_3dcoords b);
    t_3dcoords ft_3dsub(t_3dcoords a, t_3dcoords b);
    t_3dcoords ft_3dmul(t_3dcoords a, t_3dcoords b);
    t_3dcoords ft_3ddiv(t_3dcoords a, t_3dcoords b);
    double     ft_3dnorm(t_3dcoords c);
    double     ft_3ddot(t_3dcoords a, t_3dcoords b);
    t_3dcoords ft_3dunit(t_3dcoords c);
    t_3dcoords ft_3dcross(t_3dcoords a, t_3dcoords b);

    t_3dcoordsx8 ft_3dadd8(t_3dcoordsx8 a, t_3dcoordsx8 b);
    t_3dcoordsx8 ft_3dsub8(t_3dcoordsx8 a, t_3dcoordsx8 b);
    t_3dcoordsx8 ft_3dmul8(t_3dcoordsx8 a, t_3dcoordsx8 b);
    t_8packd     ft_3dnorm8(t_3dcoordsx8 c);
    t_8packd     ft_3ddot8(t_3dcoordsx8 a, t_3dcoordsx8 b);
    t_3dcoordsx8 ft_3dunit8(t_3dcoordsx8 c);
}

static void bench_ft_sqrtf(benchmark::State &state)
{
    float x = 2.0f;
    for (auto _ : state)
    {
        x = ft_sqrt(x + 1.0f);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_sqrtf(benchmark::State &state)
{
    float x = 2.0f;
    for (auto _ : state)
    {
        x = std::sqrt(x + 1.0f);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_q_sqrt(benchmark::State &state)
{
    float x = 2.0f;
    for (auto _ : state)
    {
        x = ft_q_sqrt(x + 1.0f);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_ft_dsqrt(benchmark::State &state)
{
    double x = 2.0;
    for (auto _ : state)
    {
        x = ft_dsqrt(x + 1.0);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_dsqrt(benchmark::State &state)
{
    double x = 2.0;
    for (auto _ : state)
    {
        x = std::sqrt(x + 1.0);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_ft_rsqrt(benchmark::State &state)
{
    float x = 2.0f;
    for (auto _ : state)
    {
        x = ft_rsqrt(x + 1.0f);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_rsqrt(benchmark::State &state)
{
    float x = 2.0f;
    for (auto _ : state)
    {
        x = 1.0f / std::sqrt(x + 1.0f);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_ft_drsqrt(benchmark::State &state)
{
    double x = 2.0;
    for (auto _ : state)
    {
        x = ft_drsqrt(x + 1.0);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_drsqrt(benchmark::State &state)
{
    double x = 2.0;
    for (auto _ : state)
    {
        x = 1.0 / std::sqrt(x + 1.0);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_drsqrt_x8(benchmark::State &state)
{
    t_8packd v = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    for (auto _ : state)
    {
        v = ft_drsqrt_x8(v);
        benchmark::DoNotOptimize(v.x);
    }
}

static void bench_drsqrt_x8_scalar(benchmark::State &state)
{
    double a = 2.0, b = 3.0, c = 4.0, d = 5.0;
    double e = 6.0, f = 7.0, g = 8.0, h = 9.0;
    for (auto _ : state)
    {
        a = 1.0 / std::sqrt(a);
        b = 1.0 / std::sqrt(b);
        c = 1.0 / std::sqrt(c);
        d = 1.0 / std::sqrt(d);
        e = 1.0 / std::sqrt(e);
        f = 1.0 / std::sqrt(f);
        g = 1.0 / std::sqrt(g);
        h = 1.0 / std::sqrt(h);
        benchmark::DoNotOptimize(h);
    }
}

static void bench_dsqrt_x8(benchmark::State &state)
{
    t_8packd v = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    for (auto _ : state)
    {
        v = ft_dsqrt_x8(v);
        benchmark::DoNotOptimize(v.x);
    }
}

static void bench_ft_fabs(benchmark::State &state)
{
    double x = -1.5;
    for (auto _ : state)
    {
        x = ft_fabs(x - 0.1);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_fabs(benchmark::State &state)
{
    double x = -1.5;
    for (auto _ : state)
    {
        x = std::fabs(x - 0.1);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_ft_fpow(benchmark::State &state)
{
    uint64_t n = (uint64_t)state.range(0);
    float    x = 1.0001f;
    for (auto _ : state)
    {
        x = ft_fpow(x, n);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_fpow(benchmark::State &state)
{
    uint64_t n = (uint64_t)state.range(0);
    float    x = 1.0001f;
    for (auto _ : state)
    {
        x = std::pow(x, (float)n);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_ft_dpow(benchmark::State &state)
{
    uint64_t n = (uint64_t)state.range(0);
    double   x = 1.0001;
    for (auto _ : state)
    {
        x = ft_dpow(x, n);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_std_dpow(benchmark::State &state)
{
    uint64_t n = (uint64_t)state.range(0);
    double   x = 1.0001;
    for (auto _ : state)
    {
        x = std::pow(x, (double)n);
        benchmark::DoNotOptimize(x);
    }
}

static void bench_3dadd(benchmark::State &state)
{
    t_3dcoords a = {1.0, 2.0, 3.0, 0.0};
    t_3dcoords b = {4.0, 5.0, 6.0, 0.0};
    for (auto _ : state)
    {
        a = ft_3dadd(a, b);
        benchmark::DoNotOptimize(a.x);
    }
}

static void bench_3dsub(benchmark::State &state)
{
    t_3dcoords a = {4.0, 5.0, 6.0, 0.0};
    t_3dcoords b = {1.0, 2.0, 3.0, 0.0};
    for (auto _ : state)
    {
        a = ft_3dsub(a, b);
        benchmark::DoNotOptimize(a.x);
    }
}

static void bench_3dmul(benchmark::State &state)
{
    t_3dcoords a = {1.5, 2.5, 3.5, 0.0};
    t_3dcoords b = {2.0, 3.0, 4.0, 0.0};
    for (auto _ : state)
    {
        a = ft_3dmul(a, b);
        benchmark::DoNotOptimize(a.x);
    }
}

static void bench_3dnorm(benchmark::State &state)
{
    t_3dcoords v = {3.0, 4.0, 0.0, 0.0};
    for (auto _ : state)
    {
        double r = ft_3dnorm(v);
        v.x = r;
        benchmark::DoNotOptimize(r);
    }
}

static void bench_3ddot(benchmark::State &state)
{
    t_3dcoords a = {1.0, 2.0, 3.0, 0.0};
    t_3dcoords b = {4.0, 5.0, 6.0, 0.0};
    for (auto _ : state)
    {
        double r = ft_3ddot(a, b);
        a.x = r;
        benchmark::DoNotOptimize(r);
    }
}

static void bench_3dunit(benchmark::State &state)
{
    t_3dcoords v = {3.0, 4.0, 0.0, 0.0};
    for (auto _ : state)
    {
        v = ft_3dunit(v);
        benchmark::DoNotOptimize(v.x);
    }
}

static void bench_3dcross(benchmark::State &state)
{
    t_3dcoords a = {1.0, 0.0, 0.0, 0.0};
    t_3dcoords b = {0.0, 1.0, 0.0, 0.0};
    for (auto _ : state)
    {
        a = ft_3dcross(a, b);
        benchmark::DoNotOptimize(a.x);
    }
}

static void bench_3dadd8(benchmark::State &state)
{
    t_3dcoordsx8 a = {
        {1,2,3,0},{4,5,6,0},{7,8,9,0},{1,2,3,0},
        {4,5,6,0},{7,8,9,0},{1,2,3,0},{4,5,6,0}
    };
    t_3dcoordsx8 b = a;
    for (auto _ : state)
    {
        a = ft_3dadd8(a, b);
        benchmark::DoNotOptimize(a.a.x);
    }
}

static void bench_3dadd_x1_x8(benchmark::State &state)
{
    t_3dcoords a0={1,2,3,0}, a1={4,5,6,0}, a2={7,8,9,0}, a3={1,2,3,0};
    t_3dcoords a4={4,5,6,0}, a5={7,8,9,0}, a6={1,2,3,0}, a7={4,5,6,0};
    t_3dcoords b  = {1,1,1,0};
    for (auto _ : state)
    {
        a0 = ft_3dadd(a0, b);
        a1 = ft_3dadd(a1, b);
        a2 = ft_3dadd(a2, b);
        a3 = ft_3dadd(a3, b);
        a4 = ft_3dadd(a4, b);
        a5 = ft_3dadd(a5, b);
        a6 = ft_3dadd(a6, b);
        a7 = ft_3dadd(a7, b);
        benchmark::DoNotOptimize(a7.x);
    }
}

static void bench_3dnorm8(benchmark::State &state)
{
    t_3dcoordsx8 a = {
        {3,4,0,0},{1,0,0,0},{0,1,0,0},{0,0,1,0},
        {1,1,0,0},{2,2,2,0},{3,0,4,0},{1,2,3,0}
    };
    for (auto _ : state)
    {
        t_8packd r = ft_3dnorm8(a);
        a.a.x = r.a;
        benchmark::DoNotOptimize(r.a);
    }
}

static void bench_3dnorm_x1_x8(benchmark::State &state)
{
    t_3dcoords v[8] = {
        {3,4,0,0},{1,0,0,0},{0,1,0,0},{0,0,1,0},
        {1,1,0,0},{2,2,2,0},{3,0,4,0},{1,2,3,0}
    };
    for (auto _ : state)
    {
        double r = 0.0;
        for (int i = 0; i < 8; i++)
        {
            r = ft_3dnorm(v[i]);
            v[i].x = r;
        }
        benchmark::DoNotOptimize(r);
    }
}

#define POW_SIZES ->Arg(2)->Arg(8)->Arg(16)->Arg(64)->Arg(256)

BENCHMARK(bench_ft_sqrtf);
BENCHMARK(bench_std_sqrtf);
BENCHMARK(bench_q_sqrt);

BENCHMARK(bench_ft_dsqrt);
BENCHMARK(bench_std_dsqrt);

BENCHMARK(bench_ft_rsqrt);
BENCHMARK(bench_std_rsqrt);

BENCHMARK(bench_ft_drsqrt);
BENCHMARK(bench_std_drsqrt);

BENCHMARK(bench_drsqrt_x8);
BENCHMARK(bench_drsqrt_x8_scalar);
BENCHMARK(bench_dsqrt_x8);

BENCHMARK(bench_ft_fabs);
BENCHMARK(bench_std_fabs);

BENCHMARK(bench_ft_fpow)  POW_SIZES;
BENCHMARK(bench_std_fpow) POW_SIZES;
BENCHMARK(bench_ft_dpow)  POW_SIZES;
BENCHMARK(bench_std_dpow) POW_SIZES;

BENCHMARK(bench_3dadd);
BENCHMARK(bench_3dsub);
BENCHMARK(bench_3dmul);
BENCHMARK(bench_3dnorm);
BENCHMARK(bench_3ddot);
BENCHMARK(bench_3dunit);
BENCHMARK(bench_3dcross);

BENCHMARK(bench_3dadd8);
BENCHMARK(bench_3dadd_x1_x8);
BENCHMARK(bench_3dnorm8);
BENCHMARK(bench_3dnorm_x1_x8);

BENCHMARK_MAIN();
