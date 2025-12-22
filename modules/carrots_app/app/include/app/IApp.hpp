#ifndef CARROTS_APP_APP_I_APP_HPP_
#define CARROTS_APP_APP_I_APP_HPP_


namespace CarrotsApp
{
    namespace App
    {
        class IApp
        {
        public:
            virtual void update() = 0;
        };
    } // namespace App
} // namespace CarrotsApp

#endif