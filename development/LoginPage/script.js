document.addEventListener('DOMContentLoaded', () => {

  let count = 0;

  document.querySelector('#submit').onclick = () => {

    const username = document.querySelector('#username').value;
    const password = document.querySelector('#password').value;

    if ( username == "aditya" && password == "aditya1234") {
      documen.querySelector('#error').innerHTML = "";
      alert(`Successfully validated ${username}`);
      window.location = "success.html";
    }
    else {
      document.querySelector('#error').innerHTML = "invalid credentials";
      count++;
      validate();
    }

    function validate() {
      if( count == 5) {
        alert('You have only 5 more attempts remaining');
      }
      if ( count > 10) {
        alert('Sorry You took so many login attempts');
      }
    };

  };
});
