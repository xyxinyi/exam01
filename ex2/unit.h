#ifndef UNIT_H_
#define UNIT_H_

# include <iostream>
# include <string>

class	unit
{
	public:
		unit(void);
		unit(std::string const &name, std::string const &type, int x, int y, int damage, int hp, int maxHp);
		unit(unit const &src);
		virtual ~unit(void);

		unit		&operator+=(int n);
		unit		&operator-=(int n);
		unit		&operator=(unit const &rhs);

		void		move(int x, int y);
		void		die(void);
		void		attack(unit &target) const;

		int			getIndex(void) const;
		std::string const &getName(void) const;
		std::string const &getType(void) const;
		int			getX(void) const;
		int			getY(void) const;
		int			getDam(void) const;
		int			getCHP(void) const;
		int			getMHP(void) const;

	protected:
		int			_index;
		std::string _Name;
		std::string	_type;
		int			_x;
		int			_y;
		int			_damage;
		int			_hp;
		int			_maxHp;
		bool		_die;

	private:
		static int		index;

		void			print_created(void) const;
};

std::ostream	&operator<<(std::ostream &o, unit const &unit);

#endif
