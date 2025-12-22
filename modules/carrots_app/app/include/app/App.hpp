#ifndef CARROTS_APP_APP_APP_HPP_
#define CARROTS_APP_APP_APP_HPP_

#include <functional>

#include "option/Option.hpp"

namespace CarrotsApp
{
    namespace App
    {
        using namespace CarrotsStd::Option;
        class App
        {
        public:
            using RunnerFn = std::function<size_t(App&)>;
        public:
            static App create();
        public:
            size_t run();
            Option<size_t> should_exit();
        private:
            static App empty();
        private:
            explicit App(RunnerFn m_runner);
        private:
            RunnerFn m_runner;
        };

        size_t run_once(App &app);
    } // namespace App
} // namespace CarrotsApp

#endif