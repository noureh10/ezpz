import commands.command as cmd
import json
import os


class SetConfig(cmd.Command):
	def __init__(self, flags, command):
		super().__init__(flags, command)
		self.set_config(flags)

	def check_if_config_file(self, config_file):
		if (not os.path.exists(config_file)):
			self.print_err("Config file does not exist")
			return False
		else:
			return True
	
	