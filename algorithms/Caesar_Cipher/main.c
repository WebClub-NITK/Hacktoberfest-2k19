//A C++ program to illustrate Caesar Cipher Technique

#include <iostream>
using namespace std;


//This function receives text and shift and returns the encrypted text
string encrypt(string text,int s)
{
	string result="";
	//traverse text
	for(int i=0;i<text.length();i++)
	{
	 //apply transformation to each character
	 //Encrypt Uppercase letters

	if(isupper(text[i])) 
        //isupper function checks if character are 
        //upper case classified or not.
		result+=char(int(text[i]+s-65)%26 +65);
	//Encrypt Lowercase letters
	else
		result+=char(int(text[i]+s-97)%26 +97);
	}
	//Return the resulting string
	return result;
}

string decrypt(string cipher,int s)
{
     string reslt="";
     //traverse text
	for(int i=0;i<cipher.length();i++)
	{
	 //apply transformation to each character
	 //Decrpyt Uppercase letters

	if(isupper(cipher[i]))
        //isupper function checks if character are 
        //upper case classified or not.
		reslt+=char(int(cipher[i]-s-65)%26 +65);
	//Decrypt Lowercase letters
	else
		reslt+=char(int(cipher[i]-s-97)%26 +97);
	}
	//Return the resulting string
	return reslt;
}
//Driver program to test the above function
int main()
{
	string text;
	int s;

	
	cout<<"Please enter your text: \n";
        getline(cin,text);

        cout<<"Please enter an integer denoting the required shift: \n";
        cin >> s; 

	cout << "Text : " << text; 
        cout << "\nShift: " << s; 

	s = s%26; // ensuring that s lies between 0-25
	cout<<"\nEncypted Message:"<<encrypt(text, 26-s);
	string cipher = encrypt(text,26-s);
        cout<<"\nDecrypted Message:"<<decrypt(cipher,26-s);
	return 0;
}

