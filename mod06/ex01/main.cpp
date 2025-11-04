#include "Serializer.hpp"


int main(){
	Data *d = new Data{"Gerome", 42};
	Data *p;
	
	p = Serializer::deserialize(Serializer::serialize(d));
	if (p == d)
		std::cout << "mouahaha" << std::endl;
	else
		std::cout << "aie" << std::endl;
	delete d;
}