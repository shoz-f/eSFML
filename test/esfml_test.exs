defmodule EsfmlTest do
  use ExUnit.Case
  doctest Esfml

  test "greets the world" do
    assert Esfml.hello() == :world
  end
end
