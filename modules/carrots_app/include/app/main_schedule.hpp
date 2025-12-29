#ifndef CARROTS_APP_MAIN_SCHEDULE_HPP_
#define CARROTS_APP_MAIN_SCHEDULE_HPP_

#include <carrots_ecs.hpp>

namespace carrots_app
{
    namespace app
    {
        using ScheduleLabel = carrots_ecs::ScheduleLabel;
        /// Default Schedule for Startup. Will be called once at startup.
        static constexpr ScheduleLabel Startup("STARTUP");
        /// Default Schedule for Update. Will be called once every frame.
        static constexpr ScheduleLabel Update("UPDATE");
    } // namespace app
} // namespace carrots_app


#endif