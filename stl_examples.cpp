#include <vector>
#include <iostream>
#include <algorithm> //std::for_each, std::all_of, std::find, std::count, std::count_if
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

int fun4_1(const std::vector<int>& v){
    return std::count_if(v.begin(), 
                         v.end(), 
                         [](const auto& el){
                             return el%2 == 0 ? 1 : 0;
                             }
                        );;
}

int fun4_2(const std::vector<int>& v, const int i){
    return std::count(v.begin(), v.end(), i);
}

std::string fun5(const std::vector<int>& v){
    return std::all_of(v.begin(), v.end(), [](const auto& el){return el%2 == 0;}) ? 
        "every element is divided by 2" 
        : "not every element is divided by 2";
}

std::string fun6(const std::vector<int>& v, const int el){
    return *(std::find(v.begin(), v.end(), el)) ? "Yes, I found it;)" : "No, I didn't find it";
}

int main(){

    std::vector<int> v{3,6,2,0,5,7,11,34,0,32,88};

    for (auto& el : v){
        std::cout<<el << ", ";
    }

    std::cout<< "\n\nItems divided by 2 (for_each) = " << fun1(v) << "\n";
    std::cout<< "Items divided by 2 (accumulate) = " << fun2(v) <<"\n";
    std::cout<< "Items divided by 2 (range loop) = " << fun3(v) <<"\n";
    std::cout<< "Items divided by 2 (count_if) = " << fun4_1(v) <<"\n";
    std::cout<< "All items in vector contain 0 (count) = " << fun4_2(v, 0) <<"\n";
    std::cout<< "Is every element divided by 2 (all_off) ? = " << fun5(v) <<"\n";
    std::cout<< "Is there 11 in vector (std::find) ? = " << fun6(v, 11) << "\n";

    return 0;
}
