import sys
if len(sys.argv)>1:
  f = open(sys.argv[1], 'r+')
else:
  f = sys.stdin
f.next()
gradesMap = {}
for line in f:
  grade = (line.split(','))[2]
  grade = float(grade.strip())
  personId = (line.split(','))[1]
  try:
    gradesMap[grade]+=","+ personId
  except KeyError:
    gradesMap[grade]=personId
  
mapIter = gradesMap.iteritems()
for grade,people in mapIter:
  print str(int(grade)) + ": (" + str(len(people.split(","))) + ")" + "\t " + people 