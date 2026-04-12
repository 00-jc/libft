/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_bench.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 01:52:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <benchmark/benchmark.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <vector>

extern "C"
{
    typedef struct s_tokenizer
    {
        uint8_t    *mem;
        size_t      max;
        size_t      cc;
    }   t_tokenizer;

    typedef struct s_token
    {
        uint8_t    *mem;
        size_t      len;
    }   t_token;

    typedef enum e_eater_select
    {
        set_blank  = 0,
        set_alpha  = 1,
        set_digit  = 2,
        set_xdigit = 3,
    }   t_eater_select;

    t_token     ft_eat_while(t_tokenizer *tk, t_eater_select select);
    t_token     ft_eat_until(t_tokenizer *tk, t_eater_select select);
    uint32_t    ft_tokenizer_goto(t_tokenizer *tk, uint8_t byte);
    t_tokenizer ft_tokenizer_over(void *mem, size_t size);
    void        ft_skip_whitespace(t_tokenizer *tk);
}

static std::vector<uint8_t> make_alpha(size_t n)
{
    std::vector<uint8_t> buf(n);
    for (size_t i = 0; i < n; i++)
        buf[i] = (uint8_t)('a' + i % 26);
    return buf;
}

static std::vector<uint8_t> make_digits(size_t n)
{
    std::vector<uint8_t> buf(n);
    for (size_t i = 0; i < n; i++)
        buf[i] = (uint8_t)('0' + i % 10);
    return buf;
}

static std::vector<uint8_t> make_words(size_t n_words)
{
    const size_t word_len = 8;
    const size_t stride   = word_len + 1;
    std::vector<uint8_t> buf(n_words * stride);
    for (size_t w = 0; w < n_words; w++)
    {
        for (size_t c = 0; c < word_len; c++)
            buf[w * stride + c] = (uint8_t)('a' + (w * word_len + c) % 26);
        buf[w * stride + word_len] = ' ';
    }
    return buf;
}

static void bench_eat_while_alpha(benchmark::State &state)
{
    size_t n = state.range(0);
    auto   buf = make_alpha(n);

    for (auto _ : state)
    {
        t_tokenizer tk  = ft_tokenizer_over(buf.data(), n);
        t_token     tok = ft_eat_while(&tk, set_alpha);
        benchmark::DoNotOptimize(tok.len);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_eat_while_digit(benchmark::State &state)
{
    size_t n = state.range(0);
    auto   buf = make_digits(n);

    for (auto _ : state)
    {
        t_tokenizer tk  = ft_tokenizer_over(buf.data(), n);
        t_token     tok = ft_eat_while(&tk, set_digit);
        benchmark::DoNotOptimize(tok.len);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_eat_until_blank(benchmark::State &state)
{
    size_t n = state.range(0);
    auto   buf = make_alpha(n);

    for (auto _ : state)
    {
        t_tokenizer tk  = ft_tokenizer_over(buf.data(), n);
        t_token     tok = ft_eat_until(&tk, set_blank);
        benchmark::DoNotOptimize(tok.len);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_goto_worst(benchmark::State &state)
{
    size_t n = state.range(0);
    auto   buf = make_alpha(n);
    buf[n - 1] = '\n';

    for (auto _ : state)
    {
        t_tokenizer tk = ft_tokenizer_over(buf.data(), n);
        uint32_t    r  = ft_tokenizer_goto(&tk, '\n');
        benchmark::DoNotOptimize(r);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_goto_early(benchmark::State &state)
{
    size_t n = state.range(0);
    auto   buf = make_alpha(n);
    buf[0] = '\n';

    for (auto _ : state)
    {
        t_tokenizer tk = ft_tokenizer_over(buf.data(), n);
        uint32_t    r  = ft_tokenizer_goto(&tk, '\n');
        benchmark::DoNotOptimize(r);
    }
    state.SetBytesProcessed(state.iterations() * n);
}

static void bench_tokenize_words(benchmark::State &state)
{
    size_t n   = state.range(0);
    auto   buf = make_words(n);

    for (auto _ : state)
    {
        t_tokenizer tk    = ft_tokenizer_over(buf.data(), buf.size());
        size_t      count = 0;
        while (tk.cc < tk.max)
        {
            t_token tok = ft_eat_while(&tk, set_alpha);
            count += (tok.len > 0);
            ft_skip_whitespace(&tk);
        }
        benchmark::DoNotOptimize(count);
    }
    state.SetBytesProcessed(state.iterations() * buf.size());
}

#define TOK_SIZES \
    ->Arg(8)->Arg(15)->Arg(16)->Arg(31)->Arg(32) \
    ->Arg(63)->Arg(64)->Arg(256)->Arg(4096)      \
    ->Arg(65536)->Arg(1 << 20)

#define WORD_SIZES \
    ->Arg(64)->Arg(512)->Arg(4096)->Arg(32768)

BENCHMARK(bench_eat_while_alpha)  TOK_SIZES;
BENCHMARK(bench_eat_while_digit)  TOK_SIZES;
BENCHMARK(bench_eat_until_blank)  TOK_SIZES;
BENCHMARK(bench_goto_worst)       TOK_SIZES;
BENCHMARK(bench_goto_early)       TOK_SIZES;
BENCHMARK(bench_tokenize_words)   WORD_SIZES;

BENCHMARK_MAIN();
