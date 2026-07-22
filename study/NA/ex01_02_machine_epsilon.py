meps = 1.0

while 1 + meps > 1.0:
    meps = meps / 2

meps = meps * 2.0
print(meps)

import sys
print(sys.float_info.epsilon)

print(0.1 + 0.2 == 0.3)
print(0.1 + 0.2)

import math
print(math.fabs((0.1+0.2) - 0.3) <= sys.float_info.epsilon)