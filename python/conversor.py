import math
from tkinter import *
import tkinter.messagebox as messagebox

color_fondo = '#eba234'
color_cuadro_texto = '#e3d2b8'

def bi_to_po():
    try:
        real = float(txt1.get())
        imaginario = float(txt2.get())
        modulo = math.sqrt(real**2+imaginario**2)

        modulo = float("{0:.3f}".format(modulo))
        if modulo.is_integer():
            modulo = int(modulo)
        txt3.set(str(modulo))
        
        angulo = math.atan(imaginario/real)*180/math.pi
        angulo = float("{0:.3f}".format(angulo))
        if angulo.is_integer():
            angulo = int(angulo)
        txt4.set(str(angulo))
    except:
        messagebox.showinfo(message="Formato no disponible", title="Error")

def po_to_bi():
    try:
        modulo = float(txt3.get())
        angulo = float(txt4.get())
        real = modulo*math.cos(math.radians(angulo))
        real = float("{0:.3f}".format(real))
        if real.is_integer():
            real = int(real)
        txt1.set(str(real))
        
        imaginario = modulo*math.sin(math.radians(angulo))
        imaginario = float("{0:.3f}".format(imaginario))
        if imaginario.is_integer():
            imaginario = int(imaginario)
        txt2.set(str(imaginario))
    except:
        messagebox.showinfo(message="Formato no disponible", title="Error")

wn = Tk()
wn.geometry("600x220")
wn.title("Conversor números complejos by Dardo")
wn.configure(bg=color_fondo)

Label(wn, text="Binomial",bg=color_fondo).place(x=20,y=10)
Label(wn, text="Polar",bg=color_fondo).place(x=20,y=110)

txt1 = StringVar()
Entry(wn, textvariable=txt1,justify='center',bg=color_cuadro_texto).place(x=20,y=30,width=200,height=30)
txt2 = StringVar()
Entry(wn, textvariable=txt2,justify='center',bg=color_cuadro_texto).place(x=310,y=30,width=200,height=30)
txt3 = StringVar()
Entry(wn, textvariable=txt3,justify='center',bg=color_cuadro_texto).place(x=20,y=130,width=200,height=30)
txt4 = StringVar()
Entry(wn, textvariable=txt4,justify='center',bg=color_cuadro_texto).place(x=310,y=130,width=200,height=30)

Label(wn,text="Reales",bg=color_fondo).place(x=220,y=35)
Label(wn,text="Imaginarios",bg=color_fondo).place(x=510,y=35)
Label(wn,text="módulo",bg=color_fondo).place(x=220,y=135)
Label(wn,text="grados",bg=color_fondo).place(x=510,y=135)

Button(wn, text="Convertir", command=bi_to_po, bg="#eb4034").place(x=20,y=70,width=560,height=30)
Button(wn, text="Convertir", command=po_to_bi, bg="#eb4034").place(x=20,y=170,width=560,height=30)

wn.mainloop()