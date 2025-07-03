from collections import defaultdict, deque

instructions = [
    "t1=a+b",
    "t2=t1*c",
    "t3=d+e",
    "t4=t3-f",
    "t5=t2+t4"
]

operations = []
var_to_op = {}
dependencies = defaultdict(set)
dependents = defaultdict(set)
scheduled = []
ready = deque()

for i, inst in enumerate(instructions):
    parts = inst.split("=")
    result = parts[0]
    expression = parts[1]
    operands = []
    
    for op in ['+', '-', '*', '/']:
        if op in expression:
            operands = expression.split(op)
            break
    
    operations.append((i + 1, result, operands))
    var_to_op[result] = i + 1

print(operations)
print(var_to_op)

for op_id, result, operands in operations:
    for operand in operands:
        if operand in var_to_op:
            producer_id = var_to_op[operand]
            dependencies[op_id].add(producer_id)
            dependents[producer_id].add(op_id)

print(producer_id)
print(dependencies)
print(dependents)

for op_id, _, _ in operations:
    if not dependencies[op_id]:
        ready.append(op_id)

while ready:
    current = ready.popleft()
    scheduled.append(current)
    
    for dependent in dependents[current]:
        dependencies[dependent].discard(current)
        if not dependencies[dependent]:
            ready.append(dependent)

result = [instructions[op_id - 1] for op_id in scheduled]

print("Original Instructions:")
for i, inst in enumerate(instructions, 1):
    print(f"{i}. {inst}")
    
print("\nScheduled Instructions:")
for i, inst in enumerate(result, 1):
    print(f"{i}. {inst}")
