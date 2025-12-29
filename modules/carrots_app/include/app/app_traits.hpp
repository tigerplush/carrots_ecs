#ifndef CARROTS_APP_APP_I_APP_HPP_
#define CARROTS_APP_APP_I_APP_HPP_

#include <carrots_ecs.hpp>

#include "plugin/plugin.hpp"

namespace carrots_app
{
    namespace app
    {
        using IPlugin = carrots_app::plugin::IPlugin;
        using ComponentId = carrots_ecs::ComponentId;
        using ScheduleLabel = carrots_ecs::ScheduleLabel;
        using World = carrots_ecs::World;
        /// App interface
        ///
        /// Internally, plugins are basically AppBuilders.
        /// So if you add a plugin, the app will call `.build` on that plugin
        /// which will return a SubApp, that is added to the main apps list
        /// via this type erased interface.
        class IApp
        {
        public:
            virtual void update() = 0;
            /// Adds a system to a schedule.
            /// @param label 
            /// @param system 
            /// @return 
            virtual IApp &add_system(ScheduleLabel label, std::function<void()> system) = 0;
            virtual IApp &add_plugin(IPlugin &&plugin) = 0;
            /// Inserts a component before the first schedule is run
            ///
            /// This way a user can have Data ready at Startup.
            ///
            /// @tparam Component 
            /// @param component 
            /// @return 
            template<typename Component>
            IApp &insert_resource(Component &&component)
            {
                get_world().spawn(component);
                return *this;
            }
        protected:
            virtual World &get_world() = 0;
        };
    } // namespace app
} // namespace carrots_app

#endif