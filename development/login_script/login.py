#This script basically sends a POST request to the Auth page which contains your username and password. 
#It basically fills in the data on behalf of you.
#Just replace the placeholders with your credentials and you are good to go


import requests 

def login():
            login_url = "https://nac.nitk.ac.in:8090/login.xml"	
            r = requests.post(login_url, data={'mode': 191, 'username': 'ReplaceThisWithYourUsername', 'password': 'ReplaceThisWithYourPassword'}) 

if __name__ == '__main__':
	login()

