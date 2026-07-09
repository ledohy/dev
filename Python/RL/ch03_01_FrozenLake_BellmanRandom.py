import gymnasium as gym
import numpy as np

gamma = 0.9

def policy_evaluation(env, policy):
    n = env.observation_space.n

    V = np.zeros(n)
    while True:
        oldV = V.copy()
        for state in range(n):
            v = 0
            for action, action_prob in enumerate(policy[state]):
                prob, next_state, reward, terminated = env.unwrapped.P[state][action][0]
                v = v + action_prob * (reward+gamma*V[next_state])
            V[state] = v
        if max(np.abs(V-oldV)) < 1e-8:
            break
    return V

def main():
    env = gym.make('FrozenLake-v1', is_slippery=False, render_mode='ansi')
    pi1 = np.ones((env.observation_space.n, env.action_space.n)) / env.action_space.n
    V = policy_evaluation(env, pi1)
    print('랜덤정책 pi1의 가치 함수:\n', np.round(V.reshape([4,4]),4))

if __name__ == "__main__":
    main()