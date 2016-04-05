#!/usr/bin/python

import Tkinter as tk
import random
import sys

class Board(tk.Frame):
    def __init__(self, parent, rows=8, columns=8, size=16, speed=100):
        '''size is the size of a square, in pixels'''

        self.rows = rows
        self.columns = columns
        self.size = size
        self.speed = speed
        self.board = [[0 for x in range(columns)] for x in range(rows)]

        canvas_width = columns * size
        canvas_height = rows * size

        tk.Frame.__init__(self, parent)
        self.canvas = tk.Canvas(self, borderwidth=0, highlightthickness=0,
                                width=canvas_width, height=canvas_height, background="bisque")
        self.canvas.pack(side="top", fill="both", expand=True)
        self.canvas.bind("<Configure>", self.refresh)
        self.after(self.speed, self.update)

    def update(self):
        '''Read the board from stdin'''
        for row in xrange(self.rows):
            values = sys.stdin.readline()
            for col in xrange(self.columns):
                self.board[row][col] = int(values[col])

        self.refresh()
        self.after(self.speed, self.update)

    def refresh(self, event=None):
        '''Redraw the board, possibly in response to window being resized'''
        if event:
            xsize = int((event.width) / self.columns)
            ysize = int((event.height) / self.rows)
            self.size = min(xsize, ysize)
            self.canvas.delete("square")

        self.canvas.delete("live")

        for row in range(self.rows):
            for col in range(self.columns):
                x1 = (col * self.size)
                y1 = (row * self.size)
                x2 = x1 + self.size
                y2 = y1 + self.size

                if event:
                    self.canvas.create_rectangle(x1, y1, x2, y2, outline="black", tags="square")

                if self.board[row][col] == 1:
                    self.canvas.create_rectangle(x1, y1, x2, y2, outline="black", fill="black", tags="live")

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Conway's Game of Life")

    board = Board(root, rows=int(sys.argv[1]), columns=int(sys.argv[2]), speed=int(sys.argv[3]))
    board.pack(side="top", fill="both", expand=True)

    root.mainloop()