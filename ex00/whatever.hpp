/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:41 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/08 21:28:15 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << COL_YELLOW #MSG COL_DEFAULT << ENDL; 
# define SHOW_VAL(X,Y) COUT << "x(" << X << ") : y(" << Y <<  ")\n"

template< typename T >
void    swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template< typename T >
T const &min(T const &x, T const &y)
{
    return (x < y ? x : y);
}


template< typename T >
T const &max(T const &x, T const &y)
{
    return (x > y ? x : y);
}

#endif // WHATEVER_HPP