#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number) {
  // TODO optimize this function
    size_t number_count = numbers.size();
    size_t a = 1;
    size_t b = number_count;
    while(a <= b){
        size_t c = (a + b) / 2;
        if (numbers[c-1] == number)
            return c;
        if (numbers[c-1] > number)
            b = c - 1;
        else
            a = c + 1;
    }
    return -1;
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (auto &number:numbers) {
    std::cin >> number;
  }
  assert(std::is_sorted(numbers.begin(), numbers.end()));

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    int number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}
