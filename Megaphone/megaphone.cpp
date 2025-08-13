#include <iostream>

void    set_upper_case(std::string arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] >= 'a' && arg[i] <= 'z')
            arg[i] -= 32;
        i++;
    }
    std::cout << arg;
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        i = 1;
        while (argv[i])
        {
            set_upper_case(argv[i]);
            i++;
        }
        std::cout << std::endl;
    }

    return (0);
}
