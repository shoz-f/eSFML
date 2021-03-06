alias SFML.Audio.Music

defmodule GameGear.JukeBox do
  use Agent

  def create(opt \\ [name: __MODULE__]) do
    Agent.start_link(fn -> MapSet.new end, opt)
  end

  def add_from_file({name, filename}, id \\ __MODULE__) do
    music = Music.open_from_file(filename)
    Agent.update(id, &Map.put(&1, name, music))
  end

  def get(name, id \\ __MODULE__) do
    Agent.get(id, &Map.get(&1, name))
  end

  def play(name, id \\ __MODULE__) do
    get(name, id)
    |> Music.play()
  end

  def pause(name, id \\ __MODULE__) do
    get(name, id)
    |> Music.pause()
  end

  def stop(name, id \\ __MODULE__) do
    get(name, id)
    |> Music.stop()
  end
end
