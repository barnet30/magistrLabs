import numpy as np
from timeit import default_timer as timer

sizeArray = 10
a1 = np.linspace(0,100, sizeArray)
a2 = np.linspace(0,1,sizeArray)

m1 = np.array([a1 for i in range(sizeArray)], dtype=float).transpose()
m2 = np.array([a2 for j in range(sizeArray)], dtype=float)

# print(f"a1 = {a1}")
# print(f"a2 = {a2}")
startTimer = timer()
sumArrays = a1 + a2
endTimer = timer()
print(f"Time for summation with numpy: {endTimer - startTimer}")

sumArraysWithoutNumpy = np.zeros(sizeArray)
startTimer = timer()

for i in range(sizeArray):
    sumArraysWithoutNumpy[i] = a1[i]+a2[i]

endTimer = timer()
print(f"Time for summation without numpy: {endTimer - startTimer}")

# print("\na1 + a2 = ")
# print(sumArraysWithoutNumpy)
startTimer = timer()
multMatrix = m1.dot(m2)
endTimer = timer()
print(f"Time for multiplication with numpy: {endTimer - startTimer}")

startTimer = timer()
result_matrix = [[0 for i in range(sizeArray)] for j in range(sizeArray)]
for i in range(sizeArray):
    for j in range(sizeArray):
        for k in range(sizeArray):
            result_matrix[i][j] += m1[i][k] * m2[k][j]
endTimer = timer()
print(f"Time for multiplication without numpy: {endTimer - startTimer}")

# print(f"m1 = {m1}")
# print(f"m2 = {m2}")
#
# print(m1.dot(m2))
