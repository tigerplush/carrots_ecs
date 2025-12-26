#include "app/SubApp.hpp"

namespace CarrotsApp
{
    namespace App
    {
        void SubApp::update()
        {
        }

        SubApp &SubApp::add_plugin(IPlugin &&plugin)
        {
            plugin.build(*this);
            return *this;
        }

        SubApp &SubApp::add_system(ScheduleLabel label, std::function<void()> system)
        {
            return *this;
        }

        World &SubApp::get_world()
        {
            return m_world;
        }
    } // namespace App
} // namespace CarrotsApp
