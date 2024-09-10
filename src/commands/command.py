import sys
import os

# Errors
bad_path = "Wrong path, enter a valid path"

class Command:
	cmd_argument = None
	flags_arguments = None
	potential_path_argument = None

	def __init__(self, flags ,command, potential_path):
		self.set_args(flags, command, potential_path)

	def print_err(self, message):
		print(message, file=sys.stderr)

	def command_help(self, path):
		if (os.path.exists(path)):
			with open(path, 'r') as file:
				help_text = file.read()
			print(help_text)
		else:
			self.print_err(bad_path)

	def set_args(self, flags , command, path):
		self.set_flags_arguments(flags)
		self.set_cmd_arguments(command)
		self.set_path_arguments(path)

	def set_cmd_arguments(self, command):
		if (command):
			self.cmd_argument = command

	def set_flags_arguments(self, flags):
		if (flags):
			self.flags_arguments = flags

	def set_path_arguments(self, path):
		if (path):
			self.potential_path_argument = path

