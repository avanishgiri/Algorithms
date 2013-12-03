def choose(n, k)
	#number of combinations of n-1, k-1
	#plus number of combinations of n-1, k

	return n if k == 1
	return 1 if n == k

	return choose(n-1, k-1) + choose(n-1,k)
end

p choose(4,1);
p choose(9,2);
p choose(4,4);
p choose(4,3);