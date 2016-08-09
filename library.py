T = int(raw_input())
import math
freq = {}

for t in xrange(T):
	string1 = raw_input().strip()
	freq[string1[0]] = freq.get(string1[0],0) + 1

result = 0

def custom_ceil(x):
	return math.ceil(x/10.0)

custom = map(custom_ceil,freq.values())

print int(sum(custom))

