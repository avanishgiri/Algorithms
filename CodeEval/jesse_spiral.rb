def spiral(array) # not mine: https://gist.github.com/jfarmer/d0f37717f6e7f6cebf72
	  return [] if array.empty?
		 
		  first, *rest = *array
			 
			  return first + spiral(rest.transpose.reverse)
end
a =(1..1000000).each_slice(1000).to_a
p a
p spiral(a)
