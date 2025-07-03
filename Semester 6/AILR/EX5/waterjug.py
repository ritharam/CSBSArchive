from math import gcd
from collections import deque

def water_jug(m, n, d):
    if d > max(m, n) or d % gcd(m, n) != 0:
        print("No solution")
        return -1
    visited = set()
    parent = {}
    queue = deque()
    queue.append((0, 0, 0))  # (jug1, jug2, steps)
    visited.add((0, 0))
    parent[(0, 0)] = None
    while queue:
        j1, j2, step = queue.popleft()
        
        if j1 == d or j2 == d:
            # Reconstruct and print path
            path = []
            state = (j1, j2)
            while state is not None:
                path.append(state)
                state = parent[state]
            path.reverse()
            print("Steps to reach", d, "liters:")
            for i, p in enumerate(path):
                print(f"Step {i}: {p}")
            return step

        next_states = []
        next_states.append((m, j2))  # Fill Jug 1
        next_states.append((j1, n))  # Fill Jug 2
        # Empty jugs
        next_states.append((0, j2))  # Empty Jug 1
        next_states.append((j1, 0))  # Empty Jug 2
        # Pour Jug1 -> Jug2
        p1_2 = min(j1, n - j2)
        next_states.append((j1 - p1_2, j2 + p1_2))
        # Pour Jug2 -> Jug1
        p2_1 = min(j2, m - j1)
        next_states.append((j1 + p2_1, j2 - p2_1))

        for state in next_states:
            if state not in visited:
                visited.add(state)
                parent[state] = (j1, j2)
                queue.append((*state, step + 1))

    print("No solution")
    return -1
m, n, d = 4, 3, 2
steps = water_jug(m, n, d)
print(f"\nTotal Steps: {steps}")