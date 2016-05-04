T = int(raw_input())
for t in xrange(T):
	N,M = map(int,raw_input().strip().split())
	G = []
	P = []
	for i in xrange(N):
		g,p= map(int,raw_input().strip().split())
		G.append(g)
		P.append(p)
	Pmin = min(P)
	if M > Pmin:
		print "YES"
	else:
		print "NO"
