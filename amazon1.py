from fractions import gcd
import pdb
#N = int(raw_input())
#A = map(int,raw_input().strip().split())

#print "array",A

Q = int(raw_input())
MOD = 10**9 + 7

def sum_gcd(num):
	ans = 0
	for i in xrange(1,num+1):
		print ans,
		ans += gcd(i,num)
	return ans

sum_gcd(8)
"""
for i in xrange(Q):
	input_string  = raw_input().strip().split()
#	print "input_string",input_string
	if input_string[0] == 'C':
		ans = 0
		for i in xrange(int(input_string[1])-1,int(input_string[2])):
			#print A[i],"sum",sum_gcd(A[i])
			ans =  (ans + sum_gcd(A[i])) % MOD
		print ans
	if input_string[0] == 'U':
		X = int(input_string[1])-1
		Y = int(input_string[2])
		A[X] = Y
		#print A
"""
