/*
两数之和

Given an array of integers, return indices of the two numbers such that they
 add up to a specific target. You may assume that each input would have exactly
 one solution, and you may not use the same element twice.

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> result;
        std::unordered_map<int, int> check_num;

        int size = static_cast<int>(nums.size());
        for (int index = 0; index < size; ++index)
        {
            int num = nums[index];
            auto it = check_num.find(num);
            if (it != check_num.end())
            {
                result.push_back(it->second);
                result.push_back(index);
                break;
            }
            else
            {
                check_num[target - num] = index;
            }
        }
        return result;
    }
};

void print_vec(const std::string &info, const std::vector<int> &vec)
{
    if (!info.empty())
        std::cout << info;
    for (auto num : vec)
        std::cout << num << ",";
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = solution.twoSum(nums, target);

    print_vec("The nums is  : ", nums);
    std::cout << "The target is: " << target << std::endl;
    print_vec("The result is: ", result);

    return 0;
}
