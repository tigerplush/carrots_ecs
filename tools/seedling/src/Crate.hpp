#ifndef SEEDLING_CRATE_HPP_H_
#define SEEDLING_CRATE_HPP_H_

#include <CLI/CLI.hpp>

namespace crate
{
    struct CrateOptions
    {
        std::string name;
        std::string path;
        std::string module_name;
    };
    void create_subcommand(CLI::App &app);
    void run_crate_command(CrateOptions const &options);
    std::string replaceAll(std::string string, const std::string &from, const std::string &to);
    std::string CMakeListsContent();
    std::string HeaderContent();
    std::string TestsContent();
}

#endif