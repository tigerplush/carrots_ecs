#ifndef CARROTS_ECS_SCHEDULE_SCHEDULE_LABEL_HPP_
#define CARROTS_ECS_SCHEDULE_SCHEDULE_LABEL_HPP_

namespace CarrotsEcs
{
    namespace Schedule
    {
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