def build_interference_graph(variables, live_ranges):
    interference_graph = {var: set() for var in variables}
    for live_range in live_ranges:
        for var1 in live_range:
            for var2 in live_range:
                if var1 != var2:
                    interference_graph[var1].add(var2)
                    interference_graph[var2].add(var1)
    return interference_graph

def simplify(interference_graph, total_registers):
    stack = []
    while interference_graph:
        for var in list(interference_graph):
            if len(interference_graph[var]) < total_registers:
                stack.append(var)
                for neighbor in interference_graph[var]:
                    interference_graph[neighbor].discard(var)
                del interference_graph[var]
                break
        else:
            spill(interference_graph, stack)
    return stack

def spill(interference_graph, stack):
    if interference_graph:
        spill_node = next(iter(interference_graph))
        stack.append(spill_node)
        del interference_graph[spill_node]

def select(stack, interference_graph, available_registers):
    register_assignment = {}
    spilled = set()
    for node in stack:
        used_registers = {register_assignment.get(neighbor) for neighbor in interference_graph.get(node, [])}
        for reg in available_registers:
            if reg not in used_registers:
                register_assignment[node] = reg
                break
        else:
            spilled.add(node)
    return register_assignment, spilled

if __name__ == "__main__":
    total_registers = 3
    variables = ["a", "b", "c", "d", "e", "f", "g", "h", "i"]
    live_ranges = [
        ["b", "c"],
        ["a", "e"],
        ["d", "g"],
        ["f", "i"]
    ]
    instructions = [
        "a = b + c",
        "d = a + e",
        "f = d + g",
        "h = f + i"
    ]
    
    available_registers = ["R" + str(i + 1) for i in range(total_registers)]
    interference_graph = build_interference_graph(variables, live_ranges)
    stack = simplify(interference_graph, total_registers)
    register_assignment, spilled = select(stack, interference_graph, available_registers)
    
    print("Instructions:")
    for i, instruction in enumerate(instructions, 1):
        print(f"{i}. {instruction}")

    print("\nRegister Assignment:")
    for var, reg in register_assignment.items():
        print(f"{var} -> {reg}")

    if spilled:
        print("\nSpilled Variables:", spilled)

    print("\nFormatted Output:")
    for i, instruction in enumerate(instructions, 1):
        var_names = instruction.split(" = ")[1].split(" + ")
        reg_values = [
            register_assignment.get(var, f"Memory({var})") for var in var_names + [instruction.split(" = ")[0]]
        ]
        print(f"{i}. {reg_values[2]} = {reg_values[0]} + {reg_values[1]}  ({instruction}), "
              f"{instruction.split(' = ')[0]} in {reg_values[2]}, "
              f"{var_names[0]} in {reg_values[0]}, {var_names[1]} in {reg_values[1]}")
