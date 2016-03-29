T = int(raw_input())

A = B = C = K = 0
#import pdb

def evalFunc(x):
	return  A * x * x + B * x + C - K

def findMin(low,high):
	if low <= high:
		mid = (low+high)/2
		#print low,mid,high
		#print evalFunc(mid)
		if K == C:
			return 0
		elif evalFunc(mid) == 0:
			return mid
		elif low == mid:
			mid_value = evalFunc(mid)
			high_value = evalFunc(high)
			if high_value > 0 and mid_value > 0 and high_value > mid_value:
				return mid
			elif high_value > 0 and mid_value > 0 and high_value <= mid_value:
				return high
			elif mid_value < 0:
				return high
		elif evalFunc(mid) > 0:
			return findMin(low,mid)
		elif evalFunc(mid) < 0:
			return findMin(mid+1,high)

while( T!=0):
	A,B,C,K = map(int,raw_input().strip().split())
	low = 0
	high = K
	print findMin(low,high)
	T -= 1
