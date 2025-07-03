from first_follow import comp_first, comp_follow

grammar = {
    "S": ["CC"],
    "C": ["aC", "b"]
}

first = comp_first(grammar)
follow = comp_follow(grammar, first)

def isterminal(symbol: str) -> bool:
    return symbol.islower() or not symbol.isalpha()

def get_first(production: str) -> set:
    fst = set()
    for prod in production:
        if isterminal(prod[0]):
            fst |= set(prod[0])
        else:
            fst |= first[prod[0]]
    return fst

M = {}
for production in grammar:
    alpha = grammar[production]
    for character in get_first(alpha):
        if isterminal(character) and character != "ε":
            M[production, character] = []
            for rhs in grammar[production]:
                if isterminal(rhs[0]) and rhs[0] == character:
                    M[production, character].append(rhs)
                elif rhs[0].isupper():
                    M[production, character].append(rhs)

        if character == "ε":
            for character_flw in follow[production]:
                if isterminal(character_flw):
                    M[production, character_flw] = []
                    for rhs in grammar[production]:
                        if isterminal(rhs[0]) and rhs[0] == character:
                            M[production, character_flw].append(rhs)
                        elif rhs[0].isupper():
                            M[production, character_flw].append(rhs)

                if character_flw == "$":
                    M[production, "$"] = grammar[production]

print("Parsing Table:")
for entry in M:
    print(f"{entry}: {M[entry]}")

stack = []
stack.append("$")
stack.append(tuple(grammar.keys())[0])
inp_string = input("Enter a string: ") + "$"
i = 0

try:
    while len(stack) > 1:
        X = stack[-1]
        cur_symbol = inp_string[i]
        
        print(f"Stack: {stack}")
        print(f"Input buffer: {inp_string[i:]}")
        action = ""

        if isterminal(X):
            if X == cur_symbol:
                action = f"Match {X}"
                stack.pop()
                i += 1
            else:
                raise Exception(f"Syntax error: expected '{X}', but got '{cur_symbol}' at position {i}.")
        else:
            try:
                production = M[X, cur_symbol][0]
                action = f"Apply production {X} -> {production}"
                stack.pop()

                if production != 'ε':
                    for alpha in production[::-1]:
                        stack.append(alpha)

            except KeyError:
                raise Exception(f"Syntax error: no rule to parse '{X}' with input symbol '{cur_symbol}' at position {i}.")

        print(f"Action: {action}")
        print("")

    if stack[-1] == inp_string[i] and inp_string[i] == "$":
        print("String accepted")
    else:
        raise Exception(f"Syntax error: parsing did not complete correctly. Stack top: '{stack[-1]}', Input symbol: '{inp_string[i]}'")
except Exception as e:
    print(e)
    print("String rejected.")
