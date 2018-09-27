defmodule SFML.Graphics.Rect do
  @moduledoc """
  SFML::Graphics::Rectの機能の焼き直し

  Rectデータは、矩形領域の左上の基準座標と幅(右向き)・高さ(下向き)のリストで表現する
    r = [基準x座標, 基準y座標, 幅, 高さ]
  """
  
  defguardp all4_numbers?(a, b, c, d) when
    is_number(a) and
    is_number(b) and
    is_number(c) and
    is_number(d)

  @doc """
  矩形データの生成、基準点ペアと幅・高さペアを入力として与える
  """
  def rect([left, top], [width, height])
  when all4_numbers?(left, top, width, height) do
    [left, top, width, height]
  end
  
  @doc """
  矩形データの境界を求める
  """
  def boundary(r) do
    [left, top, width, height] = r
    [left, top, left+width, top+height]
  end
  
  @doc """
  矩形データの領域内に与えられた点[x,y]が含まれるかどうかを判定する
  """
  def contains?(r, [x, y]) do
    [left, top, right, bottom] = boundary(r)
    (left <= x && x <= right) && (top <= y && y <= bottom)
  end
  
  @doc """
  ２つの矩形データの境界から重なり部分を求める。重なりがない場合はnilが返る
  """
  def intersect([l1, t1, r1, b1], [l2, t2, r2, b2]) do
    is_rect?([max(l1, l2), max(t1, t2), min(r1, r2), min(b1,b2)])
  end
  
  @doc """
  ２つの矩形データから重なり部分を求める。重なりがない場合はnilが返る
  """
  def intersect(r1, r2) do
    intersect(boundary(r1), boundary(r2))
  end
  
  @doc """
  与えられた境界が正しい矩形領域を表すかどうかをチェックする。矩形領域を表す場合は、
  矩形データに変換して返す。そうでない場合はnilを返す
  """
  def is_rect?([left, top, right, bottom]) when (left < right) and (top < bottom) do
    [left, top, right-left, bottom-top]
  end

  def is_rect?(_) do
    nil
  end
end
