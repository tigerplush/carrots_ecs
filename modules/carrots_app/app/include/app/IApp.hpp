#ifndef CARROTS_APP_APP_I_APP_HPP_
#define CARROTS_APP_APP_I_APP_HPP_


namespace CarrotsApp
{
    namespace App
    {
        /// App interface
        /// Internally, plugins are basically AppBuilders.
        /// So if you add a plugin, the app will call `.build` on that plugin
        /// which will return a SubApp, that is added to the main apps list
        /// via this type erased interface.
        class IApp
        {
        public:
            virtual void update() = 0;
        };
    } // namespace App
} // namespace CarrotsApp

#endif