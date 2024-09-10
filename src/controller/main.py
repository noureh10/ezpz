import sys
import os
from command_dispatcher import *

flags_args = None
cmds_args = None
potential_path = None

general_help_path = "help_prompts/general_help.txt"

def flags_checker(flags):
	short_flags = [
		"v",
		"s"
	]
	long_flags = [
		"verbose",
		"silent"
	]
	for fl in flags:
		if fl.startswith("--"):
			flag_name = fl[2:]
		elif fl.startswith("-"):
			flag_name = fl[1:]
		else:
			return False
		if flag_name not in short_flags and flag_name not in long_flags:
			return False
	return True

def command_checker(command):
	commands_array = [
			"setconfig",
			"start",
			"interactive",
			"status",
			"modsize",
			"modlist",
			"version",
			"update",
			"help"
	]
	for cmd in commands_array:
		if cmd == command:
			return True
	return False

def path_checker(working_command, checked_command, path, extension):
	if (len(path)):
		real_path = path[0]
		if (working_command == checked_command and os.path.exists(real_path)):
			if real_path.endswith(extension):
				return True
	return False

def arguments_rule_check(flags, cmd, path):
	sc_command = "setconfig"
	extension = ".ini"
	if (not(command_checker(cmd) and flags_checker(flags)
		and (not path or path_checker(cmds_args, sc_command ,path, extension)))):
		return False
	elif (not (cmd == sc_command) and path):
		return False
	return True

def arguments_checker(arguments):
	global flags_args
	global cmds_args
	global potential_path
	
	mixed_args = False
	prefix_match = False
	i = 0
	j = 0
	if (len(arguments) > 1):
		arguments.pop(0)
	else:
		return False
	for argument in arguments:
		prefix_match = argument.startswith("-") or argument.startswith("--")
		if (prefix_match and mixed_args):
			return False
		elif (prefix_match and not mixed_args):
			i+=1
		else:
			mixed_args = True
		j+=1
	flags_args = arguments[0:i]
	if (len(arguments) == i):
		return False
	cmds_args = arguments[i]
	potential_path = arguments[i+1:j]
	return arguments_rule_check(flags_args, cmds_args, potential_path)

def controller():
	'''Function responsible for the control flow of the application'''
	if(arguments_checker(sys.argv)):
		command_dispatch(flags_args, cmds_args, potential_path)
	else:
		command_error(sys.argv)

if __name__ == "__main__":
	controller()