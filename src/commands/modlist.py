import commands.command as cmd
import sys
import requests

api_url = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"
configuration_file_missing = "The configuration file is missing, please consider refreshing"
invalid_modlist_path = "Modlist file path invalid, exiting"
invalid_config_file = "Invalid configuration file, exiting"

class Modlist(cmd.Command):
	modlist_dict = None
	modlist_add_queue = None
	
	def __init__(self, flags, command):
		super().__init__(flags, command)
	
	#Public methods
	def extract_data_from_modlist(self, modlist_file_path):
		if (self.check_if_file_exists(modlist_file_path)):
			pass
		else:
			self.error_and_exit(invalid_modlist_path)
	
	def append_data_to_server_file(self, config_file_path):
		config_file_buffer = None
		current_line = None
		if (self.check_if_file_exists(invalid_config_file)):
			file = open(config_file_path)
			while (current_line := file.readline()):
				config_file_buffer + current_line
				if (current_line):
					config_file_buffer + "\n"
			if not config_file_buffer:
				self.error_and_exit(invalid_config_file)
			else:
				
		else:
			self.error_and_exit(invalid_config_path)

	#Private methods
	def _get_mod_details(self, workshop_id):
		payload = {
			'itemcount': 1,
			'publishedfileids[0]': workshop_id
		}
		response = requests.post(api_url, data=payload)
		if response.status_code == 200:
			data = response.json()
			if 'response' in data and 'publishedfiledetails' in data['response']:
				mod_details = data['response']['publishedfiledetails'][0]
				title = mod_details.get('title', '')
				mod_id = mod_details.get('publishedfileid', '')
				description = mod_details.get('description', '')
				return title, mod_id, description
		return None, None, None

	def _get_mod_name(self, workshop_id):
		title, _, _ = _get_mod_details(workshop_id)
		return title
    
	def _get_mod_details(self, workshop_id):
		_, _, description = get_mod_details(workshop_id)
		return description
	
	def _extract_workshop_id(self, url):
		match = re.search(r'id=(\d+)', url)
		if match:
			return match.group(1)
		return None

	def _extract_mod_id(self, text):
		match = re.search(r'Mod ID:\s*([a-zA-Z0-9]+)', text)
		if match:
			return match.group(1)
		return None
	
	def _extract_map_id(self, text):
		match = re.search(r'')

	def _append_data_to_modlist_dictionary(self, key, value):
		self.modlist_dict[key] = value