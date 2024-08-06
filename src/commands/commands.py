import sys

class Comand:
	arguments = None
	flags = None
	
	# need to work on the constructor of the command Class. Need to figure out how to check
	# the validity of the arguments.
	def __init__(self, line):
		line_len = len(line)
		if (line_len != 3):
			self.__print_err("Wrong number of arguments !\n")
			self.__command_help()
		else:
			if(len(line) == 3 and(not(self.__flags_checker(line[1]) or self.__commands_checker(line[1])))):
				self.__print_err("Not a valid command!\n")
				self.__command_help()
			else:
				self.__command_dispatcher(line)
	
	def __print_err(message):
		print(message, file=sys.stderr)

	def __command_help(self):
		with open('../help_prompts/help_text.txt', 'r') as file:
			help_text = file.read()
		print(help_text)
	
	def __flags_checker(self, flags):
		sflags_array = ["v","s","0"]
		if flags.startwith("-"):
			flags = flags[1:]
		else:
			return False
		if len(set(flags)) != len(flags):
			return False
		for flag in flags:
			if flag not in sflags_array:
				return False
		return True
	
	def __commands_checker(self, commands):
		commands_array = [
			"interactive",
			"status",
			"modsize",
			"modlist",
			"version",
			"update"
		]
		for command in commands:
			if command not in commands_array:
				return False
		return True
	
	def __command_dispatcher(self, line):
		print(line)

