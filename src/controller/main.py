import commands.command as cmd
import sys
import os

flags_args = None
cmds_args = None
potential_path = None

def flags_checker(flags):
	'''Need to see how tuples work in python so its more readable'''
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
			"interactive",
			"setconfig",
			"status",
			"modsize",
			"modlist",
			"version",
			"update"
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

def arguments_checker(arguments):
	mixed_args = False
	prefix_match = False
	sc_command = "setconfig"
	extension = ".ini"
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
	cmds_args = arguments[i]
	potential_path = arguments[i+1:j]

	if (not(command_checker(cmds_args) and flags_checker(flags_args)
		and (not potential_path or path_checker(cmds_args, sc_command ,potential_path, extension)))):
		return False
	elif (not (cmds_args == sc_command) and potential_path):
		return False
	return True

def controller():
	'''Function responsible for the control flow of the CLI'''
	if (arguments_checker(sys.argv)):
		working_command = cmd.Command(cmds_args, flags_args, potential_path)
	else:
		sys.exit(1)

if __name__ == "__main__":
	controller()