import numpy as np

my_list = [1, 2, 3, 4, 5, 6]
arr = np.array(my_list)
print(arr)
print(type(arr))

data = np.loadtxt('Lection1_Numpy/data.txt', comments='#', usecols=(0,1,2))
print(data)
print(data[:,2])