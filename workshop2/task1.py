def len_longest_substring(s):
    chars_map = {}
    maxl = 0
    l = 0

    for r in range(len(s)):
        cur_char = s[r]

        if cur_char in chars_map and chars_map[cur_char] >= l:
            l = chars_map[cur_char] + 1

        chars_map[cur_char] = r
        maxl = max(maxl, r - l + 1)

    return maxl


def test():
    assert len_longest_substring("abcabcabc") == 3

    assert len_longest_substring("bbbbb") == 1

    assert len_longest_substring("pwwkew") == 3

    assert len_longest_substring("") == 0

    assert len_longest_substring("a") == 1

    assert len_longest_substring("abcdef") == 6

    assert len_longest_substring("baauz") == 3

    print("Все тесты для len_longest_substring пройдены успешно!")


test()
