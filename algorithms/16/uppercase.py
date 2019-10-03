#i'm sorry idk cpp
inpt=input()
out=''
for i in inpt:
	if(i.isalpha()):
		out+=i.upper()
	else:
		out+=i
print(out)
