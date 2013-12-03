NUMS = {1 => "ABC", 2 => "DEF", 3 => "GHI", 4 => "JKL", 5 => "MNO", 6 => "PQRS", 7 => "TUV", 8 => "WX", 9 => "YZ" }

def combs(soFar, remaining)
	if remaining.empty?
		puts soFar
	else
		c = remaining[0]
			NUMS[c.to_i].each_char do |l|
				current = soFar + l
				rem = remaining[1..-1]
				combs(current, rem)
			end
	end
end

def p_combs(num)
	combs("",num)
end
p_combs('12345678')
