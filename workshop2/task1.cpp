#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int len_longest_substring(string s) {
    unordered_map<char, int> chars_map;
    int maxl = 0, l = 0;

    for (int r = 0; r < s.length(); r++) {
        if (chars_map.count(s[r])) {
            if (chars_map[s[r]] >= l) {
                l = chars_map[s[r]] + 1;
            }
        }
        chars_map[s[r]] = r;
        maxl = max(maxl, r - l + 1);
    }
    return maxl;
}
void test()
{
    assert (len_longest_substring("abcabcabc") == 3);

    assert (len_longest_substring("bbbbb") == 1);

    assert (len_longest_substring("pwwkew") == 3);

    assert (len_longest_substring("") == 0);

    assert (len_longest_substring("a") == 1);

    assert (len_longest_substring("abcdef") == 6);

    assert (len_longest_substring("baauz") == 3);

    cout << "Все тесты для len_longest_substring пройдены успешно!";
}
int main() {
    test();
}
