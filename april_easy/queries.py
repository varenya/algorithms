string = raw_input()
Q = int(raw_input())
for i in xrange(Q):
	sub = raw_input()
	if sub in string:
		print "Yes"
	else:
		print "No"
