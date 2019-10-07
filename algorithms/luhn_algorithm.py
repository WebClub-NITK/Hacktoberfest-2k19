num = input("Enter a number: ")

def validate_num(n):
    rest = [int(i) for i in list(n)][::-1]
    check = rest.pop(0)
    for i in range(len(rest)):
        if i %2 == 0:
                rest[i] *= 2
    for i in rest:
        if i > 9:
            rest[rest.index(i)] -= 9
    return ((sum(rest) + int(check))%10 == 0)

print(f"Is your credit card number valid? :{validate_num(num)}")
