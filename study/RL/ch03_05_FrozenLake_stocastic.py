import gymnasium as gym
import numpy as np

gamma = 0.9

def value_iteration(env):
    V = np.zeros(env.observation_space.n)
    while True:
        oldV = V.copy()
        for state in range(env.observation_space.n):
            q = np.zeros(env.action_space.n)
            for action in range(env.action_space.n):
                for prob, next_state, reward, terminated in env.unwrapped.P[state][action]:
                    q[action] = q[action] + prob*(reward+gamma*V[next_state])
                V[state] = np.max(q)
        if max(np.abs(V-oldV)) < 1e-8:
            break

    pi = env.observation_space.n*[None]
    for state in range(env.observation_space.n):
        q = np.zeros(env.action_space.n)
        for action in range(env.action_space.n):
            for prob, next_state, reward, terminated in env.unwrapped.P[state][action]:
                q[action] = q[action] + prob*(reward + gamma*V[next_state])
            pi[state] = np.argmax(q)
        return pi, V

def main():
    env = gym.make("FrozenLake-v1", is_slippery=True, render_mode="ansi")
    pi, V = value_iteration(env)
    print("최적 정책:\n", np.array(pi).reshape([4,4]))
    print("최적 가치 함수:\n", np.round(V.reshape([4,4]),4))

if __name__ == "__main__":
    main()
