import numpy as np
import sys

def gaussElimin(A, b):
    n = len(b)
    for j in range(0, n-1):
        if np.abs(A[j,j] - 0.0) < sys.float_info.epsilon:
            for k in range(j+1, n):
                if np.abs(A[k,j] - 0.0) < sys.float_info.epsilon:
                    temp = np.copy(A[k, :]); tempb = np.copy(b[k])
                    A[k, :] = A[j, :]; b[k] = b[j]
                    A[j, :] = temp; b[j] = tempb
                    break
        for i in range(j+1, n):
            lam = A[i,j]/A[j,j]
            A[i, j+1:n] = A[i, j+1:n] - lam * A[j, j+1:n]
            b[i] = b[i] - lam * b[j]

    print(A)
    print(b)

    if (np.prod(np.diag((np.abs(A)))) - 0.0) < sys.float_info.epsilon:
        print('해가 존재하지 않거나 무수히 많음')
        exit()

    x = np.zeros((n,1))
    x[n-1] = b[n-1] / A[n-1, n-1]
    for i in range(n-2, -1, -1) :
        x[i] = (b[i] - np.dot(A[i, i + 1:n], x[i + 1:n])) / A[i, i]

    return x

A = np.array([[1.0, 2.0, 1.0], [2.0, 1.0, 0.0], [4.0, 2.0, 2.0]])
b = np.array([[4.0], [3.0], [8.0]])
x = gaussElimin(A,b)
print(x)