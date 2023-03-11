/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 06:27:57 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/11 21:35:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


#if 0
class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
};
template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
    return;
};

#endif // code flag





int main(void)
{
    SHOW_HEADER(== INT TYPE : EVAL ==)
    int nbrs[5] = { 0, 1, 2, 3, 4 };
    iter<int>(nbrs, 5, increment);
    iter<int>(nbrs, 5, print_array_item);
    iter<int>(NULL, 5, print_array_item);


    SHOW_HEADER(== CHAR TYPE : EVAL ==)
    char alphabets[5] = {'a', 'b', 'c', 'd', 'e' };
    iter<char>(alphabets, 5, increment);
    iter<char>(alphabets, 5, print_array_item);
    

    SHOW_HEADER(== FLOAT TYPE : EVAL ==)
    float nbr_float[5] = {0.0f, 0.1f, 0.2f, 0.3f, 0.4f };
    iter<float>(nbr_float, 5, increment);
    iter<float>(nbr_float, 5, print_array_item);


    SHOW_HEADER(== DOUBLE TYPE : EVAL ==)
    double nbr_double[5] = {0.0, 1.1, 2.2, 3.3, 4.4 };
    iter<double>(nbr_double, 5, increment);
    iter<double>(nbr_double, 5, print_array_item);

    SHOW_HEADER(== STRING TYPE : EVAL ==)
    std::string words[5] = {"We", "are", "the", "new", "champions"};
    iter<std::string>(words, 5, print_array_item);


#if 0
    {
        SHOW_HEADER(== COMPLEX TYPE : EVAL ==)
        int tab[] = {0, 1, 2, 3, 4};
        Awesome tab2[5];
        iter(tab, 5, print);
        iter(tab2, 5, print);
    }
#endif 
    return (0);
}

