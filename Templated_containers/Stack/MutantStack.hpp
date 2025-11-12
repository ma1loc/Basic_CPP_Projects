# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class Mutantstack: public std::stack
{
	private:
		// TODO; >>>> LATTER ON
	public:
		Mutantstack();
		Mutantstack(const Mutantstack<T> &copy);
		Mutantstack<T> &operator=(const Mutantstack<T>  &copy);
		~Mutantstack();

}
