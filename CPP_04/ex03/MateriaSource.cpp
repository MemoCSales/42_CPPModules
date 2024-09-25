#include "MateriaSource.hpp"

// ++++Constructor
MateriaSource::MateriaSource(void) : materiaTemplates() {
	if (DEBUG) { 
		std::cout << "MateriaSource default constructor" << std::endl; 
	}
	for (int i = 0; i < 4; i++) {
		materiaTemplates[i] = NULL;
	}
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
	if (DEBUG) { 
		std::cout << "MateriaSource Copy Constructor called" << std::endl;
	}
	for (int i = 0; i < 4; i++) {
		if (other.materiaTemplates[i] != NULL) {
			this->materiaTemplates[i] = other.materiaTemplates[i]->clone();
		} else {
			this->materiaTemplates[i] = NULL;
		}	
	}
}

// Assignment Operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (DEBUG) { 
		std::cout << "MateriaSource assignment operator called" << std::endl;
	}
	if (this != &other)	{
		for (int i = 0; i < 4; i++)	{
			if (this->materiaTemplates[i] != NULL) {
				delete this->materiaTemplates[i];
			}
		}
		for (int i = 0; i < 4; i++)	{
			if (other.materiaTemplates[i] != NULL)	{
				this->materiaTemplates[i] = other.materiaTemplates[i]->clone();
			} else {
				this->materiaTemplates[i] = NULL;
			}
		}
	}
	return (*this);
}

AMateria* MateriaSource::getMateriaSource(int idx) const {
	if (idx < 0 || idx >= 4) {
		return NULL;
	}
	return materiaTemplates[idx];
}

// ----Destructor
MateriaSource::~MateriaSource() {
	if (DEBUG) { 
		std::cout << "MateriaSource destructor called" << std::endl;
	}
	for (int i = 0; i < 4; i++)	{
		if (this->materiaTemplates[i] != NULL) {
			delete this->materiaTemplates[i];
			this->materiaTemplates[i] = NULL;
		}
	}
}

// ****Methods
void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++)	{
		if (this->materiaTemplates[i] == NULL && materia != NULL) {
			this->materiaTemplates[i] = materia->clone();
			delete materia;
			return ;
		}
	}
	delete materia;
	std::cerr << "ERROR_LEARN_MATERIASOURCE" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const  & type) {
	if (type.empty())
		return NULL;
	for (int i = 0; i < 4; i++)	{
		if (this->materiaTemplates[i] != NULL && this->materiaTemplates[i]->getType() == type) {
				return this->materiaTemplates[i];
		}	
	}
	return NULL;
}
