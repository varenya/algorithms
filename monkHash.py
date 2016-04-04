T = int(raw_input())

def insert_dict(insert,item):
	if insert.has_key(item):
		insert[item] += 1
	else:
		insert[item] = 1

while(T!=0):
	poke = {}
	N = int(raw_input())
	ans = 0
	for i in xrange(N):
		pond,pokemon = map(int,raw_input().strip().split())
		if pond != pokemon:
			insert_dict(poke,pond)
			if not poke.has_key(pokemon):
				ans += 1
			elif poke[pokemon] == 0:
				ans += 1
			else:
			       poke[pokemon] -= 1
	print ans
	T -= 1
