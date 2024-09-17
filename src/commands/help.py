import commands.command as cmd

class Help(cmd.Command):
	def __init__(self, flags, command):
		super().__init__(None, command)