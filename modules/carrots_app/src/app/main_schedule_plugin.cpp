#include "app/main_schedule_plugin.hpp"

#include <Tracing.hpp>

#include "app/main_schedule_order.hpp"

namespace carrots_app
{
    namespace app
    {
        using Schedule = carrots_ecs::Schedule;
        MODULE("carrots_app::app")
        void MainSchedulePlugin::build(IApp &app)
        {
            TRACE << "Building MainSchedulePlugin";
            Schedule main(Main);
            app
                .add_schedule(main)
                .insert_resource(MainScheduleOrder::preset())
                .add_system(Main, run_main);
            TRACE << "Done building MainSchedulePlugin";
        }

        void run_main()
        {

        }
    } // namespace app
} // namespace carrots_app