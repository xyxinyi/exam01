#ifndef MARINE_H_
#define MARINE_H_

#include "unit.h"
#include <iostream>
#include <string>

class marine : public unit
{
	public:
		marine(void);
		marine(std::string const &name,int x, int y);
		marine(marine const &src);
		virtual ~marine(void);

		virtual void die(void);
		virtual void move(int x, int y);

		void stimpack(void);

		marine &operator=(marine const &rhs);

	protected:

	private:
};

#endif
