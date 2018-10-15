alias SFML.Audio.Music

defmodule GameGear.JukeBox do
  use Agent

  def create(opt \\ []) do
    Agent.start_link(fn -> MapSet.new end, opt)
  end

  def add_from_file(box, name, filename) do
    music = Music.open_from_file(filename)
    Agent.update(box, &Map.put(&1, name, music))
  end

  def get(box, name) do
    Agent.get(box, &Map.get(&1, name))
  end

  def play(box, name) do
    Agent.get(box, &Map.get(&1, name)).play()
  end

  def pause(box, name) do
    Agent.get(box, &Map.get(&1, name)).pause()
  end

  def stop(box, name) do
    Agent.get(box, &Map.get(&1, name)).stop()
  end
end
