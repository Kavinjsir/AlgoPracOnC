class Solution(object):
    def lengthOfLongestSubstring(self, s):
        lst = [-1 for _ in range(256)]
        sz = len(s)
        i, j, ml = 0, -1, 0
        while i != sz:
            k = ord(s[i])
            if lst[k] > j:
                j = lst[k]
            lst[k] = int(i)
            ml = max(ml, i - j);
            i += 1
        return ml