defmodule Loop do
  @doc """
  generate uniq variable
  """
  def generate_var(context) do
    System.unique_integer([:positive])
    |> (&String.to_atom("gen#{&1}")).()
    |> Macro.var(context)
  end
  
  @doc """
  restricted WHILE loop construct
  """
  defmacro while(condition, clauses) do
    do_clause = Keyword.get(clauses, :do, nil)
    label     = generate_var(__MODULE__)
    quote do
      unquote(label) = fn
        (false, _)   -> :ok
        (true, next) ->
          unquote(do_clause)
          next.(unquote(condition), next)
      end
      unquote(label).(unquote(condition), unquote(label))
    end
  end
end

###

require Loop
Loop.while (IO.gets("% ") != "bye\n") do
  IO.puts("TRY AGAIN")
end

