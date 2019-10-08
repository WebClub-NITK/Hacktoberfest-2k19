import requests

def login():
            login_url = "https://nac.nitk.ac.in:8090/login.xml"	
            r = requests.post(login_url, data={'mode': 191, 'username': 'username', 'password': 'password'})
            

if __name__ == '__main__':
	login()
