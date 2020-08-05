//
//  FindFirstAndLastPositionOfElementInSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/3.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using std::vector;

// 模板3
/*
 int binarySearch(vector<int>& nums, int target){
     if (nums.size() == 0)
         return -1;

     int left = 0, right = nums.size() - 1;
     while (left + 1 < right){
         // Prevent (left + right) overflow
         int mid = left + (right - left) / 2;
         if (nums[mid] == target) {
             return mid;
         } else if (nums[mid] < target) {
             left = mid;
         } else {
             right = mid;
         }
     }

     // Post-processing:
     // End Condition: left + 1 == right
     if(nums[left] == target) return left;
     if(nums[right] == target) return right;
     return -1;
 }
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result_vector(2, -1);
        if (nums.empty()) return result_vector;

        int left = 0;
        int right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = left + 1;
            } else if(nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // Post-processing:
        // End Condition: left + 1 == right
        if (nums[left] == target || nums[right] == target) {
            
            while (left >= 0 && nums[left] == target) left--;
            
            while (right < nums.size() && nums[right] == target) right++;

            
            result_vector[0] = left + 1;
            result_vector[1] = right - 1;
        }
 
        return result_vector;
    }
};