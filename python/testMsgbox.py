#!/usr/bin/python3

import tkinter as tk
import tkinter.messagebox

window = tk.Tk()
window.title('my window')
window.maxsize(300, 240)
window.minsize(300, 240)

def hit_me():
    tk.messagebox.showinfo(title='Hi', message='hahahaha')   # return 'ok'
    tk.messagebox.showwarning(title='Hi', message='nononono')   # return 'ok'
    tk.messagebox.showerror(title='Hi', message='No!! never')   # return 'ok'
    print(tk.messagebox.askquestion(title='Hi', message='hahahaha'))   # return 'yes' , 'no'
    print(tk.messagebox.askyesno(title='Hi', message='hahahaha'))   # return True, False
    #print(tk.messagebox.asktrycancel(title='Hi', message='hahahaha'))   # return True, False
    #print(tk.messagebox.askokcancel(title='Hi', message='hahahaha'))   # return True, False
    #print(tk.messagebox.askyesnocancel(title="Hi", message="haha"))     # return, True, False, None

tk.Button(window, text='hit me', command=hit_me).pack()

window.mainloop()
