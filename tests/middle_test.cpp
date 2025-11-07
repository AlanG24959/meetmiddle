#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/middle.hpp"
#include <fstream>
#include <string>

void createCSV(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

TEST_CASE("Median of odd number of elements") {
    Array arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    REQUIRE(findMedian(arr) == 3);
}

TEST_CASE("Median of even number of elements") {
    Array arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    REQUIRE(findMedian(arr) == 5);
}

TEST_CASE("Load CSV and find median") {
    std::string filename = "test_data.csv";
    createCSV(filename, "1,2,6,8,9,11,27,45,71,90,104");

    Array arr;
    REQUIRE(loadDataFromFile(filename, arr) == true);
    REQUIRE(arr.getSize() == 11);
    REQUIRE(findMedian(arr) == 11);
}

TEST_CASE("Empty CSV file") {
    std::string filename = "empty.csv";
    createCSV(filename, "");

    Array arr;
    REQUIRE(loadDataFromFile(filename, arr) == true);
    REQUIRE(arr.getSize() == 0);
    REQUIRE(findMedian(arr) == 0);
}