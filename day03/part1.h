#pragma once

#include <fmt/ranges.h>
#include <string_view>

namespace part_one
{

[[nodiscard]] constexpr static auto calc_mul(const std::string_view str) -> int
{
    int  first_num {};
    int  second_num {};
    bool found_comma {};
    for (const auto& ch : str) {
        if(ch == ')'){
            return first_num * second_num;
        }
        if(std::isdigit(ch) == 0 && ch != ','){
            return 0;
        }

        if(ch == ','){
            if (first_num == 0 || found_comma) {
                return 0;
            }
            found_comma = true;
        }else if(std::isdigit(ch) != 0){
            if(not found_comma){
                first_num = first_num * 10 + (ch - '0');
            }else{
                second_num = second_num * 10 + (ch - '0');
            }
        }
    }
    return 0;
}

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    int result {};

    size_t pos = document.find("mul(");
    while(pos != std::string::npos)
    {
        // fmt::println("{}   => {}", document.substr(pos+4), result);
        result += calc_mul(document.substr(pos+4));
        pos = document.find("mul(", pos+1);
    }

    return result;
}

} // namespace part_one
