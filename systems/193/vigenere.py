def repeat_to_length(string_to_expand, length):
    return (string_to_expand * (int(length/len(string_to_expand))+1))[:length]

def main(choice):
	if choice == 1:
		plaintext = input("Enter plaintext: ")
		key = input("Enter key: ")
		print(encrypt(plaintext, key))
	else:
		ciphertext = input("Enter ciphertext: ")
		key = input("Enter key: ")
		print(decrypt(ciphertext, key))

def encrypt(plaintext, key):
	keyword = repeat_to_length(key, len(plaintext))
	ciphertext = []
	for i in range(len(plaintext)):
		if 97<=ord(plaintext[i])<=122:
			x = ((ord(plaintext[i])-97 + ord(keyword[i])-97) % 26 + 97)
		else:
			x = ((ord(plaintext[i])-65 + ord(keyword[i])-65) % 26 + 65)			
		ciphertext.append(chr(x))
	return "".join(ciphertext)

def decrypt(ciphertext, key):
	keyword = repeat_to_length(key, len(ciphertext))
	plaintext = []
	for i in range(len(ciphertext)):
		if 97<=ord(ciphertext[i])<=122:
			x = ((ord(ciphertext[i])-97 - ord(keyword[i])-97 + 26) % 26 + 97 - 14)
		else:
			x = ((ord(ciphertext[i])-65 - ord(keyword[i])-65 + 26) % 26 + 65)
		plaintext.append(chr(x))
	return "".join(plaintext)

if __name__ == '__main__':
	print("Operation- 1. Encrypt  2. Decrypt")
	choice = int(input("Your choice: "))
	main(choice)