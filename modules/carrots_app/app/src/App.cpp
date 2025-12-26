#include "app/App.hpp"

#include "app/MainSchedulePlugin.hpp"

namespace CarrotsApp
{
    namespace App
    {
        App App::create()
        {
            return App::standard();
        }

        void App::update()
        {
            m_sub_apps.update();
        }

        void App::add_plugin(IPlugin &&plugin)
        {
            plugin.build(*this);
        }

        App &App::add_system(ScheduleLabel label, std::function<void()> system)
        {
            m_sub_apps.get_main_app().add_system(label, system);
            return *this;
        }
        size_t App::run()
        {
            return m_runner(*this);
        }

        Option<size_t> App::should_exit()
        {
            return None;
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
    } // namespace App
} // namespace CarrotsApp
