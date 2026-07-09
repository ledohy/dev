import gymnasium as gym
import numpy as np

gamma = 0.9

def policy_iteration(env):
    V = np.zeros(env.observation_space.n)
    pi = [0 for i in range(env.observation_space.n)]
    while True:
        oldV = V.copy()