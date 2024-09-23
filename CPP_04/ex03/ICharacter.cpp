#include "ICharacter.hpp"

std::ostream &operator<<(std::ostream &o, const ICharacter &character) {
	o << character.getName();
	return (o);
}
