/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3


1 0
2 1 2
4 3 4 5 6
8 7 8 9 10 11 12 13 14
16 15 ...

*/

#include <iostream>
#include <vector>
#include <string>

bool f(const std::vector<std::string>& t) {
    for (auto n = 1; n < t.size(); n *= 2) {
        for (auto i = n - 1, j = n * 2 - 2; i < j && j < t.size(); ++i, --j) {
            if (t[i] != t[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::string> t = {"1", "2" , "2" , "3" , "4" , "4" , "3"};
    std::cout << f(t);
    return 0;
}