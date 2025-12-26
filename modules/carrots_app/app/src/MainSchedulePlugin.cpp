#include "app/MainSchedulePlugin.hpp"

#include <Tracing.hpp>

#include "app/MainScheduleOrder.hpp"

namespace CarrotsApp
{
    namespace App
    {
        void MainSchedulePlugin::build(IApp &app)
        {
            TRACE << "Building MainSchedulePlugin";
            app.insert_resource(MainScheduleOrder::standard());
            TRACE << "Done building MainSchedulePlugin";
        }
    } // namespace App
} // namespace CarrotsApp