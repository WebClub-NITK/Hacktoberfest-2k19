def func(a, b, m):
    r = 1
    mask = 2 ** int(math.ceil(math.log(b, 2)))
    while mask > 0:
      r = r * r
      if mask & b:
          r = r * a
          b = b ^ mask
      mask = mask // 2
      r = r % m

    return r
    
print("enter values for evalute the expression (a^b)%m : \n")
a = int(input("Enter value of a "))
b = int(input("Enter value of b "))
m = int(input("Enter value of m "))
print("value is ", func(a, b, m))
