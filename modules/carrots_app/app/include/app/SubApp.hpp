#ifndef CARROTS_APP_APP_SUB_APP_HPP_
#define CARROTS_APP_APP_SUB_APP_HPP_

#include <functional>

#include "option/Option.hpp"
#include "IApp.hpp"

namespace CarrotsApp
{
    namespace App
    {
        class SubApp : public IApp
        {
        public:
            void update() override;
        public:
            void add_system(std::function<void()> system);
        };
    } // namespace App
} // namespace CarrotsApp

#endif