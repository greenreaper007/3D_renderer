/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_fast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 01:31:07 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/25 01:32:44 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

float atof_fast(const char *s)
{
	float result = 0.0f;
	float sign = 1.0f;
	if (*s == '-')
	{
		sign = -1.0f;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10.0f + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		float frac = 0.0f;
		float base = 0.1f;
		while (*s >= '0' && *s <= '9')
		{
			frac += (*s - '0') * base;
			base *= 0.1f;
			s++;
		}
		result += frac;
	}
    return (result * sign);
}
