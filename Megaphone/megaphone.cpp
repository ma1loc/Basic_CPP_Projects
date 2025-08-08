#include <iostream>

using std::cout;
using std::endl;

void    set_upper_case(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] >= 'a' && arg[i] <= 'z')
            arg[i] -= 32;
        i++;
    }
    cout << arg;
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    else
    {
        i = 1;
        while (argv[i])
        {
            set_upper_case(argv[i]);
            i++;
        }
        cout << endl;
    }

    return (0);
}
