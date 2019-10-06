from socket import socket, AF_INET, SOCK_DGRAM
serverPort = 13337
serverSocket = socket(AF_INET, SOCK_DGRAM)

serverSocket.bind(('', serverPort))

print("The server is ready to receive ...")

number_messages = 0
while number_messages < 10:
    message, clientAddress = serverSocket.recvfrom(2048)
    message = message.decode()
    
    number_messages += 1
    print(f'incoming message. server responses left[{10 - number_messages}/10]\n\n"{message}"\n')

    message_to_send = input('reply to the above message: ')
    serverSocket.sendto(message_to_send.encode(), clientAddress)


print('Chat session closed.  Restart server.')