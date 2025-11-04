#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &p1, int p2){
	typename T::iterator it;

	it = std::find(p1.begin(), p1.end(), p2);
	if (it == p1.end()){
		throw OccurenceNotFind();
	}
	return (it);
}
