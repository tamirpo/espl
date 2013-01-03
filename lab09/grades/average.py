import sys
sum=0
counter=0
if len(sys.argv)>1:
  f = open(sys.argv[1], 'r+')
else:
  f = sys.stdin
f.next()
for line in f:
  counter+=1
  grade = (line.split(','))[2]
  grade = float(grade.strip())
  sum+=grade
  
f.write("Average," + str(sum/counter))