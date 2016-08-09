T = int(raw_input())

for t in xrange(T):

	L = int(raw_input())

	upper = map(int,raw_input().strip().split())
	lower = map(int,raw_input().strip().split())

	upper.append(0)
	lower.append(0)

	#print upper
	#print lower

	res = 0

	for i in xrange(1,L+1):
		res = max([ res , i+upper[i-1] , i+lower[i-1] ])
	print res

