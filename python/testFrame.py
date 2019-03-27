#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')
window.maxsize(300, 240)
window.minsize(300, 240)

tk.Label(window, text='on the window').pack()

frm = tk.Frame(window)
frm.pack()
frm_l = tk.Frame(frm, )
frm_r = tk.Frame(frm)
frm_l.pack(side='left')
frm_r.pack(side='right')

tk.Label(frm_l, text='on the frm_l1').pack()
tk.Label(frm_l, text='on the frm_l2').pack()
tk.Label(frm_r, text='on the frm_r1').pack()

window.mainloop()
