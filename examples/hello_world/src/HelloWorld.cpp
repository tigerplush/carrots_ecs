#include "Carrots.hpp"

#include "DefaultLogSubscriber.hpp"

#include <iostream>

using namespace Carrots::Prelude;

void hello_world()
{
    std::cout << "Hello World!";
}

int main()
{
    Tracing::DefaultLogSubscriber::get_instance().set_filter("carrots_app::app=TRACE");
    return App::create().add_system(Startup, hello_world).run();
}