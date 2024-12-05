#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <spanstream>
#include <string_view>
#include <vector>

namespace part_two
{

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    std::vector<int> room_list;

    std::ispanstream stream(document);
    std::ranges::copy(std::views::istream<int>(stream), std::back_inserter(room_list));

    auto second_list = room_list | std::views::drop(1) | std::views::stride(2);
    auto first_list  = std::views::stride(room_list, 2) | std::views::transform([&](int val) {
        return val * std::ranges::count(second_list, val);
    });

    // fmt::println("{}", first_list);
    return std::ranges::fold_left(first_list, 0, std::plus<> {});
}

} // namespace part_two
