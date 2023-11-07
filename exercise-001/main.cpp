#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"
#include "vector"
#include "random"

auto printvector(std::vector<int>& numbers)->void;

auto main(int argc, char **argv) -> int
{
    auto count{20};
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    int count = 20;
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, fmt::format("The amount of elements in our vector default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
   
    std::vector<int> numbers;

    for(int i = 0; i<count; i++){
        numbers.push_back(rand() % 100);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("    value of count: {}!\n", count);

    std::vector<uint32_t> data(count);
    fmt::print("    Number of elements in vector: {}!\n", data.size());

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;   // a seed source for the random number engine
    std::mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 100);
    
    std::for_each(data.begin(), data.end(), [&distrib, &gen](auto &n) { n = distrib(gen); });
    /*
    // Use a range based for loop to fill the vector
    for (auto& i : data) {
        i = distrib(gen);
    }
    */
    fmt::print("The vector:\n[{}]\n", fmt::join(data, ", "));
    auto start = std::chrono::system_clock::now();
    std::sort(data.begin(),data.end(),std::greater<uint32_t>());
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::print("The sorted vector:\n[{}]\n", fmt::join(data, ", "));
    fmt::print("The sorting took {}\n", elapsed);
    return 0; /* exit gracefully*/
}
auto printvector(std::vector<int>& numbers)-> void{
    for(auto& i : numbers){
        fmt::print("{}\n", i);
    }
}