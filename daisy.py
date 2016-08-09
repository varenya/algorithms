T = int(raw_input())
for t in xrange(T):
	S,P = raw_input().strip().split(" ")
	possible = False
	for i in xrange(1,len(S)+1):
		temp = S[:i] + S + S[i:]
		#print "temp",temp
		if temp == P:
			possible = True
			break
	if possible :
		print "Possible"
	else:
		print "Impossible"



