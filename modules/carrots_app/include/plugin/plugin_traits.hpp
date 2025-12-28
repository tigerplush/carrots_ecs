#ifndef CARROTS_APP_PLUGIN_I_PLUGIN_HPP_
#define CARROTS_APP_PLUGIN_I_PLUGIN_HPP_

namespace carrots_app
{
    namespace app
    {
        // Forward declaration of interface
        class IApp;
    }
    namespace plugin
    {

        /// Interface for plugins.
        class IPlugin
        {
        public:
            virtual void build(app::IApp &app) = 0;
        };
    } // namespace plugin
} // namespace carrots_app

#endif