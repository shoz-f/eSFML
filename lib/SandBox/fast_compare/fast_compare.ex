# fast_compare.ex
 
defmodule SandBox.FastCompare do
  @on_load :load_nifs 
  def load_nifs do 
    :erlang.load_nif(__DIR__ <> "/fast_compare", 0)
  end 

  def fast_compare(_a, _b), do: "NIF fast_copare/2 not implemented"
  def kwlist(_a) do 
    raise "NIF fast_compare/2 not implemented" 
  end
end 
