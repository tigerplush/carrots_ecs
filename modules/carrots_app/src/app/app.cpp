#include "app/app.hpp"

#include "app/main_schedule_plugin.hpp"

namespace carrots_app
{
    namespace app
    {
        App App::create()
        {
            return App::standard();
        }

        void App::update()
        {
            m_sub_apps.update();
        }

        App &App::add_plugin(IPlugin &&plugin)
        {
            plugin.build(*this);
            return *this;
        }

        App &App::add_system(ScheduleLabel label, std::function<void()> system)
        {
            m_sub_apps.get_main_app().add_system(label, system);
            return *this;
        }

        int App::run()
        {
            return static_cast<int>(m_runner(*this));
        }

        Option<size_t> App::should_exit()
        {
            return None;
        }

        World &App::get_world()
        {
            return m_sub_apps.get_main_app().get_world();
        }

        App App::empty()
        {
            return App(run_once);
        }

        App App::standard()
        {
            App app = App::empty();
            app.add_plugin(MainSchedulePlugin());
            return app;
        }

        App::App(RunnerFn t_runner)
        : m_runner(t_runner)
        {

        }

        size_t run_once(App &app)
        {
            return app.should_exit().unwrap_or(0);
        }
    } // namespace app
} // namespace carrots_app
