// Created by bai on 2020/9/10.
// leetcode 第一题 两数相加
    /**
     * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

    示例:

    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
     */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "source/two_num_sum.h"
using namespace std;

vector<int> Solution1::twoNumSum1(vector<int> &nums, int target) {
    int i,j;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target){
                cout << i << " " << j << endl;
                return {i,j};
            }
        }
    }
    return {i,j};
}

vector<int> Solution1::twoNumSum2(vector<int> &nums, int target) {
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++){
        if(map[target - nums[i]] && map[target - nums[i]] != i + 1){
            cout << i-1 << " " << target - nums[i]-1 << endl;
        }
        map[nums[i]] = i + 1;
    }
     return {-1,-1};
}

int main(){
    vector<int> nums[4];
    nums->push_back(2);
    nums->push_back(7);
    nums->push_back(11);
    nums->push_back(15);
    Solution1 so;
    // so.twoNumSum1(*nums,9);
    so.twoNumSum2(*nums,9);

    return 0;
}