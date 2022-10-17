import matplotlib.pyplot
import matplotlib.pyplot as plt
import numpy as np
from math import pi

# пользовательская переменная для хранения размера шрифта
fsize = 12

fig, ((a1,a2),(a3,a4)) = plt.subplots(2,2)
a1.set_title("(a)")
a2.set_title("(б)")
a3.set_title("(в)")
a4.set_title("(г)")

# настройка типа шрифта на рисунке с помощью изменения
# записей в словаре rcParams из модуля pyplot
matplotlib.pyplot.rcParams['font.family'] = 'serif'
matplotlib.pyplot.rcParams['font.serif'] = 'Times New Roman'

# настройка размера шрифта в различных частях рисунка
# в заголовке:
matplotlib.pyplot.rcParams['axes.titlesize'] = fsize
# в подписях осей:
matplotlib.pyplot.rcParams['axes.labelsize'] = fsize
# в подписях меток на осях:
matplotlib.pyplot.rcParams['xtick.labelsize'] = fsize
matplotlib.pyplot.rcParams['ytick.labelsize'] = fsize
# в легенде рисунка:
matplotlib.pyplot.rcParams['legend.fontsize'] = fsize

# массив координат – 50 точек в диапазоне [0, 10]
x = np.linspace(0.0, 10.0, 50)


# график sin(x)
# только одна панель для рисования графиков
# кружки (o), соединённые сплошной (-) чёрной линией.
a1.plot(x, np.sin(x), '-', color="black", label='1')
a1.set_xlim(0, 2*pi)
a1.set_ylim(-1.1, 1.1)

# график cos(x)
# квадратики, соединённые пунктиром (:)
# оранжевой линией толщиной 1.
a2.plot(x,  np.cos(x),  ':',  color='black',  linewidth=1, markersize=3.0, label='2')
a2.set_xlim(0, 2*pi)
a2.set_ylim(-1.1, 1.1)

# график (sin(x))^2
# соединённые штриховой (--) чёрной линией толщиной 1.
a3.plot(x, (np.sin(x))**2.0, '--', color='black', linewidth=1, label='3')
a3.set_xlim(0, 2*pi)
a3.set_ylim(-1.1, 1.1)

# график x^0.15
# серая сполшная линия толщиной 1.
# графику присваивается строковый идентификатор ‹x^2’
# для отображения в легенде.
a4.plot(x, (x)**0.15, '--', color="grey", linewidth=1, label=r'$x^2$')
a4.set_xlim(0, 2*pi)
a4.set_ylim(-1.1, 1.1)


#ax.grid()
fig.savefig("fig2.png", orientation='landscape', dpi=300)