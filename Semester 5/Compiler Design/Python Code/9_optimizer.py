def eliminate_common_subexpressions(expressions):
    exprs = {}
    result = []
    
    for instr in expressions:
        lval, rval = instr.split('=')
        lval, rval = lval.strip(), rval.strip()
        
        var = exprs.get(rval)
        
        if var is None:
            for expr in exprs:
                if rval == expr:
                    rval = exprs[expr]
            exprs[rval] = lval
            result.append(f"{lval} = {rval}")
        else:
            result.append(f"{lval} = {var}")
    
    return result

expressions = [
    "t1=a+b",
    "t2=t1*c",
    "t3=a+b",
    "t4=t3*d",
    "t5=t2+t4"
]

output = eliminate_common_subexpressions(expressions)
for line in output:
    print(line)
