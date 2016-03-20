T = int(raw_input())

#import pdb


def minDamage(rows,columns,K):
	i = j = 0
	minSum = 0
	for k in xrange(K):


		if rows[0] <= columns[0]:
			minSum += rows[0]
			rows[0] += N
			columns = map( lambda x : x+1 , columns)
			i += 1
		else:
			minSum += columns[0]
			columns[0] += N
			rows = map( lambda x : x+1 , rows)
			j += 1
	return minSum



for i in xrange(T):

	N,K = map(int,raw_input().strip().split())
	matrix = []
	for i in xrange(N):
			 matrix.append( map( int,raw_input().strip().split() ))

	rows = []
	columns = []
	
	for i in xrange(N):
		row = 0
		column = 0
		for j in xrange(N):
			row += matrix[i][j]
			column += matrix[j][i]
		rows.append(row)
		columns.append(column)
	#print rows
	#print columns

	#rows.sort()
	#columns.sort()
	#pdb.set_trace()

	#print "ANS"

	print minDamage(rows,columns,K)

