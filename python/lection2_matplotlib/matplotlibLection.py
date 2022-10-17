import matplotlib.pyplot as plt
import numpy as np

# массив координат - 30 точек, равнораспределенных # в диапазоне от 0 до 10
# x = np.linspace(0.0, 10.0, 30)

# массив значений функции в заданных координатах
# y = np.sin(x)
# рисуем график
# plt.plot(x, y)
# показываем график
# plt.show()

# пользовательская переменная для хранения размера шрифта
fsize = 12
# настройка типа шрифта на рисунке с помощью изменения
# записей в словаре rcParams из модуля pyplot
plt.rcParams['font.family'] = 'serif'
plt.rcParams['font.serif'] = 'Times New Roman'

# настройка размера шрифта в различных частях рисунка
# в заголовке:
plt.rcParams['axes.titlesize'] = fsize
# в подписях осей:
plt.rcParams['axes.labelsize'] = fsize
# в подписях меток на осях:
plt.rcParams['xtick.labelsize'] = fsize
plt.rcParams['ytick.labelsize'] = fsize
# в легенде рисунка:
plt.rcParams['legend.fontsize'] = fsize

# массив координат – 50 точек в диапазоне [0, 10]
x = np.linspace(0.0, 10.0, 50)
# создаём окно рисунка
fig = plt.figure()
# аргументы 1, 1, 1 указывают, что на рисунке будет
# только одна панель для рисования графиков
ax=fig.add_subplot(1,1,1)
# кружки (o), соединённые сплошной (-) чёрной линией.
ax.plot(x, np.sin(x), 'ko-', label='1')
# квадратики (s, размером 3), соединённые сплошной (-)
# оранжевой линией толщиной 1.
ax.plot(x,  np.cos(x),  's-',  color='orange',  linewidth=1, markersize=3.0, label='2')
# треугольники (^), соединённые сплошной (-) лиловой линией толщиной 1.
ax.plot(x, (np.sin(x))**2.0, '^-', color='magenta', linewidth=1, label='3')
# чёрная штриховая линия толщиной 1.
# графику присваивается строковый идентификатор ‹x^2’
# для отображения в легенде.
ax.plot(x, (x)**0.15, 'k--', linewidth=1, label=r'$x^2$')
ax.legend(loc='best')
# диапазон отображаемых значений по оси х
ax.set_xlim(-1.0, 11.0)
# диапазон отображаемых значений по оси y
ax.set_ylim(-1.5, 1.5)
# подпись по оси x
ax.set_xlabel(r'$x$')
# подпись по оси y
ax.set_ylabel(r'$f(x)$')
ax.set_title('Мой первый рисунок')
ax.grid()
fig.savefig("fig1.png", orientation='landscape', dpi=300)