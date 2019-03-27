#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')

def get_screen_size(window):
    return window.winfo_screenwidth(),window.winfo_screenheight()

def get_window_size(window):
    return window.winfo_reqwidth(),window.winfo_reqheight()
 
def center_window(root, width, height):
    screenwidth = root.winfo_screenwidth()
    screenheight = root.winfo_screenheight()
    size = '%dx%d+%d+%d' % (width, height, (screenwidth - width)/2, (screenheight - height)/2)
    print(size)
    root.geometry(size)


center_window(window, 300, 240)
window.maxsize(300, 240)
window.minsize(300, 240)

var = tk.StringVar()
l = tk.Label(window,
         #text = 'OMG:this is TK!',
         textvariable=var,
         bg='green',
         font=('Arial',12),
         width = 15,height=2)

l.pack()

on_hit = False
def hit_me():
    global on_hit
    
    if on_hit == False:
        on_hit = True
        var.set('you hit me')
    else:
        on_hit = False
        var.set("")
        
b = tk.Button(window,
              text='hit me',
              width=15,height=2,
              command=hit_me)

b.pack()


window.mainloop()
