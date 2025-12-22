#include <CLI/CLI.hpp>

#include "Crate.hpp"

int main(int argc, char** argv) {
    CLI::App app{"Seedling is a command line interface to help carrots grow"};
    argv = app.ensure_utf8(argv);

    crate::create_subcommand(app);
    CLI11_PARSE(app, argc, argv);
    return 0;
}