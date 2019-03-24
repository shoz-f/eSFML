alias SFML.Graphics.RenderWindow

alias GameGear.Screen

defmodule GameGear.Screen do
    @moduledoc """
    描画オブジェクトを描画するステージ
    """
    defstruct win: nil, bg: :Black

    @doc """
    ステージを作成
    """
    def create([_width, _height] = size, title, color) do
      %Screen{
        win: RenderWindow.create(size, title)
             |> RenderWindow.set_framerate_limit(120),
        bg:  color
      }
    end
  
    @doc """
    ステージを破棄
    """
    def discard(%{win: w}) do
      RenderWindow.destroy(w)
      :ok
    end
  
    @doc """
    """
    def keypressed?(%{win: w}, val) do
      RenderWindow.poll_event(w) == {:keypressed, val}
    end
  
    @doc """
    """
    def poll_event(%{win: w}) do
      RenderWindow.poll_event(w)
    end
  
    @doc """
    ステージを更新する
    """
    def update(%{win: w, bg: color}, e_list) do
      RenderWindow.clear(w, color)
      Enum.each(e_list, &RenderWindow.draw(w, &1.body))
      RenderWindow.display(w)
    end
end
  