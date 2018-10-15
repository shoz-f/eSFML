defmodule SFML.System.NIF do
	@on_load :load_nifs
	def load_nifs do
	  :erlang.load_nif(__DIR__ <> "/SystemNIF", 0)
	end

	def clock_create(),              do: raise "NIF clock/0 not implemented"
	def clock_release(_a),           do: raise "NIF clock_release/1 not implemented"
	def clock_get_elapsed_time(_a),  do: raise "NIF clock_get_elapsed_time/1 not implemented"
	def clock_restart(_a),           do: raise "NIF clock_restart/1 not implemented"
#	def clock_interval(_a, _b),      do: raise "NIF clock_interval/2 not implemented"
	def gclock_get_elapsed_time(),   do: raise "NIF gclock_elapsed_time/0 not implemented"
	def gclock_restart(),            do: raise "NIF gclock_restart/0 not implemented"
end
