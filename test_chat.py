# Python program to implement server side of chat room. 
import socket 
import select 
import sys 
from _thread import *
import datetime

"""The first argument AF_INET is the address domain of the 
socket. This is used when we have an Internet Domain with 
any two hosts The second argument is the type of socket. 
SOCK_STREAM means that data or characters are read in 
a continuous flow.""" 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
print(sys.argv)
sys.argv.append("127.0.0.1")
sys.argv.append(25565)
print(sys.argv)
# checks whether sufficient arguments have been provided 
if len(sys.argv) != 3: 
	print ("Correct usage: script, IP address, port number")
	exit() 

# takes the first argument from command prompt as IP address 
IP_address = str(sys.argv[1]) 

# takes second argument from command prompt as port number 
Port = int(sys.argv[2]) 

""" 
binds the server to an entered IP address and at the 
specified port number. 
The client must be aware of these parameters 
"""
server.bind((IP_address, Port)) 

""" 
listens for 100 active connections. This number can be 
increased as per convenience. 
"""
server.listen(100) 

list_of_clients = [] 

def clientthread(conn, addr): 
	#print("1")
	# sends a message to the client whose user object is conn

	#conn.send(" Welcome to this chatroom!".encode())
	#print("1")
	while True: 
			try: 
				#conn.send(" ".encode())
				message = conn.recv(2048) #problem line
				message = message.decode("utf-8")
				#print(message)
				#print("line 54")
				#print(addr[0])
				if message:
					tmp = "<" + str(addr[0]) + "> " +message
					print(tmp)
					message_to_send = ("<" + addr[0] + "> " + message )
					broadcast(message_to_send.encode(), conn) 

				else: 
					line(addr[0]+"disconect")
					"""message may have no content if the connection 
					is broken, in this case we remove the connection"""
					remove(conn) 

			except:
				continue

"""Using the below function, we broadcast the message to all 
clients who's object is not the same as the one sending 
the message """
def broadcast(message, connection):
	for clients in list_of_clients: 
		if clients==connection: #LOOK HERE !!!!!!!!!!!!!!!!!!!!!!
			try: 
				clients.send('\0'.encode()) 
			except: 
				clients.close() 
				# if the link is broken, we remove the client 
				remove(clients)
		else:
			clients.send(message)


"""The following function simply removes the object 
from the list that was created at the beginning of 
the program"""
def remove(connection): 
	if connection in list_of_clients: 
		list_of_clients.remove(connection)
	print("left") 

while True: 

	"""Accepts a connection request and stores two parameters, 
	conn which is a socket object for that user, and addr 
	which contains the IP address of the client that just 
	connected"""
	conn, addr = server.accept() 

	"""Maintains a list of clients for ease of broadcasting 
	a message to all available people in the chatroom"""
	list_of_clients.append(conn) 

	# prints the address of the user that just connected 
	print (addr[0] + " connected")
	dt = datetime.datetime.now()
	time =int( dt.year+dt.month+dt.day+dt.hour+dt.minute+dt.second+dt.microsecond)
	conn.send(("time_seed: "+str(time)).encode())

	# creates and individual thread for every user 
	# that connects 
	start_new_thread(clientthread,(conn,addr))	 

conn.close() 
server.close() 

def encrypt():
	public_key = 12
	y = int(math.sin(public_key*public_key)*10000000)
	if(y<0):
		y = y*-1;
	print (y)
	#y = 1000
	message = list("hello")#input("enter text")
	message_nums =[]


	for j in range(len(message)):
		message_nums.append(ord(message[j]))
	print(message_nums)
	for i in range(y):
		for j in range(len(message)):
			if(j+1 <len(message)):
				message_nums[j] = message_nums[j]+message_nums[j+1];
			else:
				message_nums[j] = message_nums[j]+message_nums[0];
	for tmp in range(len(message)):
		message_nums[tmp] = message_nums[tmp]%55296
		message[tmp]= (message_nums[tmp])

	print(message,i)