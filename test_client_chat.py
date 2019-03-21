# Python program to implement client side of chat room. 
import socket 
import select 
import sys 
import math
import encrypt_header


key = 0;
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
"""tmp = input("enter IP address")
sys.append(tmp)
tmp = input("enter port number")
sys.append(tmp)"""
sys.argv.append("127.0.0.1")
sys.argv.append(25565)
if len(sys.argv) != 3: 
	print ("Correct usage: script, IP address, port number")
	exit() 
IP_address = str(sys.argv[1]) 
Port = int(sys.argv[2]) 
server.connect((IP_address, Port))
#handshake
message = server.recv(2048)
message = message.decode("utf-8")
if("time_seed:" == message[0:10]):
	x = [int(s) for s in message.split() if s.isdigit()]
	tmp_seed = x[0]
	key = encrypt_header.key_gen(tmp_seed)
	print("Welcome to this chatroom!") 
#end handshake

while True: 
	# maintains a list of possible input streams 
	sockets_list = [sys.stdin, server] 
	read_sockets = sockets_list
	for socks in read_sockets: 
		if socks == server:
			try:
				message = socks.recv(2048) #problem line
				message = message.decode("utf-8")
				if (message!='\0'):
					print(("<>")+message)
				else:
					2+2		
			except:
				print("IP") 
		else: 
			message = sys.stdin.readline() 
			server.send(str(encrypt_header.encrypt(message,key)).encode()) 
			print("<You>"+message)  

print("closing")
server.close() 



"""
Time log 
RHL - 3/14/19 5pm - 7:30pm (2hrs 30min)
RHL - 3/17/19 3:00- 3:47pm (47min)
RHL - 3/18/19 10am - 12:00am (1hr 42 min)
RHL - 3/18/19 12:37pm - 1:30pm (1hr)
RHL - 3/18/19 7-8pm (1hr)
RHL - 3/19/19 6-7:30pm (1hr 30 min)
RHL - 3/20/19 4-6:41pm ()
"""