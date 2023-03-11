/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:38:46 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/11 22:37:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <stdint.h>
# include <iostream>
# include <exception>
# include <cstring>
# include <cstdlib>

# define COL_YELLOW "\033[0;33m"
# define COL_DEFAULT "\033[0m"
# define COUT std::cout
# define ENDL std::endl
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW #MSG COL_DEFAULT << ENDL; 


template < typename T >
class Array
{
    private:
        unsigned int _size;
        T           *_array_ptr;
#ifdef __TEST
         T _error;
#endif
        
    public:
        Array(void) : _size(0), _array_ptr(NULL)//, //_error(0)
        {
            COUT << "calling default constructor\n";
        }

        Array(unsigned int n) : _size(n)//, //_error(0)
        {
            _array_ptr = new T[_size];

            if (_array_ptr == NULL)
            {
                COUT << "mem alloc failed!\n";
                throw ArrayNullPointerException();
            }
            COUT << "calling parametric constructor\n";
        }

        /* copy constructor */
        Array(Array const &other)
        {
            COUT << "calling copy constructor\n";
            if (other._array_ptr == NULL)
            {
                _array_ptr = NULL;
                _size = other._size;
            }
            else
            {
                _size = other._size;
                _array_ptr = new T[_size];
                if (_array_ptr != NULL)
                {
                    memcpy(static_cast<void *>(_array_ptr), 
                           static_cast<void *>(other._array_ptr),
                           (sizeof(T) * _size));

                }
            }
        }
        

        /* copy assignment constructor */
        Array const &operator=(Array const &other)
        {
            COUT << "calling copy assignment constructor\n";
            if (other._array_ptr == NULL)
            {
                _array_ptr = NULL;
                _size = other._size;
            }
            else
            {
                _size = other._size;
                _array_ptr = new T[_size];
                if (_array_ptr != NULL)
                {
                    memcpy(static_cast<void *>(_array_ptr), 
                           static_cast<void *>(other._array_ptr),
                           (sizeof(T) * _size));

                }
            }
           return (*this);
        }

        /* Operator Overloading */
        T &operator[](unsigned int idx) const
        {
           if (_array_ptr == NULL)
           {
                throw ArrayNullPointerException();
           }
           else if (idx >= _size)
           {
                throw ArrayInvalidIndexException();
           }

           return (_array_ptr[idx]);
        }

        /* destructor */
        ~Array(void)
        {
            COUT << "calling destructor \n";
            delete [] _array_ptr;
            _array_ptr = NULL;
        }
        
        unsigned int size(void) const
        {
            return (this->_size);
        }

        /*== EXCEPTIONS NESTED CLASS ==*/
        class ArrayNullPointerException : public std::exception
        {
            virtual char const *what() const throw()
            {
                return ("Error: null pointer\n");
            }
        };
        
        class ArrayInvalidIndexException : public std::exception
        {
            virtual char const *what() const throw()
            {
                return ("Error: invalid index to array provided\n");
            }
        };
        
        void showItems(void) const
        {
            if (_array_ptr != NULL && _size > 0)
            {
                for (unsigned int x = 0; x < _size; x++)
                {
                    COUT << _array_ptr[x] << ENDL;
                }
            }
            return ;
        }
};



#endif // ITER_HPP