#include <vector>
#include <iostream>
#include <algorithm> //std::for_each
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


int main(){

    std::vector<int> v{3,6,2,0,5,7,11,34,32,88};

    for (auto& el : v){
        std::cout<<el << ", ";
    }

    std::cout<< "\n\nItems diveded by 2 (for_each) = " << fun1(v) << "\n";
    std::cout<< "Items diveded by 2 (accumulate) = " << fun2(v) <<"\n";

    return 0;
}