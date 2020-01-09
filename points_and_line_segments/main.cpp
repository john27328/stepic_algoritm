#include <iostream>
#include <vector>
#include <cassert>

using Int = int;
using Mas = std::vector<Int>;

void partition(Mas &m, Int l, Int r, Int &jl, Int &jr){

    //    for(auto &i: m)
    //        std::cout << i << " ";
    //     std::cout << std::endl;

    //     std::cout <<"--" << l << " - " << r << std::endl;

    {
        Int p = (r + l) / 2;
        std::swap(m[p], m[l]);
    }
    Int pv = m[l];
    jl = l;
    jr = l;
    for (Int i = l+1; i < r; i++){
        if(m[i] < pv){
            std::swap(m[i], m[jr+1]);
            std::swap(m[jr+1], m[jl]);
            jl++;
            jr++;
        } else if (m[i] == pv) {
            std::swap(m[jr+1], m[i]);
            jr++;
        }
    }

    //    std::cout <<"---" << j << std::endl;
}

void qSort(Mas &m, Int l, Int r){
    if (r - l < 1)
        return;
    Int jl, jr;
    partition(m, l, r, jl, jr);
    qSort(m,l,jl);
    qSort(m,jr+1,r);
}

int get_pos(const Mas &numbers, Int number) {
    Int number_count = numbers.size();
    Int a = 0;
    Int b = number_count-1;
    while(a <= b){
        Int c = (a + b) / 2;
        if (numbers[c] == number){
            return c;
        }
        if (numbers[c] > number)
            b = c - 1;
        else
            a = c + 1;
    }
    return a;
}

int main()
{
    Int n, m;
    std::cin >> n >> m;
    Mas begins(n), ends(n);
    for(Int i = 0; i < n; i++){
        Int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        begins[i] = tmp1;
        ends[i] = tmp2;
    }

    Mas points(m);
    for(auto &i:points)
        std::cin >> i;

    qSort(begins, 0, n);
    qSort(ends, 0, n);

    for (auto &p: points){
        auto l = get_pos(begins, p);
        while (begins[l] == p and l < n) l++;
        auto r = get_pos(ends, p);
        while (ends[r-1] == p and r - 1 >= 0) r--;
        std::cout << l - r << " ";
    }
    std::cout << std::endl;

//    Mas m = {0, 1, 2, 3 ,4 ,5};
//    qSort(m, 0, m.size());

//    for(auto &i: m)
//        std::cout << i << " ";
//    std::cout << std::endl;

    return 0;
}
