#ifndef CARROTS_ECS_SCHEDULE_SCHEDULES_HPP_
#define CARROTS_ECS_SCHEDULE_SCHEDULES_HPP_

#include <unordered_map>

#include "schedule_label.hpp"
#include "schedule.hpp"

namespace carrots_ecs
{
    namespace schedule
    {
        class Schedules
        {
        private:
            std::unordered_map<ScheduleLabel, Schedule> m_inner;
        };
    } // namespace Schedule
} // namespace carrots_ecs

#endif