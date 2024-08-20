#include "src/kata2.hpp"
#include <gtest/gtest.h>
#include <functional>

void test(std::function<int(int, std::vector<int>)> search)
{
    EXPECT_EQ(-1, search(3, {}));
    EXPECT_EQ(-1, search(3, {1}));
    EXPECT_EQ(0 , search(1, {1}));

    EXPECT_EQ(0 , search(1, {1, 2}));
    EXPECT_EQ(1 , search(2, {1, 2}));

    EXPECT_EQ(0 , search(1, {1, 3, 5}));
    EXPECT_EQ(1 , search(3, {1, 3, 5}));
    EXPECT_EQ(2 , search(5, {1, 3, 5}));
    EXPECT_EQ(-1, search(0, {1, 3, 5}));
    EXPECT_EQ(-1, search(2, {1, 3, 5}));
    EXPECT_EQ(-1, search(4, {1, 3, 5}));
    EXPECT_EQ(-1, search(6, {1, 3, 5}));

    EXPECT_EQ(0 , search(1, {1, 3, 5, 7}));
    EXPECT_EQ(1 , search(3, {1, 3, 5, 7}));
    EXPECT_EQ(2 , search(5, {1, 3, 5, 7}));
    EXPECT_EQ(3 , search(7, {1, 3, 5, 7}));
    EXPECT_EQ(-1, search(0, {1, 3, 5, 7}));
    EXPECT_EQ(-1, search(2, {1, 3, 5, 7}));
    EXPECT_EQ(-1, search(4, {1, 3, 5, 7}));
    EXPECT_EQ(-1, search(6, {1, 3, 5, 7}));
    EXPECT_EQ(-1, search(8, {1, 3, 5, 7}));
}

TEST(SearchTest, Search1)
{
    test(search_1);
}

TEST(SearchTest, Search2)
{
    test(search_2);
}

TEST(SearchTest, Search3)
{
    test(search_3);
}

TEST(SearchTest, Search4)
{
    test(search_4);
}

TEST(SearchTest, Search5)
{
    test(search_5);
}
