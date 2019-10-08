## This is the code in Python
# Your task is to create the code for the same in C/C++

items = input("Input comma separated sequence of words")
words = [word for word in items.split(",")]
print(",".join(sorted(list(set(words)))))
