from collections import Counter
import sys
import os

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
			self.__is_line_valid(line, line_len)
		else:
			self.print_err("Wrong number of arguments !\n")
			self.command_help(help_c)
	
	def print_err(self, message):
		print(message, file=sys.stderr)

	def command_help(self, path):
		with open(path, 'r') as file:
			help_text = file.read()
		print(help_text)
	
	def __flags_checker(self, flags):
		sflags_array = ["v","0"]
		if flags.startwith("-") and len(flags) > 1:
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
	
	def __file_checker(self, file_path):
		return os.path.exists(file_path)
	
	def command_dispatcher(self, line):
		print(line)
	
	def __is_line_valid(self, line, line_len):
		if (line_len == 2):
			if (not(self.__commands_checker(line[1]))):
				return False
		elif (line_len == 3):
			if(not(self.__flags_checker(line[1]) or self.__commands_checker(line[2]))):
				return False
		return True