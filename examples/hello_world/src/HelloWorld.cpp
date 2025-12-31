#include <carrots.hpp>

#include <tracing.hpp>

using namespace carrots::prelude;

void hello_world()
{
    INFO << "Hello World!";
}

int main()
{
    tracing::DefaultLogSubscriber::get_instance().set_filter("carrots_app::app=TRACE,carrots_ecs::world=TRACE");
    return App::create().add_system(Startup, hello_world).run();
}