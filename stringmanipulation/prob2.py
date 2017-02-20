line = raw_input()
while(line):
    splitLine = line.split('//')
    # print splitLine
    splitLine[0] = splitLine[0].replace('->','.')
    print "".join(splitLine)
    line = raw_input()
