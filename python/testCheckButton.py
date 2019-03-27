#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')
window.maxsize(300, 240)
window.minsize(300, 240)

l = tk.Label(window, bg='yellow', width=20, text='empty')
l.pack()


def print_selection():
    if (var1.get() == 1) & (var2.get() == 0):   #如果选中第一个选项，未选中第二个选项
        l.config(text='I love only Python ')
    elif (var1.get() == 0) & (var2.get() == 1): #如果选中第二个选项，未选中第一个选项
        l.config(text='I love only C++')
    elif (var1.get() == 0) &(var2.get() == 0):  #如果两个选项都未选中
        l.config(text='I do not love either')
    else:
        l.config(text='I love both')             #如果两个选项都选中

     
var1 = tk.IntVar()
var2 = tk.IntVar()
c1 = tk.Checkbutton(window, text='Python', variable=var1, onvalue=1, offvalue=0,
                    command=print_selection)



c2 = tk.Checkbutton(window, text='c++', variable=var2, onvalue=1, offvalue=0,
                    command=print_selection)

c1.pack()
c2.pack()


window.mainloop()
