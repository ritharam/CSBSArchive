from collections import defaultdict

def comp_first(grammar):
    first = defaultdict(set)

    def find_first(symbol):
        if symbol in first and first[symbol]:
            return first[symbol]
        if not symbol.isupper() or not symbol.isalpha():
            return set(symbol)

        result = set()
        for production in grammar[symbol]:
            if production == "e":
                result.add("e")
            else :
                for char in production:
                    char_first = find_first(char)
                    result.update(char_first - {"e"})
                    if "e" not in char_first:
                        break
                    else :
                        result.add("e")
        first[symbol] = result         
        return result    

    for variable in grammar:
        find_first(variable)
    
    return dict(first)

def comp_follow(grammar,first):
    follow = defaultdict(set)
    start = next(iter(grammar))
    follow[start].add('$')
    while True :
        updated = False
        for lhs in grammar :
            for production in grammar[lhs]:
                trailer = follow[lhs].copy()
                for symbol in reversed(production):
                    if symbol.isupper() :
                        if trailer - follow[symbol]:
                            follow[symbol].update(trailer)
                            updated = True
                        if "e" in first[symbol]:
                            trailer.update(first[symbol] - {"e"})
                        else :
                           trailer = first[symbol]
                    else :
                        trailer = set(symbol)
        if not updated :
            break
    return dict(follow)

grammar = {
    "S": ["(L)", "a"],
    "L": ["SM"],
    "M": ["+SM", "e"]
}

first = comp_first(grammar)
follow = comp_follow(grammar,first)

print(first)
print(follow)

