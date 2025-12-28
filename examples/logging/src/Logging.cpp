#include <carrots.hpp>

#include <iostream>

using namespace carrots::prelude;

void hello_world()
{
    std::cout << "Hello World!";
}

int main()
{
    return App::create().run();
}