class Solution:
    def stock_span(self, prices):
        stack = [] 
        res = []
        for i, p in enumerate(prices):
            res.append(1) # initial val for i
            while stack and prices[stack[-1]] <= p:
                top = stack.pop()
                res[i] += res[top]
            stack.append(i)
        return res

# Test
prices = [100, 80, 60, 70, 60, 75, 85]
print(Solution().stock_span(prices))

# Output
# [1, 1, 1, 2, 1, 4, 6]

prices = [10, 4, 5, 90, 120, 80]
print(Solution().stock_span(prices))

# Output
# [1, 1, 2, 4, 5, 1]