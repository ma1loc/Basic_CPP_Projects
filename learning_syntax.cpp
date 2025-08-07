# include <iostream>

using namespace std;

// >>> create a namespace
namespace	first_space
{
	// the using std::cout/endl is just privet use just for the namespace only?
	using std::cout;	// cout is just a Linked to standard output?
	using std::endl;	// but endl is a function?

	// >>> here i can create functions, variables, typedef...
	void	sayHey()
	{
		cout << "Hello Guys!!!" << endl;
		exit(0);
	}
}

int	main()
{
	// cout << "hello world!!!" << endl; error no access to the member of the namespace
	// first_space::sayHey; why this have an error?
	first_space::sayHey();
	return (0);
}