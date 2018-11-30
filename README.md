# SFML binding in Elixir (experimental)

## What is this?
This is Elixir binding of SFML - Simple and Fast Multimedia Library.
You can develop graphics or sound apps in Elixir with eSFML package under
multi-platform.

I am developing eSFML simple shooting game, but it fits for any multimedia
purpose.

eSFML is consist of shared libraries and Elixir modules. You can build
the shared libraries with CMake and C++ tool chain quite easily.

Let's enjoy!

## requirement for building eSFML
1. C++98 or later
2. CMake
3. Elixir 1.6 or later/ Erlang/OTP V9.2 or later
4. SFML V2.5.0

OS depend requirements:

A. Linux-Mint

B. Windows


```elixir
>iex -S mix
Interactive Elixir (1.6.1) - press Ctrl+C to exit (type h() ENTER for help)
iex(1)> Main.flying_elixir()

Close the window when you push ESC key.

iex(2)> Main.walking_penguin()
```
