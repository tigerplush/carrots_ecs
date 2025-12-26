#include "app/MainSchedulePlugin.hpp"

#include <iostream>

namespace CarrotsApp
{
    namespace App
    {
        void MainSchedulePlugin::build(IApp &app)
        {
            std::cout << "main schedule plugin added" << std::endl;
        }
    } // namespace App
} // namespace CarrotsApp