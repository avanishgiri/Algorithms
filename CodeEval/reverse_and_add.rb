num = gets
count = 0

while(num != num.reverse)
	count += 1
	num = num.to_i + num.reverse.to_i
	num = num.to_s
end

print count
puts " " + num
