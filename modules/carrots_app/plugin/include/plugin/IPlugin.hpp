#ifndef CARROTS_APP_PLUGIN_I_PLUGIN_HPP_
#define CARROTS_APP_PLUGIN_I_PLUGIN_HPP_

namespace CarrotsApp
{
    namespace App
    {
        // Forward declaration of interface
        class IApp;
    }
    namespace Plugin
    {

        /// Interface for plugins.
        class IPlugin
        {
        public:
            virtual void build(App::IApp &app) = 0;
        };
    } // namespace Plugin
} // namespace CarrotsApp

#endif