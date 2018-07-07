#ifndef SCV_H
# define SCV_H

# include <iostream>
# include <string>

# include "unit.h"


class	scv : public Unit, public IBuilder
{
	public:
		scv(void);
		scv(int x, int y);
		scv(scv const &src);
		~scv(void);

		void		move(int x, int y);

		void		gatherRessources(Ressource &ressource);

		void		returnRessources(CommandCenter &cc);

		Building	*createBuilding(building_e building, int x, int y);

		scv			&operator=(scv const &rhs);

	protected:
		int			_res;
		Ressource::type_e	_resType;

		Building	*_buildCommandCenter(int x, int y);
		Building	*_buildBarracks(int x, int y);
		Building	*_buildSupplyDepot(int x, int y);
		Building	*_buildBunker(int x, int y);

	private:
		typedef Building	*(Scv::*t_build)(int, int);

		static Scv::t_build		builds[4];
};

#endif
