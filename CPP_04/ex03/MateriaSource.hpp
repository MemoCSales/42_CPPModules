#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materiaTemplates[4];
	public:
		MateriaSource(void);
		~MateriaSource();
		// Methods
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource(void) {
	//do something here
}

MateriaSource::~MateriaSource() {
	// do something here
}



#endif