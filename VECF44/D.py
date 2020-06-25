n, h = map(int, raw_input().split())
lo = 1
hi = n
while lo < hi:
	m = int((lo+hi)/2)
	test = 0
	if(h >= m): test = (m*(m+1))/2
	else:
		test = ((h*(h+1))/2) + h*(m-h)
		if((m-h) % 2 == 0):
			k = ((m-h)/2)
			test += k*k
		else:
			k = (m-h-1)/2
			test += k*(k+1)
	if(test < n):
		lo = m+1
	else:
		hi = m
print(lo)