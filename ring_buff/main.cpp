#include <iostream>
#include <vector>

#include <ringBuff.hpp>


int main(){
    std::vector<int> data = {10, 10, 10, 10, 10};

    ring_buff m1(data);
    int raw_sensor_data = 8111;
    int smooth_data = m1.filter(raw_sensor_data);

    m1.memory();

    std::cout << smooth_data << '\n';

    int integer_part = smooth_data >> 16;        
    int fractional_part = smooth_data & 0x00FFFF;   
    int decimal_factor = (fractional_part * 100) >> 16;
    std::cout << "Result: " << integer_part << "." << decimal_factor << '\n'; 

    return 0;
}