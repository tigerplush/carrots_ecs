#ifndef CARROTS_APP_APP_SUB_APPS_HPP_
#define CARROTS_APP_APP_SUB_APPS_HPP_

#include <vector>

#include "SubApp.hpp"

namespace CarrotsApp
{
    namespace App
    {
        class SubApps
        {
        public:
            SubApp &get_main_app()
            {
                return m_main_app;
            }

            void update()
            {
                m_main_app.update();
                for(SubApp &sub_app: m_sub_apps)
                {
                    sub_app.update();
                }
            }
        private:
            SubApp m_main_app;
            std::vector<SubApp> m_sub_apps;
        };
    } // namespace App
} // namespace CarrotsApp

#endif