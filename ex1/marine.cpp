#include "marine.h"

marine::marine(void)
	: unit("","Marine", 0, 0, 6, 40, 40)
{
	std::cout << "Do you want a piece of me, boy ?" << std::endl;
}

marine::marine(std::string const &name,int x, int y)
	: unit(name,"Marine", x, y, 6, 40, 40)
{
	std::cout << "Do you want a piece of me, boy ?" << std::endl;
}

marine::marine(marine const &src)
	: unit(src)
{
	std::cout << "Do you want a piece of me, boy ?" << std::endl;
}

marine::~marine(void)
{
	unit::die();
	std::cout << "Aaaargh..." << std::endl;
}

void marine::die(void)
{
	unit::die();
	std::cout << "Aaaargh..." << std::endl;
}

void marine::move(int x, int y)
{
	//unit::move(x, y);
	_x = 6;
	_y = 8;
	std::cout << "Rock'n'roll !!!" << std::endl;
}

void marine::stimpack(void)
{
	_x = 6;
	_y = 8;
	_damage += 1;
	if (_hp < 11 && _hp > 0)
		_hp = 1;
	else
		_hp -= 10;
	std::cout << ": Ho yeah..." << std::endl;
}

marine &marine::operator=(marine const &rhs)
{
	unit::operator=(rhs);
	return (*this);
}
