#ifndef CARROTS_APP_APP_SUB_APP_HPP_
#define CARROTS_APP_APP_SUB_APP_HPP_

#include <functional>

#include <CarrotsEcs.hpp>

#include "IApp.hpp"

namespace CarrotsApp
{
    namespace App
    {
        using ScheduleLabel = CarrotsEcs::ScheduleLabel;
        using World = CarrotsEcs::World::World;
        /// SubApps can be added to an app via `app.add_plugin(plugin)` API.
        /// Each plugin will then be built calling its `plugin.build()` function
        /// which in turn creates a subapp, that is added to the list of subapps
        /// of the main app.
        class SubApp : public IApp
        {
        public:
            void update() override;
            SubApp &add_plugin(IPlugin &&plugin) override;
            SubApp &add_system(ScheduleLabel label, std::function<void()> system) override;
        public:
            World &get_world() override;

        private:
            World m_world;
        };
    } // namespace App
} // namespace CarrotsApp

#endif