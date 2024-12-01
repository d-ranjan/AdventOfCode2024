#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <spanstream>
#include <string_view>
#include <vector>

namespace part_one
{

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    std::vector<int> room_list;

    std::ispanstream stream(document);
    std::ranges::copy(std::views::istream<int>(stream), std::back_inserter(room_list));

    auto first_list = std::views::stride(room_list, 2) | std::ranges::to<std::vector<int>>();
    std::ranges::sort(first_list);
    auto second_list = room_list | std::views::drop(1) | std::views::stride(2)
                       | std::ranges::to<std::vector<int>>();
    std::ranges::sort(second_list);

    // fmt::print("{}\n", std::views::zip(first_list, second_list));
    constexpr auto distance = [](int first, int second) { return std::abs(first - second); };
    return std::ranges::fold_left(std::views::zip_transform(distance, first_list, second_list), 0,
                                  std::plus<> {});
}

} // namespace part_one
