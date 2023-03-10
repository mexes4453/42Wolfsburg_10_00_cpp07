/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:38:46 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/09 21:55:54 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <stdint.h>


template < typename T >
void    iter(T *arrPtr, uint32_t arrSize, void (*f)(T &))
{
    uint32_t    idx;
    
    if (arrPtr == NULL || (arrSize == 0))
        return ;
    
    for (idx=0; idx<arrSize; idx++)
    {
        *f(arrPtr[idx]);
    }
}


template < typename Y >
void    add(Y &)
#endif // ITER_HPP