#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using Int = int;
using Mas = std::vector<Int>;
using Queue = std::queue<Mas>;

size_t inv = 0;

void printMas(const Mas &a){
    for(auto &i: a)
        std::cout << i << " ";
    std::cout << std::endl;

}


Mas merge(const Mas &a, const Mas &b){
    printMas(a);
    std::cout << " - ";
    printMas(b);
    auto itA = a.begin();
    auto itB = b.begin();
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
            inv++;
        }
    }
    std::cout << " : ";
    printMas(m);
    std::cout<<std::endl;
    return m;
}

Mas sort1(const Mas &mas){
    Queue q;
    for (auto &i: mas){
        Mas tmpMas;
        tmpMas.push_back(i);
        q.push(tmpMas);
    }

    size_t n = mas.size();
    while (n > 1){
        auto a = q.front();
        q.pop();
        auto b = q.front();
        q.pop();
        q.push(merge(a, b));
        n--;
    }
    return q.front();
}

Mas sort2(const Mas &mas){
   auto a = mas.begin();
   auto b = mas.end();
   if (b - a == 1){
       return mas;
   }
   auto c = a + (b - a) / 2;
   Mas m1(c - a), m2(b - c);
   std::copy(a, c, m1.begin());
   std::copy(c, b, m2.begin());
   return merge(sort2(m1),sort2(m2));
}

int main()
{
//    size_t n;
//    std::cin >> n;
//    Mas mas(n);
//    for(auto &i: mas)
//        std::cin >> i;

    Mas mas = {1, 2, 3, 5, 4};
    printMas(mas);

    auto sortMas = sort2(mas);
    printMas(sortMas);
    std::cout << inv << std::endl;

    int inv = 0;
    size_t n = mas.size();
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(mas[i] > mas[j])
                inv++;
    std::cout << inv << std::endl;
    return 0;
}



/*************************************
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> mas(n);
    for(int &i: mas)
        std::cin >> i;
    int inv = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(mas[i] > mas[j])
                inv++;
    std::cout << inv;
    return 0;
}
****************************************/
