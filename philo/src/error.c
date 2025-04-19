/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:17:58 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/19 04:19:04 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_failure(char *error_phrase)
{
	printf("Error: %s\n", error_phrase);
	return (EXIT_FAILURE);
}