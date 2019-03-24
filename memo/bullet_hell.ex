defmodule BulletHell do
  @moduledoc """
  Documentation for BulletHell.
  """
#  require BulletHell.GameState

  defstruct state: :opening,  # {:openinig, :play, :complete, :gameover}
              life: 5,          # life pint
              stage: 1,         # stage number
              score: 0,         # score point
              engine: nil       # game engine

  alias BulletHell, as: BH
              
  def run() do
  	setup()
  	|> opening
  	|> play
  	|> closing
  	|> teardown()
  end

  def setup() do
    IO.puts "Setup"
    %BH{ engine: :engine0 }
  end

  def opening(bh) do
    IO.puts "Opening"
    %BH{ bh | state: :play }
  end
  
  def play(bh = %BH{life: 0}) do
    IO.puts "Finish: life=#{bh.life} #{bh.stage}"
    %BH{ bh | stage: :complete }
  end
  
  def play(bh) do
    IO.puts "Stage=#{bh.stage}"
    play(%BH{ bh | life: (bh.life-1), stage: (bh.stage+1) })
  end
  
  def closing(bh = %BH{stage: :complete}) do
    IO.puts "Closing"
    bh.engine
  end
  
  def closing(bh) do
    IO.puts "Game Over"
    bh.engine
  end
  
  def teardown(engine) do
    IO.puts "Theardown:#{engine}"
  end
end
