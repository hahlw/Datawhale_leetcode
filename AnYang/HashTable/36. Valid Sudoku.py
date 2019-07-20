# 2019-07-20 Sat

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Row
        for i in board:
            if "." in i:
                if 9 - i.count(".") + 1 != len(set(i)):    
                    return False
            elif len(set(i)) != len(i):
                return False
        # Col
        for j in range(9):
            refCol = []
            for i in range(9):
                refCol.append(board[i][j])
            if "." in refCol:
                if 9 - refCol.count(".") + 1 != len(set(refCol)):                
                    return False
            elif len(set(refCol)) != 9:
                return False
            
        for i in range(0, 7, 3):
            for j in range(0, 7, 3):
                if not self.filter3by3(i,j,board):
                    return False
        return True
    def filter3by3(self, i,j, board):
        ref3by3 = [board[i][j], board[i][j+1], board[i][j+2],
              board[i+1][j], board[i+1][j+1], board[i+1][j+2], 
              board[i+2][j], board[i+2][j+1], board[i+2][j+2]]
        if "." in ref3by3:
            if 9 - ref3by3.count(".") + 1 != len(set(ref3by3)):   
                return False
        elif len(set(ref3by3)) != len(ref3by3):
            return False
        return True