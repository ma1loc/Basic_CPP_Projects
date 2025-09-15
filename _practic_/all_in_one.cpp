# include <iostream>
# include <vector>
# include <utility>

// // ---------------------- vector --------------------- //

// // what is vector?
// /*
//     is a dynamic type like the arry with a fixed type
//     and is not index based it can be re-size with it's
//     methodes like: .push_back() method
// */

// void test_vectore()
// {
//     int arry1[] = {10, 20, 30, 40};
//     int arry2[] = {50, 60, 70, 80, 90};

//     size_t amount1 = (sizeof(arry1) / sizeof(arry1[0]));
//     size_t amount2 = (sizeof(arry2) / sizeof(arry2[0]));

//     std::vector<int> number1(arry1, arry1 + amount1);;
//     std::vector<int> number2(arry2, arry2 + amount2);;
//     std::vector<int> number3(10, 111);

//     // for (size_t i = 0; i < amount1; i++)
//     // std::cout << "number1.size()   " << number1.size() << std::endl;
//     for (size_t i = 0; i < number1.size(); i++)
//         std::cout << number1.at(i) << " ";
//     std::cout << "\n";
//     // for (size_t i = 0; i < amount2; i++)
//     for (size_t i = 0; i < number2.size(); i++)
//         std::cout << number2.at(i) << " ";
//     std::cout << "\n";
//     for (size_t i = 0; i < number3.size(); i++)
//         std::cout << number3.at(i) << " ";
// }


// // // ---------------------- pair --------------------- //

// // // what is pair?
// // /*
// //    pair is a continer, template class are used to group two type of elements(template argumant)
// //    with deffrent type in one and access them with .first method and .second to access
// //    the second
// // */

// void    test_pair()
// {

//     std::pair<std::string, int> student;

//     student.first = "youness";
//     student.second = 23;

//     std::cout << "name: " << student.first
//         << " age: " << student.second << std::endl;
// }

// // // ---------------------- iterator --------------------- //

// // // what is iterator?
// // /*
// //     iterator is a pointer or the position in a continers (like:vector)
// //     syntax -> continer<type>::iterator it;
// //     diff between iterator and pointer?
// //     done a task with it
// // */

// void    test_iterator()
// {
//     int amount;
//     int arry[] = {10, 20, 30, 40};
//     typedef std::vector<int>::iterator ite;
    
//     amount = (sizeof(arry) / sizeof(arry[0]));
//     std::vector<int> number(arry, arry + amount);

//     // std::cout << "-> " << number.begin();   // print the iterator
//     std::cout << "-> " << *number.begin() << std::endl;  // derafrance the iterator
    
//     // auto it_begin = number.begin();
//     // auto it_begin2 = number.begin() + 2;

//     // std::vector<int>::iterator it_begin = number.begin();
//     // std::vector<int>::iterator it_begin2 = number.begin() + 2;

//     ite it_begin = number.begin();
//     ite it_begin2 = number.begin() + 2;

//     number.erase(it_begin, it_begin2);
    
//     std::cout << "_-> " << *number.begin() << std::endl;
//     std::cout << "-_> " << *(number.begin() + 1) << std::endl;

// }

// // // ---------------------------------------------------------- //

// class const_dest
// {
//     public:
//         int get_i();
//         const_dest();
//         ~const_dest();
//     private:
//         static int i;
    
// };

// const_dest::const_dest()
// {
//     std::cout << "strart\n";
// }

// const_dest::~const_dest()
// {
//     std::cout << "end\n";
// }

// int    const_dest::get_i()
// {
//     return (i);
// }

// // ---------------------------------------------------------- //
// //                  about the refrance in class


// class name
// {
//     public:
//         name();
//         std::string str_name;
//         void    set_name(std::string set_name);
//         std::string get_name();
//     private:
//         const std::string str;
//         // std::string &str;
// };

// void name::set_name(std::string name)
// {
//     this->str_name = name;
// }

// std::string name::get_name()
// {
//     return (this->str);
// }

// name::name() : str(str_name) {};

// // int main() {
// //     name _name_;

// //     _name_.set_name("youness");
// //     std::cout << _name_.get_name() << std::endl;  // prints "youness"

// //     _name_.str_name = "another";
// //     std::cout << _name_.get_name() << std::endl;  // prints "another"
// // }


// // // ---------------------------------------------------------- //


// // int main()
// // {
// //     // const_dest  ob;
// //     // test_vectore();
// //     // test_pair();
// //     // test_iterator();
// //     // std::cout << "i ----> " << ob.get_i() << std::endl; 


// //     return (0);
// // }

// ---------------------------------------------------------- //
// about shallow copy --------------------------------------- //

// class Vector
// {
// 	public:
// 		Vector();
// 		int size;
// 		int *arry;
// 		Vector(const Vector &copy);
// 		~Vector();
// };

// Vector::Vector()
// {
// 	size = 10;
// 	arry = new int[size];
// 	for (int i = 0; i < size; i++)
// 		arry[i] = i + 99;
// }

// Vector::~Vector()
// {
// 	delete[] arry;
// 	arry = NULL;
// }

// Vector::Vector(const Vector &copy)
// {
// 	size = copy.size;
// 	arry = copy.arry;
// }

// int	main()
// {
// 	Vector a;
// 	Vector b(a);

// 	for (int i = 0; i < a.size; i++)
// 		std::cout << "i form a --> " << a.arry[i] << std::endl;

// 	for (int i = 0; i < b.size; i++)
// 		std::cout << "i form a --> " << b.arry[i] << std::endl;

// 	return (0);
// }