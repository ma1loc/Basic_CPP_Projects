# include "Serializer.hpp"


int main()
{
    Data my_name;
    uintptr_t _serializer;
    Data *_deserializer;

    // >>> another example
    // int *number = new int (66);
    // char *char_nbr = reinterpret_cast<char *>(number);
    // std::cout << *char_nbr << std::endl; delete number;

    my_name.Data = "ma1loc";
    _serializer = Serializer::serialize(&my_name);
    _deserializer = Serializer::deserialize(_serializer);

    std::cout << "===================== That values ====================="
            << "\n" << "Data my_name        -> " << my_name.Data
            << "\n" << "_serializer         -> " << _serializer
            << "\n" << "Data __deserializer -> " << _deserializer->Data
            << std::endl;
    
    std::cout << "\n===================== Change the _deserializer =====================\n";
    
    _deserializer->Data = "xxxxxx";
            
    std::cout << "\n" << "Data __deserializer   -> " << _deserializer->Data
            << "\n" << "Data my_name          -> " << my_name.Data << std::endl;


    std::cout << "\n===================== That addresses ====================="
            << "\n" << "Data my_name        -> " << &my_name.Data
            << "\n" << "Data __deserializer -> " << &_deserializer->Data
            << std::endl;

    return (0);
}