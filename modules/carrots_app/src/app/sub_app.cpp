#include "app/sub_app.hpp"

namespace carrots_app
{
    namespace app
    {
        void SubApp::update()
        {
        }
        
        SubApp &SubApp::add_schedule(Schedule schedule)
        {
            return *this;
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

        void SubApp::run_default_schedule()
        {
            if(update_schedule.is_some())
            {
                // m_world.run_schedule(update_schedule.unwrap());
            }
        }
    } // namespace app
} // namespace carrots_app
