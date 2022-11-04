#include <iostream>

# define RED "\033[1;31m"
# define RESET "\033[0m"

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie( void );
		void announce( void );
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);