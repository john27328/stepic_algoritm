#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using Int = int;
using Mas = std::vector<Int>;
using Queue = std::queue<Mas>;

size_t inv = 0;

Mas merge(const Mas &a, const Mas &b){
    auto itA = a.begin();
    auto itB = b.begin();

//    for(auto &i:a){
//        std::cout<<i <<" ";
//    }
//    std::cout<<"- ";
//    for(auto &i:b){
//        std::cout<<i <<" ";
//    }
//    std::cout<<" \n";

    Mas m;
    while (itA != a.end() or itB != b.end()){
        if (itA != a.end() and itB == b.end()){
            m.push_back(*itA);
            itA++;
        } else if (itB != b.end() and itA == a.end()){
            m.push_back(*itB);
            itB++;
        } else if (*itA <= *itB) {
            m.push_back(*itA);
            itA++;
        } else {
            m.push_back(*itB);
            itB++;
            inv += a.end() - itA;
        }
    }
    return m;
}


Mas sort(const Mas &mas){
   auto a = mas.begin();
   auto b = mas.end();
   if (b - a == 1){
       return mas;
   }
   auto c = a + (b - a) / 2;
   Mas m1(c - a), m2(b - c);
   std::copy(a, c, m1.begin());
   std::copy(c, b, m2.begin());
   return merge(sort(m1),sort(m2));
}

int main()
{
    size_t n;
    std::cin >> n;
    Mas mas(n);
    for(auto &i: mas)
        std::cin >> i;

    auto sortMas = sort(mas);
    std::cout << inv << std::endl;
    return 0;
}

