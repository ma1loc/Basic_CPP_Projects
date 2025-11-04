# ifndef WHATEVER_HPP
# define WHATEVER_HPP

// NOTES
// >>>>>>>>>>>>>>>>>>>>>>>>>>> Understanding template function <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// >>> templates is just a placeholder types,  A placeholder type represents
    //  some type that is not known at the time the template is defined
    //  but that will be provided later (when the template is used).

// >>> Once a template is defined, the compiler can use the template to generate
    //  as many overloaded functions (or classes) as needed, each using different actual types!
    //  Templates automatically produce “overloads” for each type you actually use.

    // template <typename T>   // this is the syntax of template function
    // void ma1loc(T aa);  and this function called instantiated functions
        //  just take template as param
        //  that mean's the compiler create Instantiated function for that type pasd as param
        //  exmple: void ma1loc(int aa), void ma1loc(int aa) .... overloding funciton
        //  ---> overloding funciton that compiler created == instantiated functions
    // we can create a one place older of same time more then one
    // but one place holder it can not hold (int, float) an error will happen

// why i most define and not just declare the templete in the headerfile?

template <typename T>
void swap(T &value_1, T &value_2)
{
    T tmp = value_1;
    value_1 = value_2;
    value_2 = tmp;
}

template <typename T>
T min(T value_1, T value_2)
{
    if (value_1 < value_2)
        return (value_1);
    return (value_2);
}

template <typename T>
T max(T value_1, T value_2)
{
    if (value_1 > value_2)
        return (value_1);
    return (value_2);
}

# endif