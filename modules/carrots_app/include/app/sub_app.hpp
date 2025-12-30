#ifndef CARROTS_APP_APP_SUB_APP_HPP_
#define CARROTS_APP_APP_SUB_APP_HPP_

#include <functional>

#include <carrots_std.hpp>
#include <carrots_ecs.hpp>

#include "app_traits.hpp"

namespace carrots_app
{
    namespace app
    {
        using namespace carrots_std;
        using ScheduleLabel = carrots_ecs::ScheduleLabel;
        using Schedule = carrots_ecs::Schedule;
        using World = carrots_ecs::World;
        /// SubApps can be added to an app via `app.add_plugin(plugin)` API.
        /// Each plugin will then be built calling its `plugin.build()` function
        /// which in turn creates a subapp, that is added to the list of subapps
        /// of the main app.
        class SubApp : public IApp
        {
        public:
            void update() override;
            SubApp &add_schedule(Schedule schedule) override;
            SubApp &add_plugin(IPlugin &&plugin) override;
            SubApp &add_system(ScheduleLabel label, std::function<void()> system) override;
        public:
            World &get_world() override;
        public:
            void run_default_schedule();
        public:
            Option<ScheduleLabel> update_schedule;
        private:
            World m_world;
        };
    } // namespace app
} // namespace carrots_app

#endif