from typing import List
from collections import defaultdict

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        # count记录遍历过程中每种相似字符串出现的次数
        count = defaultdict(int)
        total = 0

        # 将出现字母的序号对应的位置1来生成hash 相似字符串的hash相同
        for word in words:
            hash = 0
            for letter in word:
                hash |= 1 << (ord(letter) - 97)  # 'a'
            total += count[hash]
            count[hash] += 1
        
        return total
            