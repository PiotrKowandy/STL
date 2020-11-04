#include <vector>
#include <iostream>
#include <algorithm> //std::for_each, std::all_of
#include <numeric> //std::accumulate

int fun1(const std::vector<int>& v){
    int result{};
    
    std::for_each(v.begin(), 
                  v.end(), 
                  [&result](const auto el) mutable { //mutable keyword removes const parameters captured by copy 
                      result = el%2 == 0 ? result+1 : result;  //if (el%2 == 0) result++;
                  }
                  );

    return result;
}

int fun2(const std::vector<int>& v){
    return std::accumulate(v.begin(), 
                           v.end(), 
                           0, 
                           [](auto sum, const auto el) mutable {
                                return sum = el%2 == 0 ? sum+1 : sum;
                           }
                           );
}

int fun3(const std::vector<int>& v){
    int result{};
    for (const auto& el : v){
        result = el%2 == 0 ? ++result : result;
    }
    return result;
}

int fun4(const std::vector<int>& v){
    return std::count_if(v.begin(), 
                         v.end(), 
                         [](const auto& el){
                             return el%2 == 0 ? 1 : 0;
                             }
                        );;
}

std::string fun5(const std::vector<int>& v){
    return std::all_of(v.begin(), v.end(), [](const auto& el){return el%2 == 0;}) ? 
        "every element is divided by 2" 
        : "not every element is divided by 2";
}

int main(){

    std::vector<int> v{3,6,2,0,5,7,11,34,32,88};

    for (auto& el : v){
        std::cout<<el << ", ";
    }

    std::cout<< "\n\nItems divided by 2 (for_each) = " << fun1(v) << "\n";
    std::cout<< "Items divided by 2 (accumulate) = " << fun2(v) <<"\n";
    std::cout<< "Items divided by 2 (range loop) = " << fun3(v) <<"\n";
    std::cout<< "Items divided by 2 (count_if) = " << fun4(v) <<"\n";
    std::cout<< "Is every element divided by 2 (all_off) ? = " << fun5(v) <<"\n";

    return 0;
}
