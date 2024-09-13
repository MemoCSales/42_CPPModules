#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return ;
}

// Parameter constructor
ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
	if (DEBUG)
		std::cout << "ClapTrap parameter constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	if (DEBUG)
		std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}


// Attack public member function
void ClapTrap::attack(const std::string& target) {
	std::cout << "👊 ClapTrap " << name << " (with " << energyPoints << " Energy Points - " << hitPoints << " Hit Points) -> ";
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << " attacks " << target << " || " << name << " now has: " << energyPoints << " energy points left!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has no Energy Points left!" << std::endl;
	}
}

// Take Damage member function
void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		if (amount > hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "🤖 ClapTrap " << name << " took " << amount << " points of damage.";
		std::cout << " ...now it has " << hitPoints << " hitPoints." << std::endl;
	} else
		std::cout << "😵 ClapTrap " << name << " has " << hitPoints << " and can no longer do anything. " << std::endl;
}

//Repairing member function
void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "🔋 ClapTrap " << name << " with (" << hitPoints << " Hit Points) -> ";
	if (hitPoints > 0 && energyPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		// if (hitPoints > MAX_HIT_POINTS)
		// 	hitPoints = MAX_HIT_POINTS;
		 std::cout << " repair itself with " << amount << " points.";
		std::cout << " ...it has now " << energyPoints << " points of energy." << std::endl;
	} else {
		std::cout << "😵 ClapTrap " << name << " has " << energyPoints << " and can no longer do anything. " << std::endl;
	}
}


// Setters
void	ClapTrap::setHitPoints(unsigned int _hp) {
	hitPoints = _hp;
}

void	ClapTrap::setEnergyPoints(int _energy) {
	energyPoints = _energy;
}

void	ClapTrap::setAttackDamage(int _damage) {
	attackDamage = _damage;
}

// Getters
std::string	ClapTrap::getName() const {
	return name;
}

unsigned int	ClapTrap::getHitPoints() const {
	return hitPoints;
}

int	ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return attackDamage;
}
