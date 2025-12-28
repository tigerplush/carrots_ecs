#include "Crate.hpp"

#include <carrots_std.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>

using namespace carrots_std;

namespace crate
{
    void create_subcommand(CLI::App &app)
    {
        std::shared_ptr<CrateOptions> options = std::make_shared<CrateOptions>();
        CLI::App *crate = app.add_subcommand("crate", "Creates a new cmake crate");
        crate->add_option("-n,--name", options->name, "Name of the new crate")->required();
        crate->add_option("-p,--path", options->path, "Path of the new crate")->required();
        crate->add_option("-m,--module", options->module_name);
        crate->callback([options]()
                        { run_crate_command(*options); });
    }

    void run_crate_command(CrateOptions const &options)
    {
        StringIterator name(options.name);
        std::string lowercase_name = name.to_lowercase();
        std::string uppercase_name = name.to_uppercase();
        StringIterator module_name(options.module_name);
        std::vector<std::string> folder_structure = {
            options.path + "/" + lowercase_name + "/include/" + lowercase_name,
            options.path + "/" + lowercase_name + "/src",
            options.path + "/" + lowercase_name + "/tests"};

        for (const std::string &path : folder_structure)
        {
            std::cout << path << std::endl;
            std::filesystem::create_directories(path);
        }
        std::vector<std::string> filenames = {
            options.path + "/" + lowercase_name + "/include/" + lowercase_name + "/" + options.name + ".hpp",
            options.path + "/" + lowercase_name + "/tests/" + options.name + "Tests.cpp",
            options.path + "/" + lowercase_name + "/CMakeLists.txt"
        };
        std::vector<std::string> file_contents = {
            HeaderContent(),
            TestsContent(),
            CMakeListsContent()
        };
        for(std::string &content: file_contents)
        {
            content = replaceAll(content, "{lowercase_name}", lowercase_name);
            content = replaceAll(content, "{uppercase_name}", uppercase_name);
            content = replaceAll(content, "{name}", options.name);
            content = replaceAll(content, "{module_name}", options.module_name);
        }
        for(size_t index = 0; index < filenames.size(); index++)
        {
            std::ofstream file(filenames[index]);
            file << file_contents[index];
            file.close();
        }
    }

    std::string replaceAll(std::string string, const std::string &from, const std::string &to)
    {
        size_t pos = string.find(from);
        while (pos != std::string::npos)
        {
            string.replace(pos, from.length(), to);
            pos = string.find(from, pos + to.length());
        }
        return string;
    }

    std::string CMakeListsContent()
    {
        return R"(add_library({lowercase_name} STATIC
    src/{name}.cpp
)

target_sources({lowercase_name}
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/{lowercase_name}/{name}.hpp
)

target_link_libraries({lowercase_name}
    PUBLIC
)

set_target_properties({lowercase_name} PROPERTIES FOLDER "modules/carrots_std/{lowercase_name}")

# Tests
add_executable({lowercase_name}_tests
    tests/{name}Tests.cpp
)

target_link_libraries({lowercase_name}_tests
    PRIVATE
        GTest::gtest_main
        {lowercase_name}
)

include(GoogleTest)
gtest_discover_tests({lowercase_name}_tests))";
    }

    std::string HeaderContent()
    {
        return R"(#ifndef {module_define}_{uppercase_name}_{uppercase_name}_HPP_
#define {module_define}_{uppercase_name}_{uppercase_name}_HPP_

namespace {module_name}
{
    namespace {name}
    {

    } // namespace {name}
} // namespace {module_name}

#endif)";
    }

    std::string TestsContent()
    {
        return R"(#include <gtest/gtest.h>
#include "{lowercase_name}/{name}.hpp"

using namespace {module_name}::{name};

TEST({name}Test, {name})
{
})";
    }
}