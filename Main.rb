require 'ncursesw'
module Ncurses
	@local_stack_x = [0]
	@local_stack_y = [0]
end

def Ncurses.movel(x,y)
	x_l = @local_stack_x.inject(0){|result, i| result + i }	
	y_l = @local_stack_y.inject(0){|result, i| result + i }	
	move(x+x_l,y+y_l)
end

def Ncurses.push_matrix
	@local_stack_x.push(0)
	@local_stack_y.push(0)
end

def Ncurses.pop_matrix
	@local_stack_x.pop
	@local_stack_y.pop
end

def Ncurses.translate(x,y)
	if @local_stack_x.size-1 >=0 then
		@local_stack_x[@local_stack_x.size-1] += x
		@local_stack_y[@local_stack_y.size-1] += y
	end
end

class BaseProcess
	def setup
	end
	def update
	end
	def draw
	end
end

class BaseScale < Struct.new(:keys)
end

class ScaleBook < Struct.new(:scales)

end

class Key < Struct.new(:color)
	def setup
	end
	
	def draw(is_enable = true)
		Ncurses.push_matrix
		str = ""
			if color == :black then
				Ncurses.translate(0,0)
				str = "▉▉"
			else
				Ncurses.translate(3,0)
				str = "░░"
			end
			if !is_enable then
				str = "::"
			end
			Ncurses.movel(0,0)
			Ncurses.addstr(str)
			Ncurses.movel(1,0)
			Ncurses.addstr(str)
			Ncurses.movel(2,0)
			Ncurses.addstr(str)
		Ncurses.pop_matrix
	end
end

class KeyBoard
	def initialize(oct = 0)
		@keys = []
		for num in 0..11  do
			color = :white
			if [1,3,6,8,10].include?(num) then
				color = :black
			end
			@keys[num] = Key.new(color)
		end
	end
	
	def set_range(oct)
	end
	
	def draw(scale,key)#(x,y,scale,key,chord,inversion)
		# 移調したscale
		tmpkeys = scale.map{|item| if item+key >11 then item+key-12 else item+key end}
		for num in 0..11 do
			Ncurses.push_matrix
			Ncurses.translate(0,num*2)
			@keys[num].draw(tmpkeys.include?(num))
			Ncurses.pop_matrix
		end
	end
end

class Setting < Struct.new(:scale,:key,:chord,:inversion)
end
# setting = Setting.new(1,2,3,4)
# setting.scale

class Libitum < BaseProcess
	def setup
		# 0:C
		@scale_book = {
			major: [0,2,4,5,7,9,11],
			blue_note: [0,2,3,4,5,6,7,9,10,11],
			# blue_note: [0,2,3,5,6,9,10],
			rock_chord: [0,3,5,7,10],
			natural_minor: [0,2,3,5,7,8,10],
			harmonic_minor: [0,2,3,5,7,8,11],
			melodic_minor: [0,2,3,5,7,9,11],
			# minor = BaseScale.new([])
		}
		@key = 1
		@chord_book = {}
		@inversion = 0
		
		@keyboard = KeyBoard.new()
	end
	
	def draw
		# @keyboard.draw(@scale_book[:major], @key)
		@keyboard.draw(@scale_book[:blue_note], 8)
	end
end

class ProcessManager
	def initialize(process)
		@process = process
		Ncurses.initscr(); 
		@is_run = true
		@fps_inv = 1.0/30.0
	end
	
	def set_fps(f=30.0)
		@fps_inv = 1.0/f.to_f
	end
	
	def setup
		@process.setup
	end
	
	def update
		@process.update
	end
	
	def draw
		Ncurses.erase
		@process.draw
		Ncurses.refresh
	end
	
	def loop
		while @is_run do
			start_time = Time.now
			update
			draw
			finish_time = Time.now
			diff_time = finish_time - start_time
			if diff_time.to_f < @fps_inv.to_f then
				sleep @fps_inv - diff_time.to_f
			end
		end
	end
	
	def exit
		Ncurses.endwin();
	end
end

process_manager = ProcessManager.new(Libitum.new)
process_manager.set_fps(30)
process_manager.setup
process_manager.loop
process_manager.exit

