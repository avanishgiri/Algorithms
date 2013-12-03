class Array
	def cross(a2)
		product(a2).map { |i| i.join }
	end
end

class Puzzle
	attr_accessor :neighbors, :units, :puzzle
	def makeBoard
		letters = "ABCDEFGHI".split(//)
		numbers = "123456789".split(//)
		squares = letters.cross(numbers)
		rows =	letters.map { |i| [i].cross(numbers) }
		columns = numbers.map { |i| [i].cross(letters).map { |j| j.reverse! }}
		boxes = []
		['ABC','DEF','GHI'].each do |i| 
			['123','456','789'].each do |j|
				boxes << i.split(//).cross(j.split(//))
			end
		end
		@units = rows + columns + boxes
		@neighbors = Hash.new([])
		squares.each do |sqr|
			@units.each do |unit|
				@neighbors[sqr] += unit if unit.include?(sqr)
			end
			@neighbors[sqr].uniq!.delete(sqr)
		end
		@puzzle = Hash[squares.map { |sqr| [sqr,numbers.join] } ]
	end

	def initialize(puzzle)
		makeBoard
		@puzzle.each_with_index do |(sqr,values),index|
			@puzzle[sqr] = puzzle[index] if puzzle[index] != '.'
		end
	end

	def propagate
		old = []
		@puzzle.values.each { |i| old << i.dup }
		@puzzle.each do |sqr, values|
			if values.length == 1
				@neighbors[sqr].each do |neighbor|
					@puzzle[neighbor].delete!(values) if @puzzle[neighbor].length > 1
				end
			end
		end
		old != @puzzle.values
	end

	def contradiction?
		array = []
		@units.each do |unit|
			for sqr in unit
				array << @puzzle[sqr] if @puzzle[sqr].length == 1
			end
			if array.uniq.length != array.length
				return true
			end
			array = []
		end
		return false
	end

	def guess(alternative)
		sqr = @puzzle.key(@puzzle.select {|k,v| v.length > 1}.values.min_by(&:length))
		return false if !sqr
		@puzzle[sqr] = @puzzle[sqr][0]
		alternative.puzzle[sqr] = alternative.puzzle[sqr][1..-1]
		return true
	end

	def solved?
		@puzzle.values.all? { |i| i.length == 1 }
	end

	def to_s
		@puzzle.values.join
	end

	def copy(puzz)
		array = []
		puzz.puzzle.values.each { |i| array << i.dup }
		@puzzle.values.each_with_index { |x,i| x = array[i] }
	end

end

puzzle = Puzzle.new(gets.chomp)

solutions, alternatives = [],[]

alternatives.push(puzzle)

while(!alternatives.empty?)
	puzzle = Marshal.load(Marshal.dump(alternatives.pop))
	
	simplification_found = true

	while(!puzzle.solved? and simplification_found)
		simplification_found = puzzle.propagate
		
		if(!simplification_found)
			alternative = Marshal.load(Marshal.dump(puzzle))
			simplification_found = puzzle.guess(alternative)

			alternatives.push(alternative) if simplification_found
		end
	end

	if(puzzle.solved? and !puzzle.contradiction?)
		solutions.push(Marshal.load(Marshal.dump(puzzle)))
	end
end

solutions.each { |i| print i ; puts}

