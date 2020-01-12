#include <iostream>
#include <vector>
#include <cassert>

using Int = int;
using Mas = std::vector<Int>;

int main()
{
    Int n;
    std::cin >> n;
    Mas m(n);
    Mas integers(11);
    for(auto &i: m){
        std::cin >> i;
        integers[i]++;
    }

    for(Int i = 2; i < integers.size(); i++){
        integers[i] += integers[i - 1];
    }

    Mas m2(n);
    for(Int i = n-1; i >=0; i--){
        m2[integers[m[i]]-1] = m[i];
        integers[m[i]]--;
    }

    for(auto i: m2)
        std::cout << i << " ";
    return 0;
}
