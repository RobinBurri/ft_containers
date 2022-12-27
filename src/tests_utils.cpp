#include "../inc/dummyClass.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	return;
}

Zombie &Zombie::operator=(Zombie const &rhs) {
    if (this != &rhs)
    {
        this->_name = rhs._name;
    }
    return (*this);
}

bool Zombie::operator==(Zombie const &rhs) const {
	if (this->_name == rhs._name) 
	{
		return true;
	}
	return false;
}

bool Zombie::operator!=(Zombie const &rhs) const {
	if (this->_name == rhs._name) 
	{
		return false;
	}
	return true;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
	return;
}

std::string Zombie::getName() const 
{
	return this->_name;
}
