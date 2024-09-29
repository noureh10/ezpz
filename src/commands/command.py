import sys
import os

# Errors
bad_path = "Wrong path, enter a valid path"
exit_failure = 1

class Command:
	cmd_argument = None
	flags_arguments = None
	verbose = False

	def __init__(self, flags ,command):
		self.__set_args(flags, command)
		self.verbose = self.is_verbose(flags)

	def error_and_exit(self, message):
		self.print_err(message)
		sys.exit(exit_failur)
	
	def print_err(self, message):
		print(message, file=sys.stderr)

	def command_help(self, path):
		if (os.path.exists(path)):
			with open(path, 'r') as file:
				help_text = file.read()
			print(help_text)
		else:
			self.print_err(bad_path)

	def __set_args(self, flags , command):
		self.set_flags_arguments(flags)
		self.set_cmd_arguments(command)

	def set_cmd_arguments(self, command):
		if (command):
			self.cmd_argument = command

	def set_flags_arguments(self, flags):
		if (flags):
			self.flags_arguments = flags

	def is_verbose(self, flags):
		if (not flags):
			return False
		elif (flags[0] == "-v" or flags[0] == "--verbose"):
			return True
		return False

	def check_if_file_exists(self, path):
		return os.path.exists(path)
