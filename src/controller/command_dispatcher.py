import utils.output as ut
import sys

def command_error(argument):
	print(argument)
	ut.output.print_err('wrong')
	sys.exit(0)


def command_dispatch(command, flags, potential_path):
	print(command)
	print(flags)
	print(potential_path)

	