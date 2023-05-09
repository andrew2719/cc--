# Define the context-free grammar for palindromes
cfg = {
    'S': ['aSa', 'bSb', 'a', 'b', '']
}

# Create a push-down automaton with a single stack symbol and a start state
pda = {
    'start': {
        '': [('S', '$')],
    },
    'accept': {
        ('', '$'): True,
    }
}

# Convert each production rule to a PDA transition
for symbol, productions in cfg.items():
    for production in productions:
        state = symbol + '->' + production
        if len(production) == 1:
            pda[state] = {
                (production, symbol): [('S',)],
                ('', '$'): [('S',)],
            }
        else:
            pda[state] = {
                (production[0], symbol): [(symbol + '1', '$')],
            }
            for i in range(1, len(production) - 1):
                pda[symbol + str(i)] = {
                    (production[i], symbol + str(i-1)): [(symbol + str(i+1),)],
                }
            pda[symbol + str(len(production) - 1)] = {
                (production[-1], symbol + str(len(production) - 2)): [('S',)],
                ('', '$'): [('S',)],
            }

# Define a function to simulate the PDA on an input string
def simulate_pda(pda, input_string):
    stack = ['$']
    state = 'start'
    for symbol in input_string:
        if (symbol, stack[-1]) in pda[state]:
            stack.pop()
            stack.extend(reversed(pda[state][(symbol, stack[-1])]))
            state = stack.pop()
        else:
            return False
    return ('', '$') in pda[state]

# Test the PDA on some input strings
input_strings = ['abba', 'aabbbaa', 'aaa', 'b', '']
for input_string in input_strings:
    print(input_string, simulate_pda(pda, input_string))
