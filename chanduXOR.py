N,M = map(int,raw_input().strip().split())
arr = []
for i in xrange(N):
	arr.append(map(int,raw_input().strip().split()))

sumR = map(sum,arr)
sumC = []
for j in xrange(M):
	temp = 0
	for i in xrange(N):
		temp += arr[i][j]
	sumC.append(temp)
#print sumC
#print sumR
maxXOR = 0
for i in xrange(N):
	for j in xrange(M):
		maxXOR = max(maxXOR,sumR[i] ^ sumC[j])
print maxXOR
