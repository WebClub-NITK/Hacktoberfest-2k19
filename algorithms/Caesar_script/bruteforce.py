print("Enter the text you want to decrypt:")
text=input()
assert(len(text) != 0)
maxkey=25
for key in range(1,maxkey):
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
    print(f"With key={key}, the decrypted text is:\n{output}")
