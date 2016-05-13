T = int(raw_input())


def partition(N,K):
	print N,K
	if K > N:
		return 0
	elif K == N:
		return 1
	elif K == 0:
		return 0
	else:
		return partition(N-K,K)+partition(N-1,K-1)


for t in xrange(T):
	N = int(raw_input())
	print partition(N,4)
