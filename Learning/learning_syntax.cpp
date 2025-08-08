# include <iostream>

using namespace std;

// >>> create a namespace
namespace	first_space
{
	// the using std::cout/endl is just privet use just for the namespace only?
	using std::cout;	// cout is just a Linked to standard output?
	using std::endl;	// but endl is a function?

	/*
	>>> Not allowed in the namespace
		int age;
		age = 22
	*/


	int age = 22;	
	// >>> here i can create functions, variables, typedef...
	void	sayHey()
	{
		// >>> '<<' an operator can get one argument at the time
		cout << "Hello Guys!!! " << "i'm " << age << " years old" << endl;
	}
}

int	main()
{
	// cout << "hello world!!!" << endl; error no access to the member of the namespace
	// first_space::sayHey; why this have an error?
	first_space::sayHey();
	// first_space::sayHey();
	return (0);
}
