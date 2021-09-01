import re
import keyword

def isValidVariableName(name):
    match = bool(re.match("[a-zA-Z_][a-zA-Z0-9_]*", name))
    result = match and not keyword.iskeyword(name)
    return result