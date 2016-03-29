N,K = map(int,raw_input().strip().split())
monks = map(int,raw_input().strip().split())
#import pdb


def isPossible(mid,K):
	i,j = 0,0
	prev = monks[0] + mid
	K -= 1
	for i in xrange(1,len(monks)):
		if prev + mid >= monks[i]:
			continue
		if K == 0:
			return False
		prev = monks[i] + mid
		K -= 1
	return True

def lower_bound(left,right):

	ans = 0
	while(right>left):

		mid = left + (right-left)/2
		if isPossible(mid,K):
			ans = mid
			right = mid
		else:
			left = mid+1

	return ans
monks = sorted(monks)
print lower_bound(0,10000000)
	
