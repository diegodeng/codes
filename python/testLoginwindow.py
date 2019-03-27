#!/usr/bin/python3

import tkinter as tk

window = tk.Tk()
window.title('my window')



# welcome image
canvas = tk.Canvas(window, height=200, width=500)#创建画布
image_file = tk.PhotoImage(file='welcom.gif')#加载图片文件
image = canvas.create_image(0,0, anchor='nw', image=image_file)#将图片置于画布上
canvas.pack(side='top')#放置画布（为上端）

# user information
tk.Label(window, text='User name: ').place(x=50, y= 150)#创建一个`label`名为`User name: `置于坐标（50,150）
tk.Label(window, text='Password: ').place(x=50, y= 190)

var_usr_name = tk.StringVar()#定义变量
var_usr_name.set('example@python.com')#变量赋值'example@python.com'
entry_usr_name = tk.Entry(window, textvariable=var_usr_name)#创建一个`entry`，显示为变量`var_usr_name`即图中的`example@python.com`
entry_usr_name.place(x=160, y=150)
var_usr_pwd = tk.StringVar()
entry_usr_pwd = tk.Entry(window, textvariable=var_usr_pwd, show='*')#`show`这个参数将输入的密码变为`***`的形式
entry_usr_pwd.place(x=160, y=190)

def usr_login():
    pass
def usr_sign_up():
    pass


# login and sign up button
btn_login = tk.Button(window, text='Login', command=usr_login)#定义一个`button`按钮，名为`Login`,触发命令为`usr_login`
btn_login.place(x=170, y=230)
btn_sign_up = tk.Button(window, text='Sign up', command=usr_sign_up)
btn_sign_up.place(x=270, y=230)


window.mainloop()
