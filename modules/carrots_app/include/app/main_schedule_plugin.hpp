#ifndef CARROTS_APP_MAIN_SCHEDULE_PLUGIN_HPP_
#define CARROTS_APP_MAIN_SCHEDULE_PLUGIN_HPP_

#include <carrots_ecs.hpp>

#include "app_traits.hpp"
#include "plugin/plugin.hpp"

namespace carrots_app
{
    namespace app
    {
        using IPlugin = carrots_app::plugin::IPlugin;
        class MainSchedulePlugin : public IPlugin
        {
        public:
            void build(IApp &app) override;
        };
    } // namespace app
} // namespace carrots_app


#endif