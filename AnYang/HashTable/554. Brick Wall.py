# 2019-07-27 Sat

class Solution:
    def leastBricks(self, wall):
        que, res = [], len(wall)
        for i in range(len(wall)): 
            heapq.heappush(que, (wall[i][0], i, 0))
        while que:
            acc, i, j = heapq.heappop(que)
            cnt = 1
            if j + 1 < len(wall[i]): 
                heapq.heappush(que, (acc + wall[i][j+1], i, j + 1))
            while que and acc == que[0][0]:
                _, i, j = heapq.heappop(que)
                cnt += 1
                if j + 1 < len(wall[i]): 
                    heapq.heappush(que, (acc + wall[i][j+1], i, j + 1))
            if que: 
                res = min(res, len(wall) - cnt)
        return res



# class Solution:
#     def leastBricks(self, wall):
#         mx = 0
#         m = {}
#         for a in range(wall):
#             sum = 0
#             for i in len(a):
#                 sum += a[i]
#                 m[sum] += 1
#                 mx = max(mx, m[sum])
#         return wall.size() - mx