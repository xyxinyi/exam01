#include "unit.h"
#include <string>

unit::unit(void)
	: _index(++unit::index), _name(""), _type(""), _x(0), _y(0), _damage(0), _hp(0), _maxHp(0), _die(false)
{
	print_created();
}

unit::unit(std::string const &name,std::string const &type, int x, int y, int damage, int hp, int maxHp)
	: _index(++unit::index), _name(name), _type(type), _x(x), _y(y), _damage(damage), _hp(hp), _maxHp(maxHp), _die(false)
{
	print_created();
}

unit::unit(unit const &src)
{
	*this = src;
	_index = ++unit::index;
	print_created();
}

unit::~unit(void)
{
	/*std::cout << "[DESTRUCTED] Unit #" << _index << ": " << _type << " in " << _x;
	std::cout << '/' << _y << " with " << _hp << '/' << _maxHp << "HP damaging at " << _damage;
	std::cout << '.' << std::endl;*/
}

void unit::move(int x, int y)
{
	if (_die)
		return ;
	std::cout << "Unit #" << _index << " (" << _type << ") is moving from " << _x << '/' << _y;
	std::cout << " to " << x << '/' << y << '.' << std::endl;	
	_x = x;
	_y = y;
}

void unit::attack(unit &target) const
{
	if (_die)
		return ;
	std::cout << "Unit #" << _index << " (" << _type << ") damaged unit #" << target.getIndex();
	std::cout << " (" << target.getType() << ")." << std::endl;
	target -= _damage;
}

void unit::die(void)
{
	_hp = 0;
	_die = true;
	std::cout << "Unit #" << _index << " (" << _type << ") died." << std::endl;
}

int	unit::getIndex(void) const
{
	return (_index);
}

std::string const &unit::getName(void) const
{
	return (_name);
}

std::string const &unit::getType(void) const
{
	return (_type);
}

int unit::getX(void) const
{
	return (_x);
}

int unit::getY(void) const
{
	return (_y);
}

int unit::getDam(void) const
{
	return (_damage);
}

int unit::getCHP(void) const
{
	return (_hp);
}

int unit::getMHP(void) const
{
	return (_maxHp);
}

int	unit::index = -1;

unit &unit::operator+=(int n)
{
	_hp += n;
	if (_hp <= 0)
		die();
	else if (_hp > _maxHp)
		_hp = _maxHp;
	return (*this);
}

unit &unit::operator-=(int n)
{
	_hp -= n;
	if (_hp <= 0)
		die();
	else if (_hp > _maxHp)
		_hp = _maxHp;
	return (*this);
}

unit &unit::operator=(unit const &rhs)
{
	_name = rhs._name;
	_type = rhs._type;
	_x = rhs._x;
	_y = rhs._y;
	_damage = rhs._damage;
	_hp = rhs._hp;
	_maxHp = rhs._maxHp;
	_die = rhs._die;
	return (*this);
}

void unit::print_created(void) const
{
	/*std::cout << "[CREATED] Unit #" << _index << ": " << _type << " in ";
	    std::cout << _x << "/" << _y << " with " << _hp << "/" << _maxHp << "HP damaging at";
		    std::cout << " " << _damage << '.' << std::endl;*/
}

std::ostream &operator<<(std::ostream &o, unit const &u)
{   
    std::cout << u.getName() << " is a " << u.getType() << " in " << u.getX() << '/' << u.getY() << " with ";
    std::cout << u.getCHP() << '/' << u.getMHP() << "HP damaging at " << u.getDam();
    return (o);
}
