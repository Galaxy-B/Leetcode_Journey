class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        maxlen = 0

        # 当尾指针无法前进时 从窗口中逐出头指针指向的元素 直至尾指针可以继续探测
        tail = 0
        for head in range(len(s)):
            while tail < len(s) and s[tail] not in window:
                window.add(s[tail])
                tail += 1
            
            # 内层循环退出时 [head,tail)为一个无重复字符的子串
            maxlen = max(maxlen, tail - head)
            window.remove(s[head])
        
        return maxlen
