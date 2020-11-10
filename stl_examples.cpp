#include <vector>
#include <iostream>
#include <algorithm> //std::for_each, std::all_of, std::find, std::count, std::count_if, std::replace, 
//std::swap, std::generate, std::sort, std::is_sorted
#include <numeric> //std::accumulate

void show_vector(const std::vector<int>& v){
    for (auto&& el : v){
        std::cout<< el << " ";
    }
    std::cout<< "\n";
}

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

void fun7(std::vector<int>& v, const int old_el, const int new_el) {
    std::replace(v.begin(), v.end(), old_el, new_el);
}

void fun8(std::vector<int>& v, const int first, const int second){
    std::swap(v[first], v[second]);
}

void fun9(std::vector<int>& v){
    std::generate(v.begin(), v.end(), [n = 1]() mutable{
        return n += n%2+n;
    });
}

void fun10(std::vector<int>& v){
    std::sort(v.begin(), v.end());
}

std::string fun11(const std::vector<int>& v){
    return std::is_sorted(v.begin(), v.end()) ? "yes, it's sorted" : "no, it's not sorted";
}

int main(){

    std::vector<int> v{3,6,2,0,5,7,11,34,0,32,88};

    show_vector(v);

    std::cout<< "\n\nItems divided by 2 (std::for_each) = " << fun1(v) << "\n";
    std::cout<< "Items divided by 2 (std::accumulate) = " << fun2(v) <<"\n";
    std::cout<< "Items divided by 2 (range loop) = " << fun3(v) <<"\n";
    std::cout<< "Items divided by 2 (std::count_if) = " << fun4_1(v) <<"\n";
    std::cout<< "All items in vector contain 0 (std::count) = " << fun4_2(v, 0) <<"\n";
    fun7(v, 0, 333);
    std::cout<< "Replace 0 with 333 in vector (std::replace) \n";
    std::cout<< "All items in vector contain 0 (std::count) = " << fun4_2(v, 0) <<"\n";
    std::cout<< "All items in vector contain 333 (std::count) = " << fun4_2(v, 333) <<"\n";
    std::cout<< "Is every element divided by 2 (all_off) ? = " << fun5(v) <<"\n";
    std::cout<< "Is there 11 in vector (std::find) ? = " << fun6(v, 11) << "\n";
    std::cout<< "First element in vector is = " << *(v.begin()) << "\n";
    std::cout<< "Last element in vector is = " << v[v.size()-1] << "\n";
    std::cout<< "First and last element after std::swap: \n";
    fun8(v, 0, v.size()-1);
    std::cout<< "First element after swap in vector is = " << *(v.begin()) << "\n";
    std::cout<< "Last element after swap in vector is = " << v[v.size()-1] << "\n\n";
    show_vector(v);
    std::cout<< "Is vector is sorted ? " << fun11(v) << "\n";
    std::cout<<"Vector after sorting: \n";
    fun10(v);
    show_vector(v);
    std::cout<< "Is vector is sorted ? " << fun11(v) << "\n";

    std::cout<< "new vector with size 11: ";
    std::vector<int> v2(11); //declared size of vector
    show_vector(v2);
    std::cout<< "Vector with generated elements: ";
    fun9(v2);
    show_vector(v2);

    return 0;
}
