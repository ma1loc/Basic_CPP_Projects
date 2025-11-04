# include "whatever.hpp"
# include <iostream>

int main( void )
{
    int a = 2;
    int b = 3;

    std::cout << "========= value before the swap =========" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    ::swap( a, b );
    
    std::cout << "\n========= value after the swap =========" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "\n========= min/max int value =========" << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::cout << "\n========= swap two strings =========" << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "-> before swap\nc = " << c << ", d = " << d << std::endl;

    ::swap(c, d);

    std::cout << "\n-> after swap\nc = " << c << ", d = " << d << std::endl;

    std::cout << "\n========= min/max string value =========" << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    

    std::cout << "\n========= edge cases =========" << std::endl;
    std::cout << "max(1, 2) \"normal\" = " << max(1, 2) << std::endl;
    
    std::cout << "max<double>(1.1, 2) = " << max<double>(1.1, 1) << std::endl;
    std::cout << "max<float>(1.1, 2) = " << max<float>(1.1, 1) << std::endl;
    
    std::cout << "max<int>(1, 'a') = " << max<int>(1, 'a') << std::endl;
    std::cout << "max<char>(1, 'a') = " << max<char>(88, 'a') << std::endl;
    std::cout << "max<char>(1, 127) = " << max<char>(1, 127) << std::endl;
    std::cout << "max<int>(1, 1.0f) = " << max<int>(1, 1.0f) << std::endl;
    std::cout << "max<float>(1, 'a') = " << max<float>(1, 'a') << std::endl;
    std::cout << "max<double>(1, 'a') = " << max<double>(1, 'a') << std::endl;
    
    // std::cout << max<int>(1, 1.1) << std::endl; 
    
    return 0;
}
