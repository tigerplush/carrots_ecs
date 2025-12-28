#include "app/main_schedule_plugin.hpp"

#include <Tracing.hpp>

#include "app/main_schedule_order.hpp"

namespace carrots_app
{
    namespace app
    {
        void MainSchedulePlugin::build(IApp &app)
        {
            TRACE << "Building MainSchedulePlugin";
            app.insert_resource(MainScheduleOrder::standard());
            TRACE << "Done building MainSchedulePlugin";
        }
    } // namespace app
} // namespace carrots_app