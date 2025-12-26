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
        /// SubApps can be added to an app via `app.add_plugin(plugin)` API.
        /// Each plugin will then be built calling its `plugin.build()` function
        /// which in turn creates a subapp, that is added to the list of subapps
        /// of the main app.
        class SubApp : public IApp
        {
        public:
            void update() override;
        public:
            void add_system(ScheduleLabel label, std::function<void()> system);
        };
    } // namespace App
} // namespace CarrotsApp

#endif