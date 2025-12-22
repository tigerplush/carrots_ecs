#ifndef CARROTS_APP_APP_APP_HPP_
#define CARROTS_APP_APP_APP_HPP_

#include <functional>

#include "option/Option.hpp"
#include "IApp.hpp"
#include "SubApps.hpp"

namespace CarrotsApp
{
    namespace App
    {
        using namespace CarrotsStd::Option;
        class App : public IApp
        {
        public:
            using RunnerFn = std::function<size_t(App&)>;
        public:
            static App create();
        public:
            void update() override;
        public:
            App &add_system(std::function<void()>);
            size_t run();
            Option<size_t> should_exit();
        private:
            static App empty();
        private:
            explicit App(RunnerFn m_runner);
        private:
            SubApps m_sub_apps;
            RunnerFn m_runner;
        };

        size_t run_once(App &app);
    } // namespace App
} // namespace CarrotsApp

#endif