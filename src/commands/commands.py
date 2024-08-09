import sys
import os

wrong_num_args = "Wrong number of arguments !\n"
line_not_valid = "Arguments are not valid !\n"

class Comand:
	arguments = None
	flags = None
	help_c = None
	verbose = False

	def __init__(self, line):
		splitted_line = line.split(' ')
		line_len = splitted_line.__len__()
		help_c = '../help_prompts/general_help.txt'
		if (line_len == 2 or line_len == 3):
			if (self.__is_line_valid(splitted_line, line_len)):
				print_err("success")
			else:
				self.print_err(wrong_num_args)
		else:
			self.print_err(wrong_num_args)
			self.command_help(help_c)
	
	def print_err(self, message):
		print(message, file=sys.stderr)

	def command_help(self, path):
		with open(path, 'r') as file:
			help_text = file.read()
		print(help_text)
	
	def __command_dispatcher(self, line):
		print(line)

	def __flags_checker(self, flags):
		sflags_array = ["v","0"]
		if flags.startswith("-") and len(flags) > 1:
			flags = flags[1:]
		else:
			return False
		if len(set(flags)) != len(flags):
			return False
		for flag in flags:
			if flag not in sflags_array:
				return False
		return True
	
	def __commands_checker(self, command):
		commands_array = [
			"interactive",
			"status",
			"modsize",
			"modlist",
			"version",
			"update"
		]

		for x in commands_array:
			if x == command:
				return True
		return False
	
	def __file_checker(self, file_path):
		return os.path.exists(file_path)
	
	def __is_line_valid(self, line, line_len):
		if (line_len == 2):
			if (not(self.__commands_checker(line[1]))):
				self.print_err(line_not_valid)
				return False
		elif (line_len == 3):
			if(not(self.__flags_checker(line[1]) or self.__commands_checker(line[2]))):
				self.print_err(line_not_valid)
				return False
		return True
