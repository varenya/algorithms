A,B = map(int,raw_input().strip().split())
can_buy = raw_input()
prev = A
ans = 0
#import pdb
#pdb.set_trace()
for i in xrange(len(can_buy)):
	temp = prev 
	square = temp * temp
	if can_buy[i] == "1":
		print i,square
		if i == 0:
			ans = (ans + temp)
		else:
			ans = (ans + square)
	if i == 0:
		prev = temp
	else:
		prev = square
print ans
print ans % B
