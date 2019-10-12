This simple HTML site shows the use of OAuth2 in your web application.

This is built using [gapi](https://github.com/google/google-api-javascript-client) but the 
concepts related to oauth are the same.

OAuth is an open standard for access delegation, commonly used as a way for Internet users to grant websites or applications access to their information on other websites but without giving them the passwords.

OAuth does this by sharing a token to 3rd party application after authorization. This token can be used to access user's information according to the (scopes)[https://oauth.net/2/scope/] granted by 
user.

### oauth clients require following info

* **clientId** The client id string assigned to you by the provider
* **clientSecret** The client secret string assigned to you by the provider (not required for `token`)
* **accessTokenUri** The url to request the access token (not required for `token`)
* **authorizationUri** The url to redirect users to authenticate with the provider (only required for `token` and `code`)
* **redirectUri** A custom url for the provider to redirect users back to your application (only required for `token` and `code`)
* **scopes** An array of scopes to authenticate against
* **state** Nonce sent back with the redirect when authorization is complete to verify authenticity (should be random for every request)


In our example the clientId is to be given in meta tag with name 'google-signin-client_id'

The authorizationUri is managed by gapi itself. 

After authorization or signIn the gapi store the cookies in local Storage of your application's local address. In my case 'http://localhost:3002'

To create webClient go to:
(https://console.developers.google.com)[https://console.developers.google.com]
create a new project
in it's credentials section create OAuth Client ID of type Web application
add authorized origin and redirect url according to your application
eg, for this demo
    origin: 	http://localhost:3002
    redirect:    http://localhost:3002/auth_callback   

To test this application serve the page on http://localhost:3002.
eg, run 
`$ npx serve -l 3002 ` in current directory   
after clicking google signin the gapi authenticates using OAuth2 and stores the cookie sent from server in localstorage. Note that even after reloading or re-opening in different tabs the session is maintained because of cookies. Logout clears these cookies.

