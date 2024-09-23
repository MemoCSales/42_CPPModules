#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure();
		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif