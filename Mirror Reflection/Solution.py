class Solution(object):
    def hcf(self,x, y):
        if x > y:
            smaller = y
        else:
            smaller = x

        for i in range(1,smaller + 1):
            if((x % i == 0) and (y % i == 0)):
                hcf = i

        return hcf
    
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
       
        lcm = p * q / self.hcf(p, q)
        
        x = lcm / q
        y = lcm / p
        rst = [[-1,2], [0,1]]
        return rst[x % 2][y % 2]
