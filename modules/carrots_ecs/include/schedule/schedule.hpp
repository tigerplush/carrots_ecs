#ifndef CARROTS_ECS_SCHEDULE_SCHEDULE_HPP_
#define CARROTS_ECS_SCHEDULE_SCHEDULE_HPP_

#include "schedule_label.hpp"

namespace carrots_ecs
{
    namespace schedule
    {
        class Schedule
        {
        public:
            Schedule(ScheduleLabel t_label) : m_label(t_label){}
        private:
            ScheduleLabel m_label;
        };
    } // namespace Schedule
} // namespace carrots_ecs

#endif