#pragma once

#include <fmt/ranges.h>
#include <string_view>

namespace part_two
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

    bool is_enabled{true};
    size_t do_pos = 0;
    size_t dont_pos = document.find("don't()");
    size_t pos = document.find("mul(");
    while(pos != std::string::npos)
    {
        if(is_enabled){
            if(pos < dont_pos){
                result += calc_mul(document.substr(pos+4));
            }else{
                is_enabled = false;
                do_pos = document.find("do()", pos);
            }
        }else{
            if(pos > do_pos){
                is_enabled = true;
                dont_pos = document.find("don't()", pos);
                result += calc_mul(document.substr(pos+4));
            }
        }
        dont_pos = document.find("don't()", pos);
        pos = document.find("mul(", pos+1);
    }

    return result;
}

} // namespace part_one
