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

// ------------------------------------------------------------------------

int	ft_strdup()
{
	// string x = std::new;
	int *dup = new int;

	*dup = 11;

	std::cout << "before dup = " << *dup << endl;

	*dup = 22;

	delete dup;

	std::cout << "after free addr of dup -> " << *dup << endl;
	if (dup)
		return (2);
	return (*dup);
}

class learning_syntax
{
	public:
		static void	Say_hello()
		{
			std::cout << "hello" << std::endl;
		}
};


int	main()
{
	// char	*name_1;	//	-> not valid based on the logic added by the cpp, read-only value most have const before.
	const char	*name_1;
	string	name_2;		// to know about it?

	name_1 = "ma1loc 1";
	name_2 = "ma1loc 2";

	// cout << "hello world!!!" << endl; error no access to the member of the namespace
	first_space::sayHey();
	// ------------------------------------------------------------------	

	// cout << name_1 << endl;
	// cout << name_2 << endl;
	// cout << name_2.length() << endl;
	// cout << name_1 << endl;

	// -> you don't need to create a object to use the member of the class.
	// learning_syntax::Say_hello();
	// learning_syntax::Say_hello();
	
	// ------------------------------------------------------------------

	// new way to allocate 
	std::string dupp(10, '\0');

	dupp = "ma1loccc\n";
	delete dupp;
	std::cout << dupp << endl;

	// std::cout << ft_strdup() << std::endl;

	return (0);
}
