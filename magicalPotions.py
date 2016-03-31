A,B = map(int,raw_input().strip().split())
can_buy = raw_input()
prev = A
ans = 0
#import pdb
#pdb.set_trace()
for i in xrange(0,len(can_buy)):
	if can_buy[i] == "1":
		ans = (ans + prev) % B
	prev = (prev * prev) % B
print ans 
