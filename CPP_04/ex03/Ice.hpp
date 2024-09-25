#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice();
		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
