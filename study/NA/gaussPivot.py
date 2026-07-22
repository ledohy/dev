import numpy as np
import sys

def gaussElimin(A, b):
    n = len(b)
    for j in range(0, n - 1):

        p = np.argmax(np.abs(A[j:n, j])) + j
        if np.abs(A[p, j]) < sys.float_info.epsilon:
            print("Pivot is zero!")

        if p != j:
            A[[j, p]] = A[[p, j]]
            b[[j, p]] = b[[p, j]]

        for i in range(j + 1, n):
            lam = A[i, j] / A[j, j]
            A[i, j + 1:n] = A[i, j + 1:n] - lam * A[j, j + 1:n]
            b[i] = b[i] - lam * b[j]

    x = np.zeros((n, 1))
    x[n - 1] = b[n - 1] / A[n - 1, n - 1]
    for i in range(n - 2, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:n], x[i + 1:n])) / A[i, i]
    return x


# 문제 데이터
A = np.array([[1.0, -3.0, 3.0], [-3.0, 2.0, 3.0], [-1.0, 2.0, -1.0]])
b = np.array([[-6.0], [-13.0], [3.0]])

x = gaussElimin(A, b)
print(x)