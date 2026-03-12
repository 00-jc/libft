/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/12 12:36:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "mem.h"

typedef union u_fp
{
	float	f;
	t_u32	i;
}	t_fp;

typedef union u_dp
{
	double	f;
	t_u64	i;
}	t_dp;

typedef struct s_2packd
{
	double	x;
	double	y;
} __attribute__((aligned(16), packed))	t_2packd;

typedef struct s_4packd
{
	double	x;
	double	y;
	double	z;
	double	w;
} __attribute__((aligned(32), packed))	t_4packd;

typedef struct s_8packd
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	a;
	double	b;
	double	c;
	double	d;
} __attribute__((aligned(64), packed))	t_8packd;

typedef t_4packd	t_3dcoords;

float			ft_q_sqrt(float x)\
					__attribute__((const));
double			ft_q_dsqrt(double number)\
					__attribute__((const));
float			ft_sqrt(float number)\
					__attribute__((const));
double			ft_dsqrt(double number)\
					__attribute__((const));
float			ft_q_sqrt_round(float number, t_u8 n)\
					__attribute__((const));
float			ft_q_sqrt_fround(float number)\
					__attribute__((const));
float			ft_roundf(float x, t_u8 n)\
					__attribute__((const));
float			ft_floorf(float x)\
					__attribute__((const));
float			ft_ceilf(float x)\
					__attribute__((const));
t_u128			ft_pow_u128(t_u128 x, t_u128 n)\
					__attribute__((const));
t_u64			ft_pow_u64(t_u64 x, t_u64 n)\
					__attribute__((const));
t_u32			ft_pow_u32(t_u32 x, t_u32 n)\
					__attribute__((const));
t_u8			ft_pow_u8(t_u8 x, t_u8 n)\
					__attribute__((const));
int				ft_ipow(int x, t_u64 n)\
					__attribute__((const));
long long		ft_lpow(long long x, t_u64 n)\
					__attribute__((const));
float			ft_fpow(float x, t_u64 n)\
					__attribute__((const));
double			ft_dpow(double x, t_u64 n)\
					__attribute__((const));
float			ft_roundff(float x)\
					__attribute__((const));
double			ft_fabs(double x)\
					__attribute__((const));
float			ft_rsqrt(float number)\
					__attribute__((const));
double			ft_drsqrt(double number)\
					__attribute__((const));
t_8packd		ft_drsqrt_x8(t_8packd d1)\
					__attribute__ ((const));
t_4packd		ft_drsqrt_x4(t_4packd d1)\
					__attribute__ ((const));
t_8packd		ft_dsqrt_x8(t_8packd d1)\
					__attribute__ ((const));
t_3dcoords		ft_3dsub(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
t_3dcoords		ft_3dadd(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
double			ft_3dnorm(t_3dcoords c)\
					__attribute__((const));
double			ft_3ddot(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
t_3dcoords		ft_3dunit(t_3dcoords c)\
					__attribute__((const));
t_3dcoords		ft_3dmul(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
t_3dcoords		ft_3ddiv(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
t_3dcoords		ft_3dcross(t_3dcoords a, t_3dcoords b)\
					__attribute__((const));
#endif
