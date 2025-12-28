#include "Carrots.hpp"

#include <iostream>

using namespace Carrots::prelude;

void hello_world()
{
    std::cout << "Hello World!";
}

int main()
{
    return App::create().run();
}