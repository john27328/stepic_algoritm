#include <iostream>
#include <vector>
#include <cassert>

using Int = int;
using Mas = std::vector<Int>;

Int partition(Mas &m, Int l, Int r){

    //    for(auto &i: m)
    //        std::cout << i << " ";
    //     std::cout << std::endl;

    //     std::cout <<"--" << l << " - " << r << std::endl;

    Int p = (r + l) / 2;
    std::swap(m[p], m[r-1]);
    p = r-1;
    Int j = l;
    for (Int i = l; i < p; i++){
        if(m[i] <= m[p]){
            std::swap(m[i], m[j]);
            j++;
        }
    }
    std::swap(m[p], m[j]);

    //    std::cout <<"---" << j << std::endl;
    return j;
}

void qSort(Mas &m, Int l, Int r){
    if (r - l < 1)
        return;
    Int j = partition(m, l, r);
    qSort(m,l,j-1);
    qSort(m,j+1,r);
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

    for (int &p: points){
        auto l = get_pos(begins, p);
        while (begins[l] == p and l < n) l++;
        auto r = get_pos(ends, p);
        while (ends[r-1] == p and r - 1 >= 0) r--;
        std::cout << l - r << " ";
    }
    std::cout << std::endl;

//    Mas m = {4,2,1,6,2,3,2,5};
//    qSort(m, 0, m.size());

//    for(auto &i: m)
//        std::cout << i << " ";
//    std::cout << std::endl;

    return 0;
}
