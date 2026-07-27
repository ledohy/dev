import gymnasium as gym
import numpy as np

gamma = 0.9

def policy_evaluation(env, policy):
	n = env.observation_space.n
	V = np.zeros(n)
	while True:
		oldV = V.copy()
		for s in range(n):
			v = 0
			for a, ap in enumerate(policy[s]):
				p, s_nxt, r, end = env.unwrapped.P[s][a][0]
				v = v + ap * (r + gamma*V[s_nxt])
			V[s] = v
		if max(abs(V-oldV)) < 1e-8:
			break
	return V

env = gym.make("FrozenLake-v1", is_slippery=False, render_mode="ansi")
pi1 = np.ones((env.observation_space.n,env.action_space.n)) / env.action_space.n
V = policy_evaluation(env, pi1)
print("랜덤정책 pi1의 가치함수:\n", np.round(V.reshape([4,4]),4))
