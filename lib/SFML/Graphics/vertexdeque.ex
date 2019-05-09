defmodule SFML.Graphics.VertexDeque do
  alias SFML.Graphics.NIF
  defstruct [:obj]

  @moduledoc """
  """
  defdelegate create(count),                to: NIF, as: :vertex_deque_create
  defdelegate get_count(vd),                to: NIF, as: :vertex_deque_get_count
  defdelegate get(vd, index),               to: NIF, as: :vertex_deque_get
  defdelegate clear(vd),                    to: NIF, as: :vertex_deque_clear
  defdelegate push(vd, position),           to: NIF, as: :vertex_deque_push
  defdelegate set_primitive_type(vd, type), to: NIF, as: :vertex_deque_set_primitive_type
  defdelegate get_primitive_type(vd),       to: NIF, as: :vertex_deque_get_primitive_type
end
