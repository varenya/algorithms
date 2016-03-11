T = int(raw_input())
#import pdb

while(T!=0):
	N,M = map(int,raw_input().strip().split())
	L,R,C,P,Q,S = map(int,raw_input().strip().split())
	listL = [0] * N
	listR = [0] * N
	listC = [0] * N
	listL[0] = L
	listR[0] = R
	listC[0] = C
	#print "L",listL
	#print "R",listR
	#print "C",listC
	for i in xrange(1,N):
		listL[i] = (listL[i-1] * P + listR[i-1]) % N + 1
		listR[i] = (listR[i-1] * Q + listL[i-1]) % N + 1
		if(listL[i] > listR[i]):
			temp = listR[i]
			listR[i] = listL[i]
			listL[i] = temp
		listC[i] = (listC[i-1] * S) % 1000000 + 1
	print "L",listL
	print "R",listR
	print "C",listC
	money = [0] * N
	k = 0
	while(M!=0):
		for i in xrange(N):
			if i >= listL[k]-1 and i <= listR[k]-1:
				money[i] += listC[k]
		k +=1
		M=M-1
	print money
	max_amt = max(money)
	print money.index(max_amt)+1,max_amt
	T=T-1
