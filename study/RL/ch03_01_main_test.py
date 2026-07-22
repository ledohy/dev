import ch03_01_FrozenLake_BellmanRandom as pre
import gymnasium as gym
import numpy as np

def main():
    env = gym.make("FrozenLake-v1", is_slippery=False, render_mode="ansi")
    pi1 = np.ones((env.observation_space.n, env.action_space.n)) / env.action_space.n
    V = pre.policy_evaluation(env, pi1)
    print("랜덤정책 pi1의 가치함수:\n", np.round(V.reshape([4,4]),4))

if __name__ == "__main__":
    main()