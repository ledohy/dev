import gymnasium as gym
import numpy as np

env = gym.make('FrozenLake-v1', render_mode='ansi', is_slippery=False)
env = gym.wrappers.TimeLimit(env, max_episode_steps=100)
state, info = env.reset()

print(info)