#include "app/SubApp.hpp"

namespace CarrotsApp
{
    namespace App
    {
        void SubApp::update()
        {
        }

        void SubApp::add_plugin(IPlugin &&plugin)
        {
            plugin.build(*this);
        }

        void SubApp::add_system(ScheduleLabel label, std::function<void()> system)
        {
        }
    } // namespace App
} // namespace CarrotsApp
