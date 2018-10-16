alias SFML.Graphics.Texture

defmodule GameGear.TextureBox do
  use Agent

  def create(opt \\ [name: __MODULE__]) do
    Agent.start_link(fn -> MapSet.new end, opt)
  end

  def add_from_file({name, filename}, id \\ __MODULE__) do
    texture = Texture.load_from_file(filename)
    Agent.update(id, &Map.put(&1, name, texture))
  end

  def get(name, id \\ __MODULE__) do
    Agent.get(id, &Map.get(&1, name))
  end
end
