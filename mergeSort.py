import pdb
def mergeSort(arr,low,high):

	
	if low == high:
		return [arr[low]]

	mid = (low+high)/2

	left = mergeSort(arr,low,mid)
	right = mergeSort(arr,mid+1,high)

	ans = merge(left,right)

	return ans

def merge(left,right):

	n1 = len(left)
	n2 = len(right)
	ans = [0]* (n1+n2)
	i = j = k = 0
	while(i < n1 and j < n2):
		if left[i] <= right[j]:
			ans[k] = left[i]
			i +=1
		else:
			ans[k] = right[j]
			j += 1
		k += 1
	if i!=n1:
		while(i < n1):
			ans[k] = left[i]
			k +=1
			i +=1
	if j!=n2:
		while(j < n1):
			ans[k] = right[j]
			k +=1
			j +=1
	return ans

arr = [9,8,7,6,5,4,1,1,0]
print "before sorting",arr
print "after sorting",mergeSort(arr,0,len(arr)-1)


