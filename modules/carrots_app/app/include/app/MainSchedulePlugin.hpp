#ifndef CARROTS_APP_MAIN_SCHEDULE_PLUGIN_HPP_
#define CARROTS_APP_MAIN_SCHEDULE_PLUGIN_HPP_

#include <CarrotsEcs.hpp>

#include "IApp.hpp"
#include "plugin/Plugin.hpp"

namespace CarrotsApp
{
    namespace App
    {
        using IPlugin = CarrotsApp::Plugin::IPlugin;
        class MainSchedulePlugin : public IPlugin
        {
        public:
            void build(IApp &app) override;
        };
    } // namespace App
} // namespace CarrotsApp


#endif