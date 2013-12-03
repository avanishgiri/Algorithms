# Solution for Challenge: Review Others, Refactor Yours - Week 1 Review. Started 2013-04-08T19:47:40+00:00
class Sudoku


  def initialize(board_string)
    @board = board_string.split('') # ['1','2',....] 81 length
  end
 
  def solve!
    #while solved? == false
    return self if solved? # solved instance of Sudoku (obj id, @board)

    @board.each_with_index do |cell, index|
      if cell == "0"
        possibilities = possible_values(index)
        return nil if possibilities.empty?
        
        possibilities.each do |element|
          @board[index] = element
          solution = Sudoku.new(@board.join('')).solve! # self or nil makes it up the ladder.
          puts "Found an unsolvable cell" if solution == nil
          return solution if solution
        end
      end
    end
  end

  def board
    @board.each_slice(9).to_a.map {|inner_array| inner_array.join('  ')}.join("\n")
  end

  private
  def possible_values(index)
    row_elements = make_row(index)
    col_elements = make_column(index)
    box_elements = make_box(index)

    all_possibilities = ("1".."9").to_a          
    possibilities = all_possibilities - (row_elements + col_elements + box_elements)
  end

  def solved?
    @board.include?("0") ? false : true
  end

  def row_index(one_d_index)
    one_d_index/9
  end

  def col_index(one_d_index)
    one_d_index%9
  end

  def make_row(one_d_index)
    row = []
    @board.each_with_index do |cell, index|
      if row_index(one_d_index) == row_index(index)
        row << cell
      end
    end
    row
  end

  def make_column(one_d_index)
    column = []
    @board.each_with_index do |cell, index|
      if col_index(one_d_index) == col_index(index)
        column << cell
      end
    end 
    column
  end
 
  def make_box(one_d_index)
    box = []
    @board.each_with_index do |cell, index|
      if col_index(one_d_index)/3 == col_index(index)/3 && row_index(one_d_index)/3 == row_index(index)/3
        box << cell
      end
    end
    box
  end

  # Returns a string representing the current state of the board
  # Don't spend too much time on this method; flag someone from staff
  # if you are.
  
end
 
# The file has newlines at the end of each line, so we call
# String#chomp to remove them.
board_string = File.readlines(ARGV[0]).first.chomp
 
game = Sudoku.new(p board_string)
 
# Remember: this will just fill out what it can and not "guess"
solved = game.solve!
puts solved.object_id
puts solved.board
puts "-----"
puts game.object_id
puts game.board

 
#puts game.board
