class RegisterAllocator:
    def __init__(self, total_registers):
        self.total_registers = total_registers
        self.interference_graph = {}
        self.stack = []
        self.spilled = set()
        self.register_assignment = {}
        self.available_registers = ["R" + str(i + 1) for i in range(total_registers)]

    def build_interference_graph(self, variables, live_ranges):
        for var in variables:
            self.interference_graph[var] = set()
        for live_range in live_ranges:
            for var1 in live_range:
                for var2 in live_range:
                    if var1 != var2:
                        self.interference_graph[var1].add(var2)
                        self.interference_graph[var2].add(var1)

    def simplify(self):
        removed = True
        while removed:
            removed = False
            for var in list(self.interference_graph):
                if len(self.interference_graph[var]) < self.total_registers:
                    self.stack.append(var)
                    for neighbor in self.interference_graph[var]:
                        self.interference_graph[neighbor].discard(var)
                    del self.interference_graph[var]
                    removed = True

    def spill(self):
        if self.interference_graph:
            spill_node = next(iter(self.interference_graph))
            self.spilled.add(spill_node)
            del self.interference_graph[spill_node]

    def select(self):
        while self.stack:
            node = self.stack.pop()
            used_registers = set()
            for neighbor in self.interference_graph.get(node, set()):
                if neighbor in self.register_assignment:
                    used_registers.add(self.register_assignment[neighbor])
            for reg in self.available_registers:
                if reg not in used_registers:
                    self.register_assignment[node] = reg
                    break
            else:
                self.spilled.add(node)

    def output(self, instructions):
        print("INPUT/OUTPUT:")
        for index, instruction in enumerate(instructions):
            print(f"{index + 1}. {instruction}")

        print("\nRegister Assignment:")
        for var, reg in self.register_assignment.items():
            print(f"Variable {var} is in {reg}")

        if self.spilled:
            print("Spilled Variables:", self.spilled)

        print("\nFormatted Output:")
        for index, instruction in enumerate(instructions):
            inst_vars = instruction.split(" = ")[1].replace("+", "").split()
            a, b = inst_vars[0], inst_vars[1]
            c = instruction.split(" = ")[0]

            reg_a = self.register_assignment.get(a, f"Memory({a})")
            reg_b = self.register_assignment.get(b, f"Memory({b})")
            reg_c = self.register_assignment.get(c, f"Memory({c})")

            print(f"{index + 1}. {reg_c} = {reg_a} + {reg_b}  ({instruction}), {c} in {reg_c}, {a} in {reg_a}, {b} in {reg_b}")

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
    
    allocator = RegisterAllocator(total_registers)
    allocator.build_interference_graph(variables, live_ranges)
    allocator.simplify()
    allocator.spill()
    allocator.select()
    allocator.output(instructions)
