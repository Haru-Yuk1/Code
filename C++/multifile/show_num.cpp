#include<iostream>
#include "add_two_num.h"
void show_num(int& c, int& d)
{
    c=add_two_num(c,d);
    std::cout<<c<<std::endl;
}
