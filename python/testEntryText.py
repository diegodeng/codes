#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')
window.maxsize(300, 240)
window.minsize(300, 240)


e = tk.Entry(window,show=None)

e.pack()

def insert_point():
    var = e.get()
    t.insert('insert',var)


def insert_end():
    var = e.get()
    t.insert('end',var)
b1 = tk.Button(window,
              text='insert point',
              width=15,height=2,
              command=insert_point)

b1.pack()

b1 = tk.Button(window,
              text='insert end',
              width=15,height=2,
              command=insert_end)

b1.pack()

t = tk.Text(window,height=2)
t.pack()

window.mainloop()
