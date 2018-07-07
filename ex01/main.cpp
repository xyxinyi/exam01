#include <iostream>
#include "marine.h"

int main()
{
marine m2("Jim", 23, 56);
marine m3 = m2;
std::cout << m3 << std::endl;
m3 -= 7;
std::cout << m3 << std::endl;
m3 += 8;
std::cout << m3 << std::endl;
m3.move(6, 8);
std::cout << m3 << std::endl;
m3.stimpack();
std::cout << m3 << std::endl;
}
