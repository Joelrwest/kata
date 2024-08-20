#include "kata2.hpp"
#include <span>
#include <iostream>

static constexpr auto NOT_FOUND{-1};

/* Iterative binary search */
int search_1(int target, std::vector<int> vec)
{
    auto lo_idx{0};
    auto hi_idx{static_cast<int>(vec.size()) - 1};
    while (lo_idx <= hi_idx)
    {
        const auto mid{(lo_idx + hi_idx) / 2};
        const auto mid_val{vec.at(mid)};
        if (mid_val == target)
        {
            return mid;
        }

        if (mid_val > target)
        {
            hi_idx = mid - 1;
        }
        else
        {
            lo_idx = mid + 1;
        }
    }

    return NOT_FOUND;
}

/* Recursive binary search using span */
int search_2_impl(int target, std::span<const int> span, int base_idx = 0)
{
    if (span.size() == 1)
    {
        return span.front() == target ? base_idx : NOT_FOUND;
    }

    const auto target_idx{[&]() {
        const auto mid_idx{static_cast<int>(span.size() / 2)};
        const auto mid_it{std::next(span.begin(), mid_idx)};
        if (*mid_it == target)
        {
            return base_idx + mid_idx;
        }

        if (*mid_it > target)
        {
            return search_2_impl(target, std::span<const int>{span.begin(), mid_it}, base_idx);
        }
        else
        {
            return search_2_impl(target, std::span<const int>{mid_it, span.end()}, base_idx + mid_idx);
        }
    }()};

    return target_idx == NOT_FOUND ? NOT_FOUND : target_idx;
}

int search_2(int target, std::vector<int> vec)
{
    if (vec.empty())
    {
        return NOT_FOUND;
    }

    return search_2_impl(target, vec);
}

/* Recursive binary search using indexes */
int search_3_impl(int target, const std::vector<int> &vec, int lo_idx, int hi_idx)
{
    if (lo_idx >= hi_idx)
    {
        const auto idx{hi_idx};
        return vec.at(idx) == target ? idx : NOT_FOUND;
    }

    const auto target_idx{[&]() {
        const auto mid_idx{lo_idx + hi_idx / 2};
        const auto mid_val{vec.at(mid_idx)};
        if (mid_val == target)
        {
            return mid_idx;
        }

        if (mid_val > target)
        {
            return search_3_impl(target, vec, lo_idx, mid_idx - 1);
        }
        else
        {
            return search_3_impl(target, vec, mid_idx + 1, hi_idx);
        }
    }()};

    return target_idx == NOT_FOUND ? NOT_FOUND : target_idx;
}

int search_3(int target, std::vector<int> vec)
{
    if (vec.empty())
    {
        return NOT_FOUND;
    }

    return search_3_impl(target, vec, 0, vec.size() - 1);
}

/* Recursive binary search using iterators */
template <typename I>
I search_4_impl(int target, I begin_it, I end_it)
{
    const auto distance{std::distance(begin_it, end_it)};
    if (distance == 0)
    {
        return end_it;
    }

    if (distance == 1)
    {
        return *begin_it == target ? begin_it : end_it;
    }

    const auto mid_it{std::next(begin_it, distance / 2)};
    if (*mid_it == target)
    {
        return mid_it;
    }

    if (*mid_it > target)
    {
        const auto target_it{search_4_impl(target, begin_it, mid_it)};
        return target_it == mid_it ? end_it : target_it;
    }
    else
    {
        return search_4_impl(target, mid_it, end_it);
    }
}

int search_4(int target, std::vector<int> vec)
{
    const auto target_it{search_4_impl(target, vec.begin(), vec.end())};
    return target_it == vec.end() ? NOT_FOUND : std::distance(vec.begin(), target_it);
}

/* Using the standard library */
int search_5(int target, std::vector<int> vec)
{
    const auto target_it{std::find(vec.begin(), vec.end(), target)};
    return target_it == vec.end() ? NOT_FOUND : std::distance(vec.begin(), target_it);
}
