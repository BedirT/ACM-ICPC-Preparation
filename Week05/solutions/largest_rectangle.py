class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        
        for i, height in enumerate(heights):
            s = i
            while stack and stack[-1][1] > height:
                idx, h = stack.pop()
                max_area = max(max_area, h * (i - idx))
                s = idx
            stack.append((s, height))
        for idx, h in stack:
            max_area = max(max_area, h * (len(heights) - idx))
        return max_area
