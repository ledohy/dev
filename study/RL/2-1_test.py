import gymnasium as gym
import numpy as np

env = gym.make('FrozenLake-v1', render_mode = 'ansi', is_slippery = False)

state, info = env.reset()
while True:
	action = np.random.choice([0,1,2,3], 1, p=[0.25, 0.25, 0.25, 0.25])[0]
	state1, reward, terminated, truncated, info = env.step(action)
	state = state1
	print(env.render())
	if terminated or truncated:
		break
	
env.close()
