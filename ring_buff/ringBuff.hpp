#pragma once

#include <iostream>
#include <vector>
#include <atomic>
#include <numeric>

inline std::atomic<bool> flag = 0;

class ring_buff{
    private:
        std::vector<int> buff;
        int len;
        int head = 0;
        long long current_sum = 0;

    public:
        ring_buff(std::vector<int> nums) : buff(nums), len(size(nums)){
            current_sum = std::accumulate(buff.begin(), buff.end(), 0LL);
        }
        
        void check();
        std::vector<int> memory();
        void print_res(std::vector<int>);
        int filter(int next_val);
        
};