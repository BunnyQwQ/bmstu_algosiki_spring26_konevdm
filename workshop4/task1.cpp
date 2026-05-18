#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long


// Тут по хорошему свой бинарный поиск писать. Но это долго...
// Задача популярная очень
// Но кратко по решению: собираем самую эффективную строку в dop
// Если элемент не увеличивает последовательность, то мы стараемся сделать dop более предрасположенной к будущим числам уменьшая ближайшее сверху число
// то есть если у нас есть dop: [10]
// x = 8, то мы заменяем 10 на 8, длина не меняется, но зато в будущем последовательсность сможет включить в себя 9 и 10
// Объясняю подробно, потому что предполагаю что вы ожидали решение через динамику
int lengthOfLIS(vector<int>& nums) {
    vector<int> dop;
    for (auto x : nums) {
        auto i = lower_bound(dop.begin(), dop.end(), x);
        if (i == dop.end()) dop.push_back(x);
        else *i = x;
    }
    return dop.size();
}





signed main() // На литкоде зашла, Тесты оттуда же
{
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    assert(lengthOfLIS(nums1) == 4);
    assert(lengthOfLIS(nums2) == 4);
    assert(lengthOfLIS(nums3) == 1);
}
