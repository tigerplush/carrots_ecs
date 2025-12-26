#ifndef CARROTS_APP_MAIN_SCHEDULE_HPP_
#define CARROTS_APP_MAIN_SCHEDULE_HPP_

#include "CarrotsEcs.hpp"

namespace CarrotsApp
{
    namespace App
    {
        using ScheduleLabel = CarrotsEcs::ScheduleLabel;
        static constexpr ScheduleLabel Startup("STARTUP");
        static constexpr ScheduleLabel Update("UPDATE");
    } // namespace App
} // namespace CarrotsApp


#endif