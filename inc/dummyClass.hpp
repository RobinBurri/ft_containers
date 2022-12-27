#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name; 
	
	public:
		Zombie(void);
		Zombie(std::string);
		virtual ~Zombie(void);
        Zombie &operator=(Zombie const &rhs);
		bool operator==(Zombie const &rhs) const;
		bool operator!=(Zombie const &rhs) const;
		void setName(std::string);
		std::string getName() const;
};

#endif