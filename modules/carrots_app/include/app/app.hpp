#ifndef CARROTS_APP_APP_APP_HPP_
#define CARROTS_APP_APP_APP_HPP_

#include <functional>

#include <CarrotsEcs.hpp>
#include <carrots_std.hpp>

#include "app_traits.hpp"
#include "sub_apps.hpp"

namespace carrots_app
{
    namespace app
    {
        using namespace carrots_std;
        using ScheduleLabel = CarrotsEcs::ScheduleLabel;
        /// An App brings together plugins and systems
        ///
        /// Create a new App with `App::create()`.
        ///
        /// Add systems to schedules with `.add_system(schedule, system)`.
        ///
        /// Add plugins to the app with `.add_plugin(plugin)`.
        ///
        /// At last, call `.run()` to run the app.
        ///
        /// # Remarks
        /// If you don't add any plugins, the App will be empty and run
        /// every schedule once before returning.
        class App : public IApp
        {
        public:
            using RunnerFn = std::function<size_t(App &)>;

        public:
            /// Creates an new app with some default structure to enable core engine features.
            /// This is the preferred constructor for most cases.
            /// @return
            static App create();

        public:
            void update() override;
            App &add_plugin(IPlugin &&plugin) override;
            /// Adds a system to a schedule.
            /// @param label
            /// @param system
            /// @return
            App &add_system(ScheduleLabel label, std::function<void()> system) override;

        public:
            /// Runs the app.
            ///
            /// If you don't add any plugins, this will run all schedules once.
            /// If you add the ScheduleRunnerPlugin, this will run indefinitely
            /// until either canceled by a user, a crash appears or some system
            /// sends the AppExit Message.
            /// @return
            size_t run();
            /// Returns `Some(exit code)`, when the App should exit,
            /// None otherwise.
            /// @return
            Option<size_t> should_exit();
        protected:
            World &get_world() override;

        private:
            /// Creates an empty app with a default runner
            /// that will run all schedules exactly once and
            /// then return
            /// @return
            static App empty();
            /// Creates an new app with some default structure to enable core engine features.
            /// This is the preferred constructor for most cases.
            /// @return
            static App standard();

        private:
            /// Creates an app with a given runner
            /// @param m_runner
            explicit App(RunnerFn m_runner);

        private:
            SubApps m_sub_apps;
            RunnerFn m_runner;
        };

        /// Helper to run all schedules exactly once
        /// and then return.
        /// @param app
        /// @return
        size_t run_once(App &app);
    } // namespace app
} // namespace carrots_app

#endif