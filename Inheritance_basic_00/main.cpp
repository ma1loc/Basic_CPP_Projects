# include "ClapTrap.hpp"

int main()
{
    ClapTrap alice("Alice");
    ClapTrap bob("Bob");

	std::cout << "\n";
    
	alice.attack("Bob");
    bob.takeDamage(0);

	std::cout << "\n";
    
    alice.takeDamage(3);
    alice.beRepaired(2);

	std::cout << "\n";

	for (int i = 1; i <= 10; i++)
	{
		std::cout << "attack number -> " << i << ": ";
		alice.attack("unkown");
	}

	std::cout << "\n";
    
    for (int i = 1; i <= 10; i++)
	{
        std::cout << "attack number -> " << i << ": ";
        bob.attack("unknown");
    }

	std::cout << "\n";
    
    bob.attack("unkonwn");
    bob.beRepaired(5);

	std::cout << "\n";

    alice.takeDamage(15);
    alice.attack("unknown");
    alice.beRepaired(5);

	std::cout << "\n";
    
    ClapTrap charlie = alice;
    ClapTrap dave("Dave");
    dave = bob;

	std::cout << "\n";

	dave.attack("Unkonwn");
    
    return 0;
}
