# include <iostream>
# include <utility>
# include "BitcoinExchange.hpp"

// there's a data as a database based to extract the info.
// std::advance(); get the element at your position previded.
// std::next(); put something at proceded position?
// use the sort based on the date.
// use the fucking std::map and have more info.
// binnary sherch

int main(int argc, char *argv[])
{
    (void)argv;
    if (argc <= 1)
        return (std::cout << "Error: could not open file.", 1);

    try
    {
        BitcoinExchange DE;
        DE.set_DB();
        DE.set_FInput(argv[1]);
    }
    catch (const char *e)
    {
        std::cout << "Error: " << e << std::endl;
        return (1);
    }

    return (0);
}
