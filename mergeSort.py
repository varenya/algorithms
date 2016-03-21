import pdb
def mergeSort(arr,low,high):
	if low == high:
		return [arr[low]],0

	mid = (low+high)/2

	#pdb.set_trace()
	left,count_left = mergeSort(arr,low,mid)
	right,count_right = mergeSort(arr,mid+1,high)
	#print left,count_left
	#print right,count_right
	ans,count_merge = merge(left,right)
	return ans,count_merge+count_left+count_right


def merge(left,right):
	n1 = len(left)
	n2 = len(right)
	ans = [0]* (n1+n2)
	count = i = j = k = 0
	#pdb.set_trace()

	global freq
	while(i < n1 and j < n2):
		if left[i] <= right[j]:
			ans[k] = left[i]
			i +=1
		else:
			count += n1-i
			for t in xrange(i,n1):
				freq[left[t]-1] += 1
			ans[k] = right[j]
			j += 1
		k += 1
	if i!=n1:
		while(i < n1):
			ans[k] = left[i]
			k +=1
			i +=1
	if j!=n2:
		#pdb.set_trace()
		while(j < n2):
			#count += n2-i-1
			ans[k] = right[j]
			k +=1
			j +=1
	#print "count",count
	return ans,count


# print "before sorting",arr

T = int(raw_input())
while(T!=0):
	N = int(raw_input())
	arr = []
	freq =[0] * 10001
	for i in xrange(N):
		arr.append(int(raw_input().strip()))
	#print arr
	if N!=1:
		sort,inv = mergeSort(arr,0,len(arr)-1)
		for index in arr:
			print freq[index-1],
		print
	else:
		print 0

	T -= 1
#print freq
#print "after sorting",sort,inv
