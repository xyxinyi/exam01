#include "scv.h"

scv::scv(void)
	: Unit("SCV T-280", 0, 0, 5, 60, 60), _res(0), _resType(Ressource::GAS)
{
	std::cout << "SCV ready to go, sir." << std::endl;
}

scv::scv(int x, int y)
	: Unit("SCV T-280", x, y, 5, 60, 60), _res(0), _resType(Ressource::GAS)
{
	std::cout << "SCV ready to go, sir." << std::endl;
}

scv::scv(scv const &src)
	: Unit(src), _res(0), _resType(Ressource::GAS)
{
	std::cout << "SCV ready to go, sir." << std::endl;
}

scv::~scv(void)
{
	std::cout << "* noise of an exploding SCV *" << std::endl;
}

void		scv::move(int x, int y)
{
	Unit::move(x, y);
	std::cout << "Unit #" << _index << ": Affirmative." << std::endl;
}

void		scv::gatherRessources(Ressource &ressource)
{
	Unit::move(ressource.getX(), ressource.getY());
	if (!ressource.isDepleted() && _res == 0)
	{
		_res = ressource.gather();
		_resType = ressource.type;
		std::cout << "Unit #" << _index << " (" << _type << ") gathered " << _res << ' ';
		if (ressource.type == Ressource::GAS)
			std::cout << "gas";
		else
			std::cout << "minerals";
		std::cout << '.' << std::endl;
	}
}

void		scv::returnRessources(CommandCenter &cc)
{
	Unit::move(cc.getX(), cc.getY());
	cc.acceptRessources(_resType, _res);
	std::cout << "Unit #" << _index << " (" << _type << ") returned " << _res << ' ';
	if (_resType == Ressource::GAS)
		std::cout << "gas" << '.' << std::endl;
	else
		std::cout << "minerals." << std::endl;
	_res = 0;
}

Building	*scv::createBuilding(building_e building, int x, int y)
{
	if (building < 1 || building > 4)
	{
		std::cout << "No such building, sir !" << std::endl;
		return (NULL);
	}
	return ((this->*builds[building - 1])(x, y));
}

Building	*scv::_buildCommandCenter(int x, int y)
{
	std::cout << "Command center finished, sir !" << std::endl;
	return (new CommandCenter(x, y));
}

Building	*scv::_buildBarracks(int x, int y)
{
	std::cout << "Barrack finished, sir !" << std::endl;
	return (new Barracks(x, y));
}

Building	*scv::_buildSupplyDepot(int x, int y)
{
	std::cout << "Supply depot finished sir !" << std::endl;
	return (new SupplyDepot(x, y));
}

Building	*scv::_buildBunker(int x, int y)
{
	std::cout << "Bunker finished sir !" << std::endl;
	return (new Bunker(x, y));
}

scv::t_build	scv::builds[4] = {&scv::_buildCommandCenter, &scv::_buildBarracks, &scv::_buildSupplyDepot, &scv::_buildBunker};

scv			&scv::operator=(scv const &rhs)
{
	Unit::operator=(rhs);
	_res = rhs._res;
	_resType = rhs._resType;
	return (*this);
}
