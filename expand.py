compressed = raw_input().strip()
import re
#uncompressed = ""

match = re.findall("([a-z])(\d+)",compressed)

freq_char = {}
for each_tuple in match:
	freq_char[each_tuple[0]] = 0

for each_tuple in match:
	freq_char[each_tuple[0]] += int(each_tuple[1])

chars = sorted(freq_char.keys())

#print chars
#print freq_char

prev = 0
for char in chars:
	freq_char[char] += prev
	prev = freq_char[char]

#print freq_char


def find_char(chars,freq_dict,index):

	prev = 0
	for char in chars:
		if index >= prev and index <= freq_dict[char] :
			return char
		prev = freq_char[char]
	return -1


Q = int(raw_input())
while Q!=0:
	index = int(raw_input().strip())
	print find_char(chars,freq_char,index)
	Q -= 1
