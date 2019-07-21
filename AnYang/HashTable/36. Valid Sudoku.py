# 2019-07-20 Sat

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Row
        for i in board:
            if "." in i:
                if 10 - i.count(".") != len(set(i)):    
                    return False
            elif len(set(i)) != len(i):
                return False
        # Col
        for j in range(9):
            refCol = []
            for i in range(9):
                refCol.append(board[i][j])
            if "." in refCol:
                if 10 - refCol.count(".") != len(set(refCol)):                
                    return False
            elif len(set(refCol)) != 9:
                return False
            
        range33 = [0,3,6]
        for i in range33:
            for j in range33:
                ref3by3 = board[i][j:j+3] + board[i+1][j:j+3] + board[i+2][j:j+3]
                if "." in ref3by3:
                    if 10 - ref3by3.count(".") != len(set(ref3by3)):   
                        return False
                elif len(set(ref3by3)) != len(ref3by3):
                    return False
        return True

""" S2 """
# class Solution:
#     def isValidSudoku(self, board: List[List[str]]) -> bool:
#         grid = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
#         row = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
#         colum = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
        
#         for i, board_row in enumerate(board):
#             for j, item in enumerate(board_row):
#                 if item == '.':
#                     continue
#                 elif item in grid[int(i/3)*3 + (int)(j/3)]:
#                     return False
#                 elif item in row[i]:
#                     return False
#                 elif item in colum[j]:
#                     return False
#                 else:
#                     grid[int(i/3)*3 + (int)(j/3)][item] = '{}, {}'.format(i, j)
#                     row[i][item] = ''
#                     colum[j][item] = ''
#         return True

