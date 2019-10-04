print("Enter the text you want to encrypt:")
text=input()
assert(len(text) != 0)
print("Enter the key:")
key=input()
assert(key.isdigit())
key = int(key)
assert(key>0)
output=""
for c in text:
    if c.isalpha():
        ascii_value=ord(c)
        encrypted = ascii_value + key
        if c.isupper():
            if encrypted > ord('Z'):
                encrypted-=26
            elif encrypted < ord('A'):
                encrypted+=26
        else:
            if encrypted > ord('z'):
                encrypted-=26
            elif encrypted < ord('a'):
                encrypted+=26
        output+= chr(encrypted)
    else:
        output += c
print(f"The encrypted text is:\n{output}")
