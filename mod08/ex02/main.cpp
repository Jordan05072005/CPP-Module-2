#include "MutantStack.hpp"
#include "MutantStack.tpp"

#include <vector>

int main()
{
std::vector<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << mstack.back() << std::endl;
mstack.pop_back();
std::cout << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
//[...]
mstack.push_back(0);
std::vector<int>::iterator it = mstack.begin();
std::vector<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
// std::stack<int> s(mstack);



std::cout << "\n et \n" << std::endl;


MutantStack<int> mstack2;
mstack2.push(5);
mstack2.push(17);
std::cout << mstack2.top() << std::endl;
mstack2.pop();
std::cout << mstack2.size() << std::endl;
mstack2.push(3);
mstack2.push(5);
mstack2.push(737);
mstack2.push(0);
MutantStack<int>::iterator it2 = mstack2.begin();
MutantStack<int>::iterator ite2 = mstack2.end();
++it2;
--it2;
std::cout << "stack : " << std::endl;
while (it2 != ite2)
{
std::cout << *it2 << std::endl;
++it2;
}
std::cout << "end of stack" << std::endl << std::endl;
std::stack<int> s(mstack2);
MutantStack<int>::reverse_iterator it3;
MutantStack<int>::const_reverse_iterator it4;
MutantStack<int>::const_iterator it5;
it3 = mstack2.rbegin();
it5 = mstack2.cbegin();
it4 = mstack2.crbegin();
std::cout << *it3 << " et " <<  *it4 << " et " << *it5 << std::endl;

return 0;
}