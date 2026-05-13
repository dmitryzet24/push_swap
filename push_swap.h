/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsutormi <dsutormi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:04:43 by dsutormi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/11 17:29:23 by dsutormi         ###   ########.fr       */
=======
/*   Updated: 2026/05/11 18:13:52 by dsutormi         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//comment
typedef struct s_stack
{
	int					value;
	int					index;

	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

#endif