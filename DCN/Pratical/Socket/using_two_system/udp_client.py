from socket import *

serverName = 'add_another_system_IP_address'
serverPort = 12000

clientSocket = socket(AF_INET6, SOCK_DGRAM)

message = input('Input lowercase sentence: ')

clientSocket.sendto(message.encode(), (serverName, serverPort))

modifiedMessage, serverAddress = clientSocket.recvfrom(2048)

print(modifiedMessage.decode())

clientSocket.close()