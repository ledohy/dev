import numpy as np
import sys


def gaussJordan(A):
    n = len(A)
    aug = np.hstack([A, np.eye(n)])

    for j in range(0, n):
        p = np.argmax(np.abs(aug[j:n, j])) + j
        if np.abs(aug[p, j]) < sys.float_info.epsilon:
            print("역행렬이 존재하지 않음")
            exit()

        aug[[j, p]] = aug[[p, j]]

        aug[j, :] = aug[j, :] / aug[j, j]

        for i in range(0, n):
            if i != j:
                lam = aug[i, j]
                aug[i, j:2 * n] = aug[i, j:2 * n] - lam * aug[j, j:2 * n]

    invA = aug[:, n:2 * n]
    return invA

A = np.array([[1.0, 3.0, -2.0], [2.0, 6.0, -2.0], [0.0, 1.0, 1.0]])

invA = gaussJordan(A)

print(invA)