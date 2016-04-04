S = raw_input().strip()
Q = int(raw_input().strip())

for q in xrange(Q):
	l1,r1,l2,r2 = map(int,raw_input().strip().split())
	sub1 = S[l1-1:r1]
	sub2 = S[l2-1:r2]
	if sub1 == sub2:
		print "Yes"
	else:
		print "No"
