#ifndef CARROTS_ECS_SCHEDULE_SCHEDULE_LABEL_HPP_
#define CARROTS_ECS_SCHEDULE_SCHEDULE_LABEL_HPP_

namespace CarrotsEcs
{
    namespace Schedule
    {
        /// A label for Schedules.
        ///
        /// There are a few schedules that carrots will
        /// provide, but a user can create new schedules
        /// for their own purpose.
        class ScheduleLabel
        {
        public:
            explicit constexpr ScheduleLabel(
                const char* t_label
            ) : m_label(t_label)
            {
            }
        private:
            const char* m_label;
        };

        static constexpr ScheduleLabel DefaultSchedule("DEFAULT");
    } // namespace Schedule
} // namespace CarrotsEcs

#endif