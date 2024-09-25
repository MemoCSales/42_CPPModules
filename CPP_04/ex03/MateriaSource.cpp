#include "MateriaSource.hpp"

// ++++Constructor
MateriaSource::MateriaSource(void) {
	if (DEBUG) { 
		std::cout << "MateriaSource default constructor" << std::endl; 
	}
	for (int i = 0; i < 4; i++) {
		materiaTemplates[i] = NULL;
	}
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &other){
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
			if (materiaTemplates[i] != NULL) {
				delete materiaTemplates[i];
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
		if (materiaTemplates[i] != NULL) {
			delete materiaTemplates[i];
			materiaTemplates[i] = NULL;
		}
	}
}

// ****Methods
void MateriaSource::learnMateria(AMateria* materia) {
	if (materia == NULL)
		return ;
	for (int i = 0; i < 4; i++)	{
		if (materiaTemplates[i] == NULL) {
			materiaTemplates[i] = materia->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const  & type) {
	if (type.empty())
		return NULL;
	for (int i = 0; i < 4; i++)	{
		if (materiaTemplates[i] != NULL) {
			if (materiaTemplates[i]->getType() == type)	{
				return materiaTemplates[i]->clone();
			}
		}	
	}
	return NULL;
}
