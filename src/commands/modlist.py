import command as cmd
import requests

class Modlist(cmd.Command):
	def __init__(self, flags, command):
		super().__init__(flags, command)
	
	def test(self):
		print(cmd.Command.cmd_argument)










def get_mod_details(workshop_id):
    url = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"
    payload = {
        'itemcount': 1,
        'publishedfileids[0]': workshop_id
    }
    response = requests.post(url, data=payload)
    if response.status_code == 200:
        data = response.json()
        if 'response' in data and 'publishedfiledetails' in data['response']:
            mod_details = data['response']['publishedfiledetails'][0]
            title = mod_details.get('title', '')
            mod_id = mod_details.get('publishedfileid', '')
            description = mod_details.get('description', '')
            return title, mod_id, description
    return None, None, None

def get_mod_name(workshop_id):
    title, _, _ = get_mod_details(workshop_id)
    return title

def get_mod_description(workshop_id):
    _, _, description = get_mod_details(workshop_id)
    return description

def add_mod_to_file(ini_file, workshop_id, mod_id):
	with open(ini_file, 'r') as file:
		lines = file.readline()
	workshop_line = next((line for line in lines if lines.startswith("WorkshopItems")), None)
	mod_line = next((line for line in lines if line.startswith("Mods")), None)
	if workshop_line and workshop_id not in workshop_line:
		workshop_line = workshop_line.strip() + f",{workshop_id}\n"
		lines = [line if not line.startswith("WorkshopItems") else workshop_line for line in lines]
	if mod_line and mod_id not in mod_line:
		mod_line = mod_line.strip() + f",{mod_id}\n"
		lines = [line if not line.startswith("Mods") else mod_line for line in lines]
	with open(ini_file, 'w') as file:
		file.writelines(lines)

def extract_workshop_id(url):
	match = re.search(r'id=(\d+)', url)
	if match:
		return match.group(1)
	return None

def extract_mod_id(text):
    match = re.search(r'Mod ID:\s*([a-zA-Z0-9]+)', text)
    if match:
        return match.group(1)
    return None

def extract_map_id(text):
	match = re.search(r'')

ini_file = "testfile.ini"

# while True:
# 	user_input = input("Enter the Steam URL for Workshop : \n")
# 	if user_input.lower == 'done':
# 		break
# 	workshop_id = extract_workshop_id(user_input)
# 	if workshop_id:
# 		w_id = extract_workshop_id(user_input)
# 		print(w_id)
# 		m_id = get_mod_description(workshop_id)
# 		m_id = extract_mod_id(m_id)
# 		print(m_id)
# 		if w_id and m_id:
# 			add_mod_to_file(ini_file, w_id, m_id)

test = Modlist("bonjour", "aurevoir")

test.test()
