N,Q = map(int,raw_input().strip().split(' '))
names = {}
for i in xrange(N):
	names[raw_input().strip()] = 1

age = 0
for i in xrange(Q):
	temp = raw_input()
	if  temp.isdigit():
		if int(temp) <= 20:
			age += 1
	else:
		if !names.has_key(temp):
			age += 1

print age
