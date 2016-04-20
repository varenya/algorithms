N = int(raw_input())

def compare(s1,s2):
	temp = int(s1+s2) > int(s2+s1)
	print temp,s1,s2
	return temp
		

temp = raw_input().strip().split()
print sorted(temp,cmp = compare)
