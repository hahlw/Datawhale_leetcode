# 2019-07-15 Mon

# Graph by gulshan98125

""" 
Inf                                      Inf
|                   Peak                  |
|       Peak          |                   |
|         |           | |                 |
|       | |           | | |               |
|     | | | |       | | | | |     | | |   |
|   | | | | | |   | | | | | | |   | | |   |
| _ | | | | | | | | | | | | | | _ | | | | |
-------------------------------------------
* 0 2 3 4 5 3 2 1 2 3 6 5 4 3 2 0 3 3 3 1 *
i=0 1 2 3 4 5 6 7 8 9...             ...19
  ^		        ^               ^   ^   ^
  P1		    P2              P3  P4  P5

 """

# 扫一遍的亲情况下，记录下升跟降的次数，最后加上底数1

class Solution:
    def candy(self, ratings: List[int]) -> int:
        sum = 0
        pre = 1
        des = 0
        l = len(ratings)
        for i in range(l):
            if i == 0 or ratings[i] < ratings[i-1]:
                des += 1
                if pre > 1:
                    pre -= 1
                    sum += pre
                else:
                    sum += des
            else:
                if i-1 == 0 or ratings[i-1] < ratings[i-2]:
                    sum -= (des-1)*(pre-1)
                    pre = 1
                des = 1
                if ratings[i] > ratings[i-1]:
                    pre += 1
                else:
                    pre = 1
                sum += pre
        if l > 2 and ratings[l-1] < ratings[i-2]:
            sum -= (des - 1)*(pre - 1)
        return sum