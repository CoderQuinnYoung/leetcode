//
//  46 Permutations.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> visited;
    
    vector<vector<int>> permute(vector<int>& nums) {
        auto n = nums.size();
        
        path.resize(n);
        visited.resize(n);
        
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>&nums, int u)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                path[u] = nums[i];
                visited[i] = true;
                dfs(nums, u + 1);
                visited[i] = false;
            }
        }
        
    }
};
