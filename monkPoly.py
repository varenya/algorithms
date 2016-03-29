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
		if evalFunc(mid) == 0:
			return mid
		elif evalFunc(mid) > 0:
			return findMin(low,mid-1)
		elif evalFunc(mid) < 0:
			return findMin(mid+1,high)
	else:
		return low

while( T!=0):
	A,B,C,K = map(int,raw_input().strip().split())
	low = 0
	high = K
	print findMin(low,high)
	T -= 1
