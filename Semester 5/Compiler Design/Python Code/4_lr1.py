from collections import defaultdict

def augment_grammar(grammar):
    augmented_grammar = grammar.copy()
    start_symbol = next(iter(grammar))
    augmented_grammar["S'"] = [(start_symbol,)]
    return augmented_grammar

def comp_first(grammar):
    first = defaultdict(set)
    def find_first(symbol):
        if symbol in first and first[symbol]:
            return first[symbol]
        if not symbol.isupper():
            return set(symbol)
        result = set()
        for production in grammar[symbol]:
            for char in production:
                char_first = find_first(char)
                result.update(char_first - {'ε'})
                if 'ε' not in char_first:
                    break
            else:
                result.add('ε')
        first[symbol] = result
        return result
    for variable in grammar:
        find_first(variable)
    return first

# Function to compute follow sets
def comp_follow(grammar, first):
    follow = defaultdict(set)
    start_symbol = next(iter(grammar))
    follow[start_symbol].add('$')
    while True:
        updated = False
        for lhs in grammar:
            for production in grammar[lhs]:
                trailer = follow[lhs].copy()
                for symbol in reversed(production):
                    if symbol.isupper():
                        if trailer - follow[symbol]:
                            follow[symbol].update(trailer)
                            updated = True
                        if 'ε' in first[symbol]:
                            trailer.update(first[symbol] - {'ε'})
                        else:
                            trailer = first[symbol]
                    else:
                        trailer = set(symbol)
        if not updated:
            break
    return follow

def closure(items, grammar, first):
    closure_set = set(items)
    added = True
    while added:
        added = False
        new_items = set()
        for item in closure_set:
            lhs, rhs, dot_pos, lookahead = item
            if dot_pos < len(rhs) and rhs[dot_pos].isupper():
                non_terminal = rhs[dot_pos]
                for prod in grammar[non_terminal]:
                    # Correctly concatenate tuples here
                    first_lookaheads = compute_first_of_string(rhs[dot_pos + 1:] + (lookahead,), first)
                    for la in first_lookaheads:
                        new_item = (non_terminal, prod, 0, la)
                        if new_item not in closure_set:
                            new_items.add(new_item)
                            added = True
        closure_set |= new_items
    return closure_set

# Compute the first of a string of symbols
def compute_first_of_string(symbols, first):
    result = set()
    for symbol in symbols:
        result |= first[symbol] - {'ε'}
        if 'ε' not in first[symbol]:
            break
    else:
        result.add('ε')
    return result

# Compute the goto function for a set of items and a symbol
def goto(items, symbol, grammar, first):
    goto_set = set()
    for item in items:
        lhs, rhs, dot_pos, lookahead = item
        if dot_pos < len(rhs) and rhs[dot_pos] == symbol:
            goto_set.add((lhs, rhs, dot_pos + 1, lookahead))
    return closure(goto_set, grammar, first)

# Construct the canonical collection of LR(1) items
def construct_lr1_items(grammar, first):
    start_item = ("S'", (grammar["S'"][0][0],), 0, "$")
    canonical_collection = [closure({start_item}, grammar, first)]
    added = True
    while added:
        added = False
        new_states = []
        for state in canonical_collection:
            for symbol in set(sym for _, rhs, dot_pos, _ in state for sym in rhs[dot_pos:dot_pos + 1]):
                goto_state = goto(state, symbol, grammar, first)
                if goto_state and goto_state not in canonical_collection and goto_state not in new_states:
                    new_states.append(goto_state)
                    added = True
        canonical_collection.extend(new_states)
    return canonical_collection

# Construct the LR(1) parsing table
def construct_parsing_table(states, grammar, first, follow):
    action = defaultdict(dict)
    goto_table = defaultdict(dict)

    for i, state in enumerate(states):
        print(f"State {i}: {state}")  # Debugging info to see each state
        for item in state:
            lhs, rhs, dot_pos, lookahead = item
            if dot_pos < len(rhs):
                next_symbol = rhs[dot_pos]
                if next_symbol.islower():  # Terminal
                    goto_state = goto(state, next_symbol, grammar, first)
                    action[i][next_symbol] = ("shift", states.index(goto_state))
                    print(f"action[{i}][{next_symbol}] = shift {states.index(goto_state)}")  # Debugging info
            else:  # Reduce or accept
                if lhs == "S'":
                    action[i]["$"] = ("accept",)
                    print(f"action[{i}][$] = accept")  # Debugging info
                else:
                    action[i][lookahead] = ("reduce", lhs, rhs)
                    print(f"action[{i}][{lookahead}] = reduce {lhs} -> {''.join(rhs)}")  # Debugging info

        for non_terminal in grammar:
            goto_state = goto(state, non_terminal, grammar, first)
            if goto_state in states:
                goto_table[i][non_terminal] = states.index(goto_state)
                print(f"goto[{i}][{non_terminal}] = {states.index(goto_state)}")  # Debugging info

    return action, goto_table

def parse(input_string, action_table, goto_table, grammar):
    stack = [0]  # Start with initial state 0
    i = 0  # Input pointer

    print("Action Table:", action_table)
    print("Goto Table:", goto_table)
    print(f"Input string: {input_string}")

    while True:
        state = stack[-1]  # Current state
        current_symbol = input_string[i]  # Current input symbol

        print(f"Current stack: {stack}, current symbol: {current_symbol}")  # Debugging info

        if current_symbol in action_table[state]:
            action = action_table[state][current_symbol]

            if action[0] == "shift":
                print(f"Shift to state {action[1]}")  # Debugging info
                stack.append(action[1])
                i += 1  # Move the input pointer to the next symbol

            elif action[0] == "reduce":
                lhs, rhs = action[1], action[2]
                print(f"Reduce: {lhs} -> {''.join(rhs)}")  # Debugging info
                stack = stack[:-len(rhs)]  # Pop the rhs length from the stack
                new_state = goto_table[stack[-1]][lhs]  # Goto new state for lhs
                stack.append(new_state)
                print(f"New state after reduce: {new_state}")  # Debugging info

            elif action[0] == "accept":
                print("Input is accepted!")
                break

        else:
            print(f"Error: No action found for state {state} and symbol {current_symbol}")
            raise Exception(f"Syntax error at symbol {current_symbol}")

# Example usage with debugging
grammar = {
    "S": [("C", "C")],
    "C": [("a", "C"), ("b",)]
}

# Augment the grammar and compute first and follow sets
augmented_grammar = augment_grammar(grammar)
first = comp_first(augmented_grammar)
follow = comp_follow(augmented_grammar, first)

# Construct the LR(1) items and the parsing table
states = construct_lr1_items(augmented_grammar, first)
action_table, goto_table = construct_parsing_table(states, augmented_grammar, first, follow)

# Parse an input string
input_string = "ab$"  # Example input string with $ as end marker
parse(input_string, action_table, goto_table, augmented_grammar)


