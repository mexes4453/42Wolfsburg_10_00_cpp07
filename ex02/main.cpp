/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 06:27:57 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/11 22:03:49 cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#if 1
class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }
    void set(int v) { _n = v; }

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
#endif // AWESOME CLASS





int main(void)
{
    SHOW_HEADER(== INT TYPE : EVAL ==)
    Array<int>  nbrs(5);
    
    /* Initialise all items in array */
    for (int x=0; x<5; x++) { nbrs[x] = 0; }

    COUT << "Setting index 3 to 3... \n"; nbrs[3] = 50;
    COUT << "Printing item in index 3:  " << nbrs[3] << ENDL;
    COUT << "Array size :" << nbrs.size() << ENDL;
    COUT << "copy array: \n";
    Array<int> copy_nbrs = nbrs;
    
    SHOW_HEADER(== SHOW ORIGINAL ==) nbrs.showItems();
    SHOW_HEADER(== SHOW COPY ==) copy_nbrs.showItems();

    SHOW_HEADER(== MODIFY ORIGINAL == index 0 => 2) nbrs[0] = 2;
    SHOW_HEADER(== SHOW ORIGINAL ==) nbrs.showItems();
    SHOW_HEADER(== SHOW COPY ==) copy_nbrs.showItems();

    {
        SHOW_HEADER(== EMPTY ARRAY ==)
        Array<int> nbrs;
        COUT << "==> Array size :" << nbrs.size() << ENDL;
        COUT << "==> print items in empty array\n"; nbrs.showItems();
        try
        {
            COUT << "==> Accessing empty array: " << nbrs[6] << ENDL;
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
        }
    }

#if 1
    {
        SHOW_HEADER(== COMPLEX TYPE : EVAL ==)
        Array<Awesome> tab(5);
        tab.showItems();
        
        SHOW_HEADER(== COPYING ORIGINAL ...)
        Array<Awesome> copy_tab(tab);
        
        SHOW_HEADER(== SHOW ORIGINAL ==) tab.showItems();
        SHOW_HEADER(== SHOW COPY ==) copy_tab.showItems();

        SHOW_HEADER(== MODIFY ORIGINAL == index 0 => 2) tab[0].set(2);

        SHOW_HEADER(== SHOW ORIGINAL ==) tab.showItems();
        SHOW_HEADER(== SHOW COPY ==) copy_tab.showItems();

        COUT << "Printing item in index 0:  " << tab[0] << ENDL;
        try
        {
            COUT << "==> Accessing invalid index: " << tab[6] << ENDL;
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
        }
    }
#endif 
    return (0);
}

