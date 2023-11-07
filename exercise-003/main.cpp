#include <fmt/chrono.h>
#include <fmt/format.h>

#include "vectorint.hpp"
#include "iostream"

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, World!\n");

    /* INSERT YOUR CODE HERE */
    VectorInt data(20);
    data.push_back(42);
    std::cout << data.size() << std::endl;
    // write some Data to the vector
    for(int i = 0; i < 18; i++){
        data.push_back(i);
    };    
    // print vector
    for(int i = 0; i < data.size(); i++){
        fmt::print(" {}: {}", i, data.at(i));
    };
    fmt::print("\n");

    // measure push back time with capacity change:
    auto start = std::chrono::system_clock::now();
    data.push_back(815);
    std::greater<uint32_t>();
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::print("push_back with capacity change took {}\n", elapsed);

    // measure push back time without capacity change:
    start = std::chrono::system_clock::now();
    data.push_back(815);
    std::greater<uint32_t>();
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::print("push_back without capacity change took {}\n", elapsed);

    // test resize function
    data.resize(42);
    fmt::print("new data size: {}\n", data.size());
    fmt::print("new capacity size: {}\n", data.max_size());

    // print vector
    for(int i = 0; i < data.size(); i++){
        fmt::print(" {}: {}", i, data.at(i));
    };
    return 0; /* exit gracefully*/
}
