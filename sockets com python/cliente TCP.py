import socket
HOST = '127.0.0.1' # Endereco IP do Servidor
PORT = 5000 # Porta do Servidor
tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
dest = (HOST, PORT)
tcp.connect(dest)
print ('Para sair use CTRL+X\n')
msg = input()
while (msg != '\x18'):
    tcp.sendto(msg.encode(),dest)
    msg = input()
tcp.close() 
