/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>


std::pair<std::size_t, std::size_t> f(const std::vector<int>& nums, int target) {
    std::unordered_map<int, std::size_t> m;

    for (auto i = 0; i < nums.size(); ++i) {
        auto k = target - nums[i];
        if (m.count(k)) {
            return {m[k], i};
        }
        m[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    auto target = 20;
    auto result = f(nums, target);
    std::cout << result.first << " " << result.second;
    return 0;
}
