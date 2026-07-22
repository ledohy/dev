# 입력 : SPD 행렬 A, 초기벡터 x, 허용오차 tol, 최대 반복횟수 kmax, 완화변수 w
# 출력 : 근사해 approx
import numpy as np

def SOR(A, b, x, kmax, tol, w):
    r = b - np.matmul(A, x)
    rnorm = np.linalg.norm(r)
    bnorm = np.linalg.norm(b)
    n = len(A)
    xnew = np.copy(x)
    k = 1
    print('k \t\t 근사해')
    while ((rnorm > (tol * bnorm)) and (k <= kmax)):
        for i in range(0, n):
            Lsum = np.dot(A[i, 0:i], xnew[0:i])
            # Lsum = np.matmul([A[i, 0:i], x[0:i])
            Usum = np.dot(A[i, i:n], x[i:n])
            xnew[i] = x[i] + w*(b[i] - Lsum - Usum) / A[i, i]
        print('k={0} \t  x={1}'.format(k, xnew))
        x = np.copy(xnew)
        r = b - np.matmul(A, x)
        rnorm = np.linalg.norm(r)
        k = k+1
    approx = x
    return approx

A = np.array([ [8.0, 2.0, -4.0], [5.0, 10.0, -3.0], [-1.0, 5.0, 20.0] ])
b = np.array([6.0, 12.0, 24.0])
x = np.array([0.0, 0.0, 0.0])
kmax = 10
tol = 0.0001
w = 1.25
approx = SOR(A, b, x, kmax, tol, w)
print(approx)