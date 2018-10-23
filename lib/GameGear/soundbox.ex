alias SFML.Audio.{SoundBuffer,Sound}

defmodule GameGear.SoundBox do
  use Agent

  def create(opt \\ [name: __MODULE__]) do
    Agent.start_link(fn -> MapSet.new end, opt)
  end

  def add_from_file({name, filename}, id \\ __MODULE__) do
    sb = SoundBuffer.load_from_file(filename)
    Agent.update(id, &Map.put(&1, name, sb))
  end

  def get(name, id \\ __MODULE__) do
    sb = Agent.get(id, &Map.get(&1, name))
    Sound.create()
    |> Sound.set_buffer(sb)
  end

  def play(name, id \\ __MODULE__) do
    get(name, id)
    |> Sound.play()
  end

  def pause(name, id \\ __MODULE__) do
    get(name, id)
    |> Sound.pause()
  end

  def stop(name, id \\ __MODULE__) do
    get(name, id)
    |> Sound.stop()
  end
end
