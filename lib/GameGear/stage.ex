alias SFML.Graphics.RenderWindow

alias GameGear.Stage

defmodule GameGear.Stage do
    @moduledoc """
    描画オブジェクトを描画するステージ
    """
    defstruct win: nil, bg: :Black

    @doc """
    ステージを作成
    """
    def create([_width, _height] = size, title, color) do
      %Stage{
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
    ステージの中と外の境界を返す: [left,top,right,bottom]
    """
    def border(%{win: w}) do
      [0.0, 0.0] ++ RenderWindow.get_size(w)
    end
    
    @doc """
    ステージを更新する
    """
    def update(%{win: w, bg: color}, e_list) do
      RenderWindow.clear(w, color)
      Enum.each(e_list, &RenderWindow.draw(w, &1.sprite))
      RenderWindow.display(w)
    end
end
  