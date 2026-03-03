/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 00:00:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/test.h"

void	test_str_push_back(void);
void	test_str_extend(void);
void	test_str_remove(void);
void	test_str_grow(void);

void	test_str_push_back(void)
{
	t_str	s;

	s = ft_str_new(8);
	ft_pin_invariant(s.data != NULL);
	ft_pin_invariant(s.len == 0);
	ft_pin_invariant(ft_str_push_back(&s, 'H'));
	ft_pin_invariant(ft_str_push_back(&s, 'i'));
	ft_pin_invariant(s.len == 2);
	ft_pin_invariant(s.data[0] == 'H');
	ft_pin_invariant(s.data[1] == 'i');
	ft_pin_invariant(s.data[2] == '\0');
	ft_str_free(&s);
}

void	test_str_extend(void)
{
	t_str	s;

	s = ft_str_new(16);
	ft_pin_invariant(ft_str_extend(&s, (t_u8 *)"hello", 5));
	ft_pin_invariant(s.len == 6);
	ft_pin_invariant(memcmp(s.data, "hello", 5) == 0);
	ft_str_free(&s);
}

void	test_str_remove(void)
{
	t_str	s;

	s = ft_str_new(16);
	ft_str_push_back(&s, 'a');
	ft_str_push_back(&s, 'b');
	ft_str_push_back(&s, 'c');
	ft_pin_invariant(ft_str_remove(&s, 1));
	ft_pin_invariant(s.len == 2);
	ft_pin_invariant(s.data[0] == 'a');
	ft_pin_invariant(s.data[1] == 'c');
	ft_pin_invariant(!ft_str_remove(&s, 5));
	ft_str_free(&s);
}

void	test_str_grow(void)
{
	t_str	s;
	int		i;

	s = ft_str_new(4);
	i = 0;
	while (i < 200)
	{
		ft_pin_invariant(ft_str_push_back(&s, 'A' + (i % 26)));
		i++;
	}
	ft_pin_invariant(s.len == 200);
	ft_pin_invariant(s.capacity >= 200);
	ft_pin_invariant(s.data[0] == 'A');
	ft_pin_invariant(s.data[199] == 'A' + (199 % 26));
	ft_str_free(&s);
}

int	main(void)
{
	ft_printf("Testing t_str...\n");
	test_str_push_back();
	test_str_extend();
	test_str_remove();
	test_str_grow();
	ft_printf("  t_str: OK\n");
	return (0);
}
