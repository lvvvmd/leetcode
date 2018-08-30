class Solution(object):
    def countAndSay(self, n):
        if n == 0:
            return ''

        rst = '1'
        for i in range(n-1):
            count = 1
            prev = rst[0]
            r = len(rst) - 1
            new_rst = ''
            for j in range(r):
                if rst[j + 1] == prev:
                    count += 1
                else:
                    new_rst += bytes(count) + prev
                    count = 1
                    prev = rst[j + 1]

            new_rst += bytes(count) + prev
            rst = new_rst

        return rst
