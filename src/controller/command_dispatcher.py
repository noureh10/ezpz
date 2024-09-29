import sys
import commands.help as help
import commands.interactive as interactive
import commands.status as status
import commands.modlist as modlist
import commands.version as version
import commands.update as update
import commands.setconfig as setconfig

# Error paths
general_help_error = "help_prompts/general_help.txt"

def command_error(argument):
	print(f"Usage: ezpz [FLAGS] [COMMAND] [~PATH]")
	print(f"Type 'ezpz help' for more information on a specific command.")
	sys.exit(1)

def help_prompt(command):
	command = help.Help(command, None)
	command.command_help(general_help_error)
	del command

def command_dispatch(command, flags, potential_path):
	match command:
		case "interactive":
			print("interactive")
			#interactive.Interactive(flags)
		case "status":
			print("status")
			#status.Status(flags)
		case "modsize":
			print("modsize")
			#modsize.ModSize(flags)
		case "modlist":
			print("modlist")
			#modlist.ModList(flags)
		case "version":
			print("version")
			#version.Version(flags)
		case "update":
			print("update")
			#update.Update(flags)
		case "setconfig":
			print("setconfig")
			#setconfig.SetConfig(flags, potential_path)
		case "help":
			help_prompt(command)
		case _:
			command_error(command)
	