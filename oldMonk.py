T = int(raw_input())

#import pdb
def firstOccurence(arr,left,right,item):
	while(right-left > 1):
		mid = left + (right-left)/2
		if arr[mid] <= item:
			right = mid
		else:
			left = mid
	return right

for i in xrange(T):
	N = int(raw_input())
	A = map(int,raw_input().strip().split())
	B = map(int,raw_input().strip().split())
	i=0
	j=N-1
	maxValue = 0
	left = 0
	right = N-1
	mid = (i+j)/2
	#pdb.set_trace()
	while(j >= 0):
		#print B[j],A[i]
		i = firstOccurence(A,left,right,B[j])
		if j >= i:
			#print i,j
			diff = j-i
			maxValue = max(diff,maxValue)
		j -= 1
	print maxValue

