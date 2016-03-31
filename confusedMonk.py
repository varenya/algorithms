N = int(raw_input())
arr = map(int,raw_input().strip().split())
def GCD(a,b):
	if b == 0:
		return a
	else:
		return GCD(b,a%b)
def multiply(a,b):
	return a * b

gcd = reduce(GCD,arr)
prod = reduce(multiply,arr)
mod = 10 ** 9 + 7

def modPower(a,b,c):
	ans = 1
	while(b!=0):
		if b%2 == 1:
			ans = (ans*a)%c
		a = (a*a) % c
		b /= 2
	return ans
print modPower(prod,gcd,mod)

