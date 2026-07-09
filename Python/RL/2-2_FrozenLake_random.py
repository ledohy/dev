import gymnasium as gym
import numpy as np

n = 100000

env = gym.make('FrozenLake-v1', is_slippery=False, render_mode='ansi')
env = gym.wrappers.TimeLimit(env, max_episode_steps=100)
episodes = []
for _ in range(n):
    epi = []
    state, info = env.reset()
    epi.append([None, state])
    while True:
        action = np.random.choice([0,1,2,3], 1, p=[0.25, 0.25, 0.25, 0.25])[0]
        state1, reward, terminated, truncated, info = env.step(action)
        state = state1
        epi.append([action, reward, state])
        if terminated or truncated:
            break
    episodes.append(epi)

env.close()

expected_return = sum([e[-1][1] for e in episodes]) / n
print('랜덤 정책의 기대 이득 =', expected_return)