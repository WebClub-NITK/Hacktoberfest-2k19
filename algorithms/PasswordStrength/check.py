from string import punctuation
score = 8
CONDITIONS = {
    "length" :(2,"The password lenght should be between 7 and 32."),
    "special" :(1,"The password should have at least an special character."),
    "digit" :(1,"The password should contain at least a digit."),
    "lowercase" :(1,"The password should contain at least a lower case letter."),
    "uppercase" :(1,"The password should contain at least an upper case letter."),
}
str = "abc"
print(ord(str[0]))
print(ord(str[0 + 1 % len(str)]) - 1)
print(ord(str[0 + 2 % len(str)]) - 2)
print('Enter the password:')
pwd = input()
if len(pwd) in range(7,32):
    del CONDITIONS["length"]
        
for idx in range(len(pwd)):
    if pwd[idx] in punctuation:
        CONDITIONS.pop("special",None)
    elif pwd[idx].isdigit():
        CONDITIONS.pop("digit",None)
    elif pwd[idx].islower():
        CONDITIONS.pop("lowercase",None)
    elif pwd[idx].isupper():
        CONDITIONS.pop("uppercase",None)
    # Check the ASCII code of the current character and the three next ones to see if they are consecutive. If so, add the points and the message to the list.
    if ord(pwd[idx]) == ord(pwd[(idx + 1) % len(pwd)]) - 1 == ord(pwd[(idx + 2) % len(pwd)]) - 2: 
        CONDITIONS["consecutive"] = (2,"The password should not have more than 3 consecutive elements.")
        
for (i,j) in CONDITIONS.items():
    score = score - j[0]

print("The score of the password is {}".format(score))
for (i,j) in CONDITIONS.items():
    print(j[1])