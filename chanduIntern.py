N = int(raw_input())
def checkDivisors(num):
	i = 1
	count = 0
	isDrinkable = True
	while( i * i < num):
		if num % i == 0:
			if i * i == N:
				count += 1
			else:
				count += 2
		if count >= 4:
			isDrinkable = False
			break
		i += 1
	return isDrinkable

for i in xrange(N):
	X = int(raw_input())
	if checkDivisors(X):
		print "NO"
	else:
		print "YES"
