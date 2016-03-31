T = int(raw_input())
#import pdb


def binarySearch(a,item,low,high):
	if low > high:
		return -1
	mid = (low+high)/2
	if a[mid] == item:
		return mid
	elif a[mid] > item:
		return binarySearch(a,item,low,mid-1)
	else:
		return binarySearch(a,item,mid+1,high)
for t in xrange(T):
	N,M = map(int,raw_input().strip().split())
	arr = map(int,raw_input().strip().split())
	#print arr
	firstN = arr[:N]
	#print firstN
	#print arr[N:]
	firstN.sort()
	for item in arr[N:]:
		index = binarySearch(firstN,item,0,len(firstN)-1)
		if index == -1:
			firstN.append(item)
			firstN.sort()
			print "NO"
		else:
			print "YES"
			#print index
			#del firstN[index]

