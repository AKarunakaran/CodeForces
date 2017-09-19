s = raw_input()
sm = 0
rb = 0
for i in range(len(s)-1, -1, -1):
    if(s[i] == 'b'):
        rb += 1
    else:
        sm = sm+rb
        rb *= 2
print sm % 1000000007
