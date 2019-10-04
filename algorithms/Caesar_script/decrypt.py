print("Enter the text you want to decrypt:")
text=input()
assert(len(text) != 0)
print("Enter the used key:")
key=input()
assert(key.isdigit())
key = int(key)
assert(key>0)
output=""
for c in text:
    if c.isalpha():
        ascii_value=ord(c)
        decrypted = ascii_value - key
        if c.isupper():
            if decrypted > ord('Z'):
                decrypted-=26
            elif decrypted < ord('A'):
                decrypted+=26
        else:
            if decrypted > ord('z'):
                decrypted-=26
            elif decrypted < ord('a'):
                decrypted+=26
        output+= chr(decrypted)
    else:
        output += c
print(f"The decrypted text is:\n{output}")
