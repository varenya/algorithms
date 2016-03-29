T = int(raw_input())

def adjacentZ(string):
	for i in xrange(1,len(string)):
		if string[i-1] == string[i] and string[i] == "1":
			return False
	return True
def toOz(char):
	if char == '0':
		return 'O'
	else:
		return 'Z'

for t in xrange(T):
	N,K = map(int,raw_input().strip().split())
	if K > N:
		print -1
	else:
		arr = []
		for i in xrange(N):
			arr.append(bin(i)[2:])
		print arr

		arr = filter(adjacentZ,arr)
		print arr
		ans = "0"*(N-K) + arr[K-1]
		print ans
		print map(toOz,ans)
		
	
	

