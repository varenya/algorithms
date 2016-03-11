T = int(raw_input())


def binarsearch(arr,item,low,high):
	if low > high:
		return -1
	mid = (low+high)/2
	if arr[mid] == item:
		return mid
	elif arr[mid] > item:
		return binarsearch(arr,item,low,mid-1)
	else:
		return binarsearch(arr,item,mid+1,high)

while(T!=0):
	N = int(raw_input())
	arr = []
	for i in xrange(N):
		arr.append(int(raw_input()))
		
	sort = sorted(arr)
	for item in arr:
		print binarsearch(sort,item,0,len(arr)-1),
	print
	for i in xrange(N):
		print arr[i],
	print
	for i in xrange(N):
		print i,
	T -= 1

