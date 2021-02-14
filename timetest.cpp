#include <cmath>
#include <iostream>
#include <chrono>
#include <cfloat>
#include <climits>
void loop(){
    int num;
    int res;
    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    
    for(int i=0; i<1000000;i++){
        num = INT_MAX;
        int cnt = 0;
        while(num>=1){
            num/=10;
            cnt++;
        }
        res = cnt;
    }
    std::cout<<res<<"\n";
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count() << "[µs]\n" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - begin1).count() << "[ns]\n" << std::endl;
    
}
void logarithm(){
    int num;
    int res;
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    for(int i=0; i<1000000;i++){
        num = INT_MAX;
        res = log10(num)+1;
    }
    std::cout<<res<<"\n";
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count() << "[µs]\n" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - begin2).count() << "[ns]\n" << std::endl;
    
}
int main(){
    
    
    logarithm();
    loop();
}