defmodule SFML.System.Clock do
#  @on_load :start_gclock
  alias SFML.System.NIF

  defdelegate create(),            to: NIF, as: :clock_create
  defdelegate release(c),          to: NIF, as: :clock_release
  defdelegate get_elapsed_time(c), to: NIF, as: :clock_get_elapsed_time
  defdelegate restart(c),          to: NIF, as: :clock_restart
  defdelegate get_elapsed_time(),  to: NIF, as: :gclock_get_elapsed_time
  defdelegate restart(),           to: NIF, as: :gclock_restart


if !Module.defines?(__MODULE__, {:get_elapsed_time, 0})
&& !Module.defines?(__MODULE__, {:restart, 0}) do
  @gclock :global_clock

  def start_gclock() do
    clk = SFML.System.NIF.clock_create()
    pid = spawn(SFML.System.Clock, :clk_loop, [clk])
    Process.register(pid, @gclock)
    :ok
  end

  def get_elapsed_time() do
    send @gclock, {:get_elapsed_time, self()}
    receive do
      {:ok, val} -> val
    end
  end

  def restart() do
    send @gclock, {:restart, self()}
    receive do
      {:ok, val} -> val
    end
  end

  def clk_loop(clk) do
    receive do
      {:get_elapsed_time, caller} ->
        send caller, {:ok, get_elapsed_time(clk)}
        clk_loop(clk)
      {:restart, caller} ->
        send caller, {:ok, restart(clk)}
        clk_loop(clk)
    end
  end
end
end
