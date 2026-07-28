import gymnasium as gym
import numpy as np

gamma = 0.9

def policy_iteration(env):
	V = np.zeros(env.observation_space.n)
	pi = [0 for _ in range(env.observation_space.n)]
	while True:
		while True:
			oldV = V.copy()
			for s in range(env.observation_space.n):
				a = pi[s]
				p, s_next, r, terminated = env.unwrapped.P[s][a][0]
				V[s] = r + gamma*V[s_next]
			if max(np.abs(V-oldV)) < 1e-8:
				break

		old_pi = pi.copy() #전체를 한 번 복사해두는 방식! 스케일이 커지면 비효율적일지도
		for s in range(env.observation_space.n):
			q = np.zeros(env.action_space.n)
			for a in range(env.action_space.n):
				p, s_next, r, terminated = env.unwrapped.P[s][a][0]
				q[a] = r + gamma*V[s_next]
			pi[s] = np.argmax(q)
			if pi != old_pi:
				converged = False
		if old_pi == pi:
			return V, pi

def main():
	env = gym.make("FrozenLake-v1", is_slippery=False, render_mode="ansi")
	V, pi = policy_iteration(env)
	print("최적 정책:\n", np.array(pi).reshape([4,4]))
	print("최적 가치함수:\n", np.round(V.reshape([4,4]),4))

if __name__ == "__main__":
	main()
