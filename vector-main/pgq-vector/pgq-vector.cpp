// Copyright 2022 Dmitriy <dimapermyakov55@gmail.com>

#include <gtest/gtest.h>

#include <stdexcept>
#include <vector-header.hpp>

TEST(vectorTest, AllTests) {
    vector<int> vec;
    vec.push_back(1);
    EXPECT_EQ(vec[0], 1);
    vec.reserve(1);
    vec.at(1) = 2;
    EXPECT_EQ(vec[1], 2);
    vec.clear();
    EXPECT_EQ(vec.empty(), true);

    // fill vector
    for (int i = 0; i < 5; ++i) {
        vec.push_back(1);
    }
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 1);
    EXPECT_EQ(vec[3], 1);
    EXPECT_EQ(vec[4], 1);
    auto it = vec.begin();
    for (; it != vec.end(); ++it) {
        *it = 3;
    }
    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 3);
    EXPECT_EQ(vec[4], 3);
    vec.clear();
    EXPECT_EQ(vec.empty(), true);

    // swap
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(9);
    vector<int> two(vec.size());
    EXPECT_EQ(two[0], 0);
    EXPECT_EQ(two[1], 0);
    EXPECT_EQ(two[2], 0);
    EXPECT_EQ(two[3], 0);
    EXPECT_EQ(two[4], 0);
    vec.swap(two);
    EXPECT_EQ(two[0], 1);
    EXPECT_EQ(two[1], 5);
    EXPECT_EQ(two[2], 4);
    EXPECT_EQ(two[3], 2);
    EXPECT_EQ(two[4], 9);
    EXPECT_EQ(vec[0], 0);
    EXPECT_EQ(vec[1], 0);
    EXPECT_EQ(vec[2], 0);
    EXPECT_EQ(vec[3], 0);
    EXPECT_EQ(vec[4], 0);

    // capacity + size
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.capacity(), 5);

    // pop
    EXPECT_EQ(two[0], 1);
    EXPECT_EQ(two[1], 5);
    EXPECT_EQ(two[2], 4);
    EXPECT_EQ(two[3], 2);
    EXPECT_EQ(two[4], 9);
    two.pop_back();
    EXPECT_EQ(two.at(0), 1);
    EXPECT_EQ(two.at(1), 5);
    EXPECT_EQ(two.at(2), 4);
    EXPECT_EQ(two.at(3), 2);

    // exception-range
    EXPECT_THROW(vec.at(200), std::out_of_range);
}

TEST(NewTest, Test) {
    vector<double> vec;
    vec.push_back(1.1);
    vec.push_back(2.1);
    vec.push_back(3.2);
    vec.push_back(4.2);
    vec.push_back(5.6);
    EXPECT_EQ(vec[0], 1.1);
    EXPECT_EQ(vec[1], 2.1);
    EXPECT_EQ(vec[2], 3.2);
    EXPECT_EQ(vec[3], 4.2);
    EXPECT_EQ(vec[4], 5.6);
    vec.insert(2, 777.7);
    EXPECT_EQ(vec[2], 777.7);
    EXPECT_EQ(vec[0], *vec.data());
    EXPECT_EQ(vec[0], vec.front());
}

TEST(Iterator, Test1) {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec[0], *vec.begin());
    EXPECT_EQ(vec[0], vec.front());
    EXPECT_EQ(vec[2], vec.back());
    EXPECT_EQ(vec[2], *(vec.end() - 1));
}

// TEST(Sort, Test2) {
//     vector<int> vec;
//     vec.push_back(3);
//     vec.push_back(1);
//     vec.push_back(2);
//
//     std::sort(vec.begin(), vec.end(),
//               [](const int& a, const int& b) { return a < b; });
//
//     EXPECT_EQ(vec[0], 1);
//     EXPECT_EQ(vec[1], 2);
//     EXPECT_EQ(vec[2], 3);
// }

TEST(Swap, Test3) {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vector<int> vec2;
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(7);
    vec2.push_back(8);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
    EXPECT_EQ(vec2[0], 5);
    EXPECT_EQ(vec2[1], 6);
    EXPECT_EQ(vec2[2], 7);
    EXPECT_EQ(vec2[3], 8);
    vec.swap(vec2);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
    EXPECT_EQ(vec2[3], 4);
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec[1], 6);
    EXPECT_EQ(vec[2], 7);
    EXPECT_EQ(vec[3], 8);
}
