#ifndef ISCV_H
#define ISCV_H


class	IScv
{
	public:
		virtual ~IScv(void){}

		enum	building_e
		{
			COMMAND_CENTER = 1,
			BARRACKS,
			SUPPLY_DEPOT,
			BUNKER
		};

		virtual Building		*createBuilding(building_e building, int x, int y) = 0;

	protected:
		virtual Building		*_buildCommandCenter(int x, int y) = 0;
		virtual Building		*_buildBarracks(int x, int y) = 0;
		virtual Building		*_buildSupplyDepot(int x, int y) = 0;
		virtual Building		*_buildBunker(int x, int y) = 0;
};

#endif
