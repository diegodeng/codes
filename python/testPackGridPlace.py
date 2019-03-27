#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')
window.maxsize(300, 240)
window.minsize(300, 240)



#tk.Label(window,text=1).pack(side='top')
#tk.Label(window,text=1).pack(side='bottom')
#tk.Label(window,text=1).pack(side='left')
#tk.Label(window,text=1).pack(side='right')

#for i in range(4):
#    for j in range(3):
#        tk.Label(window, text=1).grid(row=i, column=j, padx=30, pady=12)


tk.Label(window, text=1).place(x=20, y=40, anchor='nw')

window.mainloop()
