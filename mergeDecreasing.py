T = int(raw_input())


def printArray(arr):
	for item in arr:
		print item,
	print 


def merge(arr1,arr2,N,M):
	i = j = k = 0
	merged = [0] * (N+M)
	while( i < N and j < M):
		if arr1[i] >= arr2[j]:
			merged[k] = arr1[i]
			i += 1
			k +=1
		else:
			merged[k] = arr2[j]
			j +=1
			k +=1
	if i!=N:
		while(i < N):
			merged[k] = arr1[i]
			k += 1
			i +=1
	if j!=M:
		while(j < M):
			merged[k] = arr2[j]
			k += 1
			j +=1
	return merged

for i in xrange(T):

	N,M = map(int,raw_input().strip().split())
	arr1 = map(int,raw_input().strip().split())
	arr2 = map(int,raw_input().strip().split())
	merged = merge(arr1,arr2,N,M)
	printArray(merged)

