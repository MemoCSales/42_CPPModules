#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


/*
	The MateriaSource class is designed to manage a small collection of learned 
	Materias (up to 4) and create new instances of these learned Materias when 
	requested.
*/
class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materiaTemplates[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();
		// Getters
		AMateria* getMateriaSource(int idx) const;
		// Methods
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
