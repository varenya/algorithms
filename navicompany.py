T = int(raw_input())
for i in xrange(T):
	dev = 0
	unassigned = 0
	N = int(raw_input())
	for j in xrange(N):
		str_input = raw_input()
		if str_input.isdigit():
			dev += int(str_input)
		else:
			if dev > 0:
				dev -= 1
			else:
				unassigned += 1
	print unassigned
	
