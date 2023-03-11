/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:38:46 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/11 21:35:20 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <stdint.h>
# include <iostream>
# include <exception>
# define COL_YELLOW "\033[0;33m"
# define COL_DEFAULT "\033[0m"
# define COUT std::cout
# define ENDL std::endl
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW #MSG COL_DEFAULT << ENDL; 


template < typename T >
void    iter(T arrPtr[], uint32_t const &arrSize, void (*f)(T const &))
{
    uint32_t    idx = 0;
    
    if (arrPtr == NULL)
    {
        std::cout << "invalid array address (NULL) detected" << std::endl;
        return ;
    }
        
    for (; idx<arrSize; idx++)
    {
        f(arrPtr[idx]);
    }
}


template < typename T >
void    print_array_item(T const &item)
{
    std::cout << item << std::endl;
    return ;
}

template < typename T >
void    increment(T const &item)
{
    const_cast<T &>(item) = item + 1;
    return ;
}


#endif // ITER_HPP