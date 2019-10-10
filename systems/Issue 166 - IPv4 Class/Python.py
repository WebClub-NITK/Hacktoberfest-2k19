def main():
	ip=input("Enter the IPv4 address: ")
	a=""
	b=""
	f=0
	x=0
	zc=0
	for i in range(len(ip)):
		if(ip[i]=="."):
			if x==1 and zc>0:
				print()
				print("Invalid IPv4 Address")
				f=1
				break
			a=int(a)
			x=0
			zc=0
			if(a<0 or a>255):
				print()
				print("Invalid IPv4 Address")
				f=1
				break
			else:
				if i<=3:
					b=a
			a=""
		else:
			if int(ip[i])>0:
				x=1
			elif int(ip[i])==0 and x==0:
				zc+=1
			a+=ip[i]

	if a!="" and (int(a)<0 or int(a)>255) and f==0:
		print()
		print("Invalid IPv4 Address")
		f=1

	if f==0 and (len(ip)<7 or len(ip)>15):
		print()
		print("Invalid IPv4 Address")
		f=1

	if f==0:
		b=int(b)
		print()
		if b>=0 and b<=127:
			print("This is a class A IPv4 address.")
		elif b>=128 and b<=191:
			print("This is a class B IPv4 address.")
		elif b>=192 and b<=223:
			print("This is a class C IPv4 address.")
		elif b>=224 and b<=239:
			print("This is a class D IPv4 address.")
		elif b>=240 and b<=255:
			print("This is a class E IPv4 address.")

if __name__=='__main__':
	main()