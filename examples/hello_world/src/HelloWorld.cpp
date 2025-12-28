#include "Carrots.hpp"

#include <tracing.hpp>

#include <iostream>

using namespace Carrots::Prelude;

void hello_world()
{
    std::cout << "Hello World!";
}

int main()
{
    tracing::DefaultLogSubscriber::get_instance().set_filter("carrots_app::app=TRACE,carrots_ecs::world=TRACE");
    return App::create().add_system(Startup, hello_world).run();
}