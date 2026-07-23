from socket import *

serverName = 'add_another_system_IP_address'
serverPort = 12000

clientSocket = socket(AF_INET6, SOCK_STREAM)

clientSocket.connect((serverName, serverPort))

sentence = input("Input lowercase sentence: ")

clientSocket.send(sentence.encode())

modifiedSentence = clientSocket.recv(1024)

print("From Server:", modifiedSentence.decode())

clientSocket.close()