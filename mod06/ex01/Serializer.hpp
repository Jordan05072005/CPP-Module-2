#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// # include <cstdint>
# include <string>
# include <iostream>
typedef unsigned long uintptr_t;

struct Data
{
	std::string d1;
	int d2;
};


class Serializer{
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif