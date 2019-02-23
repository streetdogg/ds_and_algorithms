#!/bin/python3

'''
Solves the n queens problem in n^n time :(
TODO: improve the runtime complexity
'''

import sys

QUEEN = 'X'
BLANK = '-'

def main():
    if len(sys.argv) != 2:
        print ("usage: python3 n_queens.py BoardSize")
        return
    board_size = int(sys.argv[1])
    q = queen(board_size)
    q.solve()
    q.print_runtime_compltexity()

class queen:
    def __init__(self, board_size):
        '''
        Setup the board
        '''
        self.board_size = board_size
        self.board = []
        self.runtime_complexity = 0

        for i in range(0, self.board_size):
            l = []
            for j in range(0, self.board_size):
                l.append(BLANK)

            self.board.append(l)

    def print_board(self):
        '''
        Print the board
        '''
        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                print("{} ".format(self.board[i][j]), end="")
            print("")

    def print_runtime_compltexity(self):
        '''
        print the runtime complexity for given size of problem
        '''
        print ("----------------------------")
        print ("Board Size: {}, Runtime: {}".format(self.board_size, self.runtime_complexity))
        print ("----------------------------")

    def solve(self):
        '''
        Trigger the solving of puzzle
        '''
        for j in range(0, self.board_size):
            if self.move_queen(0, j):
                break
            else:
                self.undo_move(0, j)
                j+=1

        self.print_board()
        return

    def place_queen(self, a, b):
        self.runtime_complexity += 1
        '''
        Mark the position in board with presence of the queen
        '''
        self.board[a][b] = QUEEN

    def undo_move(self, a, b):
        '''
        Clear the position. Remove existance of the Queen from the provided position.
        '''
        self.board[a][b] = BLANK

    def valid_vertical(self, a, b):
        '''
        Check for the presence of a Queen in the column
        '''
        i = a - 1

        while (i>=0):
            if (self.board[i][b] == QUEEN):
                return False
            i -= 1

        return True

    def valid_r_diagonal(self, a, b):
        '''
        Check for existance of another queen in diagonal going from left bottom
        to right top.
        '''
        i = a - 1
        j = b + 1

        while (i >= 0 and j < self.board_size):
            if self.board[i][j] == QUEEN:
                return False

            i -= 1
            j += 1

        return True

    def valid_l_diagonal(self, a, b):
        '''
        Check for existance of another queen in diagonal going from right bottom
        to left top.
        '''
        i = a - 1
        j = b - 1

        while (i>=0 and j >= 0):
            if self.board[i][j] == QUEEN:
                return False

            i -= 1
            j -= 1

        return True

    def valid_move(self, a, b):
        '''
        Check if the queen being placed at a given position is not attacked by
        any other queen
        '''
        if self.valid_vertical(a, b) and self.valid_r_diagonal(a, b) and self.valid_l_diagonal(a, b):
            return True

        return False

    def move_queen(self, a, b):
        '''
        move queen to provided location
        '''
        if a == self.board_size:
            return True

        self.place_queen(a, b)
        if not self.valid_move(a, b):
            self.undo_move(a, b)
            return False
        else:
            for i in range(0, self.board_size):
                if self.move_queen(a+1, i):
                    return True
                else:
                    self.undo_move(a+1, i)
                    i += 1
            return False

if __name__ == '__main__':
    main()