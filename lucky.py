T = int(raw_input())
#import pdb


def isLucky(string):
	N = len(string)
	i,j = 0,N-1
	mid = (i+j)/2
	if N%2 != 0:
		return False
	count_pre = 0
	count_post = 0
	while(i <= mid and j > mid):
		if string[i] == "R" and string[j] == "K":
			count_pre += 1
			count_post += 1
		i += 1
		j -= 1
	if count_pre == count_post and count_pre == N/2:
		return True
	else:
		return False

def maxLucky(string):
	i,j = 0,len(string)-1
	res = 0
	while i < j:
		while i < j and string[i] != 'R':
			i += 1
		while j > i and string[j] != 'K':
			j -= 1
		if i < j:
			res += 2
		i += 1
		j -= 1

	return res
		
	

for t in xrange(T):
	string = raw_input().strip()
	print maxLucky(string)
