defmodule SFML.System.Clock do
  alias SFML.System.NIF

  defdelegate create(),            to: NIF, as: :clock_create
  defdelegate release(c),          to: NIF, as: :clock_release
  defdelegate get_elapsed_time(c), to: NIF, as: :clock_get_elapsed_time
  defdelegate restart(c),          to: NIF, as: :clock_restart
  defdelegate interval(c, wait),   to: NIF, as: :clock_interval
end
