defmodule SFML.System.Vector2 do
  import :math

  @moduledoc """
  2次元ベクトル演算
  """
  
  @doc """
  原点ベクトルの生成
  """
  @spec zero() :: [number]
  def zero() do
    [0.0, 0.0]
  end

  @doc """
  ベクトル和
  """
  @spec add([number], [number]) :: [number]
  def add([ax, ay], [bx, by]) do
    [ax + bx, ay + by]
  end
  
  @doc """
  ベクトル差
  """
  @spec sub([number], [number]) :: [number]
  def sub([ax, ay], [bx, by]) do
    [ax - bx, ay - by]
  end
  
  @doc """
  位置ベクトルの拡大・縮小
  """
  @spec scale([number], number) :: [number]
  def scale([ax, ay], k) do
    [k*ax, k*ay]
  end
  
  @doc """
  2点間距離
  """
  @spec distance([number], [number]) :: number
  def distance([ax, ay], [bx, by]) do
    sqrt(pow(ax - bx, 2) + pow(ay - by, 2))
  end

  @doc """
  位置ベクトルの比較(等値)
  """
  @spec equal([number], [number]) :: boolean
  def equal([ax, ay], [bx, by]) do
    (ax == bx) && (ay == by)
  end
end
