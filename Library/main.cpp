// Library.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.hpp"
#include <array>
#include <algorithm>

int main()
{
	std::array<int, 10> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	std::cout << "Array before: "; std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << "\n";

	auto it = std::upper_bound(a.begin(), a.begin(), 0);
	auto nxt = std::next(it);

	std::cout << "upper_bound returns " << *it << " and next returns " << *nxt << "\n";

	std::rotate(a.begin(), a.begin() + 5, a.end());

	std::cout << "Array after: "; std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << "\n";

    return 0;
}

