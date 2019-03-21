import math
def key_gen(tmp_seed2):
	#print("before")
	y = int(math.sin(tmp_seed2*tmp_seed2)*100000)
	#print("after")
	if(y<0):
		y = y*-1;
	return int(y)

def encrypt(message2,key):
	message = message2
	message_nums =[]
	for j in range(len(message)):
		message_nums.append(ord(message[j]))
	for i in range(key):
		for j in range(len(message)):
			if(j+1 <len(message)):
				message_nums[j] = message_nums[j]+message_nums[j+1];
			else:
				message_nums[j] = message_nums[j]+message_nums[0];
	for tmp in range(len(message)):
		message_nums[tmp] = message_nums[tmp]%55296
		#message[tmp]= (message_nums[tmp])

	return message_nums


def decrypt(message2,key):
	message = message2
	message_nums =[]
	for j in range(len(message)):
	message_nums.append(ord(message[j]))
tmp_length = len(message)
for i in range(key,0,-1):
	for j in range(tmp_length-1,-1,-1):
		if(j<tmp_length-1):
			message_nums[j] = message_nums[j]-message_nums[j+1];
		else:
			message_nums[j] = message_nums[j]-message_nums[0];
for tmp in range(tmp_length):
 	message_nums[tmp] = message_nums[tmp]%55296
	print(message_nums)

	return message_nums

