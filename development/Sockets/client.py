from socket import socket, AF_INET, SOCK_DGRAM
serverName = '127.0.0.1'
serverPort = 13337

clientSocket = socket(AF_INET, SOCK_DGRAM)

message_limit = 5

while message_limit > 0:
    message = input('Input lowercase sentence: ')

    clientSocket.sendto(message.encode(), (serverName, serverPort))

    modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
    
    message_limit -= 1

    print(f'incoming message: "{modifiedMessage.decode()}".  You can send {message_limit} more message(s)')


print('Chat session closed.  Restart client.')
clientSocket.close()