import numpy as np
# matrix = np.array([[1, 2, 3], [4, 5, 6]])
# print(matrix)
# # add
# result = matrix + matrix
# print(result)
# # multiply
# print(matrix.T)
# result = np.dot(matrix, matrix.T)
# print(result)

# structure matrix
arr1 = np.array([1, 2, 3, 4, 5])
print(arr1)

arr = np.zeros((2, 3))
print(arr)

arr = np.ones((3, 4))
print(arr)

result = arr + arr
print(result)

# dot product
result = np.dot(arr, arr.T)
print(result)

print(arr[0, 0])