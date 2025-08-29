# include <iostream>

// using namespace std;

/*
	class is for build the use type by a blueprint of the class
	class has members inside
		function -> called methodes
		vars -> called attributes
	class give a object/instance
	what is constructor?
	what is diffrence between constructor and function?
	constructor overloading
	about the constructor:
		constructor is a function inside a class that have no return
		it can be a constructor overloading
		constructor is a function that run we creating an object
			like; first_class test; -> you creating an object
	about public, privet flags
		public ->  visible from anywhere
		privet -> hidden from outside

*/


class first_class
{
	// body is just for attributes
	// int i = 5;
	
	public:	// -> flag
		first_class(){	// -> constructor is run auto we declare an object
			std::cout << 5 << std::endl;
		}
};

int main()
{
	first_class hello;
	std::cout << "hello" << std::endl;

	return (0);
}