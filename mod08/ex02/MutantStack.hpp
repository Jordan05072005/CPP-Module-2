#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <stack>
# include <iostream>


template <typename T>
class MutantStack : public std::stack<T>{
	public:
		typedef typename  std::deque<T>::iterator iterator;
		typedef typename  std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename  std::deque<T>::const_iterator const_iterator;
		typedef typename  std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_iterator cbegin();
		const_iterator cend();
		const_reverse_iterator crbegin();
		const_reverse_iterator crend();
};

// template <typename T>
// std::ostream& operator<<(std::ostream& os, typename MutantStack<T>::iterator ms);

// template <typename Iter,
//           typename = typename std::iterator_traits<Iter>::value_type>
// std::ostream& operator<<(std::ostream& os, Iter it) {
//     // Attention : si *it n'est pas imprimable (pas d'operator<< pour value_type),
//     // la compilation échouera ici.
//     os << *it;
//     return os;
// }

#endif