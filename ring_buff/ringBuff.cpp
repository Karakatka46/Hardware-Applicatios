#include <ringBuff.hpp>

void ring_buff::check(){
    if(buff.empty()) 
        flag = 1;
}

std::vector<int> ring_buff::memory()
{
    std::vector<int> diffs;
    std::cout << len << '\n';
    for(int i = 0; i < len; i++){
        int next_ind = (i + 1) % len;
        auto res_diff = buff[i] - buff[next_ind];
        // auto res_diff = static_cast<int>(reinterpret_cast<uintptr_t>(&buff[i]) - 
        //                                  reinterpret_cast<uintptr_t>(&buff[next_ind]));
        diffs.push_back(res_diff);
        std::cout << "Element " << i << "\t" << diffs[i] << '\n';

    }

    return diffs;
}

void ring_buff::print_res(std::vector<int> diffs){
    for(int i = 0; i < size(diffs); i++){
        std::cout << "Element " << i << "\t" << diffs[i] << '\n';
    }
}

int ring_buff::filter(int new_val){
    current_sum -= buff[head];
    buff[head] = new_val;
    current_sum += new_val;
    head = (head + 1) % len;

    long long scaled_sum = current_sum << 16;
    int result_q4 = static_cast<int>(scaled_sum / static_cast<long long>(len));
    
    return result_q4;
//    return static_cast<int>(current_sum / len);
}