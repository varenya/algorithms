T = int(raw_input())
for i in xrange(T):
	N,P = map(int,raw_input().strip().split())
	sides  = 0
	while P:
		if N%2 == 0:
			N = N >> 1
			N += 1
		else:
			N = N >> 1
			N += 2
		#print "N",N
		P -= 1
	print N
