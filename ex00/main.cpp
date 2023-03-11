/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/11 16:17:36 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

#if 0

class Awesome
{
public:
    Awesome(void) : _n(0) {}
    Awesome(int n) : _n(n) {}
    Awesome &operator=(Awesome &a)
    {
        _n = a._n;
        return *this;
    }
    bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
    bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }

private:
    int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a)
{
    o << a.get_n();
    return o;
}
#endif


int main(void)
{
    /* swap */
    {
        SHOW_HEADER(=== TEST : SWAP(INT) ===)
        int x = 5, y = 20;
        SHOW_VAL(x, y);
        swap<int>(x, y);
        SHOW_VAL(x, y);

        COUT << ENDL;
        SHOW_HEADER(=== TEST : SWAP(FLOAT) ===)
        float a = 5.2f, b = 4.3f;
        SHOW_VAL(a, b);
        swap<float>(a, b);
        SHOW_VAL(a, b);

        COUT << ENDL;
        SHOW_HEADER(=== TEST : SWAP(CHAR) ===)
        char i = 'a', j = 'b';
        SHOW_VAL(i, j);
        swap<char>(i, j);
        SHOW_VAL(i, j);
    }
    /* min */
    {
        COUT << ENDL;
        SHOW_HEADER(=== TEST : MIN (INT) ===)
        int x = 5, y = 20;
        SHOW_VAL(x, y);
        COUT << "min: " << min<int>(x, y) << ENDL;

        COUT << ENDL;
        SHOW_HEADER(=== TEST : MIN (FLOAT) ===)
        float a = 5.2f, b = 4.3f;
        SHOW_VAL(a, b);
        COUT << "min: " << min<float>(a, b) << ENDL;

        COUT << ENDL;
        SHOW_HEADER(=== TEST : MIN (CHAR) ===)
        char i = 'a', j = 'b';
        SHOW_VAL(i, j);
        COUT << "min: " << min<char>(i, j) << ENDL;
    }
    /* max */
    {
        COUT << ENDL;
        SHOW_HEADER(=== TEST : MAX (INT) ===)
        int x = 5, y = 20;
        SHOW_VAL(x, y);
        COUT << "max: " << max<int>(x, y) << ENDL;

        COUT << ENDL;
        SHOW_HEADER(=== TEST : MAX (FLOAT) ===)
        float a = 5.2f, b = 4.3f;
        SHOW_VAL(a, b);
        COUT << "max: " << max<float>(a, b) << ENDL;

        COUT << ENDL;
        SHOW_HEADER(=== TEST : MAX (CHAR) ===)
        char i = 'a', j = 'b';
        SHOW_VAL(i, j);
        COUT << "max: " << max<char>(i, j) << ENDL;
    }

    COUT << ENDL;
    SHOW_HEADER(=== TEST : SUBJECT_FILE ===)
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

#if 0
    {
        COUT << ENDL;
        SHOW_HEADER(=== TEST : SUBJECT_FILE COMPLEX TYPE ===)
        Awesome a(2), b(4);
        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }
#endif
    return (0);
}