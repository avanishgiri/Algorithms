x = gets.to_i

sieve = []
primes = []

for i in 2..Math.sqrt(x).to_i
	if !sieve[i]
		((2*i)..x).step(i) { |j| sieve[j] = true }
	else
		sieve[i] = false
	end
end

p sieve
2.upto(x) { |i| puts i unless sieve[i] }
