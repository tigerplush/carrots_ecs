#include "Carrots.hpp"

#include <iostream>

using namespace Carrots::Prelude;

void hello_world()
{
    std::cout << "Hello World!";
}

int main()
{
    return App::create().add_system(Startup, hello_world).run();
}