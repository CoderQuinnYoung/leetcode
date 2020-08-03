//
//  SearchinRotatedSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if(nums[left] < nums[mid]) { // 左边有序
                if (nums[left] <= target && target < nums[mid]) { // target位于右边有序列
                    right = mid -1;
                } else {
                    left = mid + 1;
                }
            } else { // 右边有序
                 if (nums[mid] < target && target <= nums[right]) { // target位于右边有序列
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] < nums[right]) { // 右边是有序的
                if (nums[mid] < target && target <= nums[right]) { // 位于右边有序中
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // 左边是有序的
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
};
