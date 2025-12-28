#ifndef CARROTS_APP_MAIN_SCHEDULE_ORDER_HPP_
#define CARROTS_APP_MAIN_SCHEDULE_ORDER_HPP_

#include <vector>

#include "main_schedule.hpp"

namespace carrots_app
{
    namespace app
    {
        class MainScheduleOrder
        {
        public:
            static MainScheduleOrder standard()
            {
                return MainScheduleOrder(
                    {
                        Update
                    },
                    {
                        Startup
                    }
                );
            }

        public:
            MainScheduleOrder(
                std::vector<ScheduleLabel> t_labels,
                std::vector<ScheduleLabel> t_startup_labels
            )
            : m_labels(t_labels)
            , m_startup_labels(t_startup_labels)
            {
            }

        private:
            std::vector<ScheduleLabel> m_labels;
            std::vector<ScheduleLabel> m_startup_labels;
        };
    } // namespace app
} // namespace carrots_app

#endif