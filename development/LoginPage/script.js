document.addEventListener('DOMContentLoaded', () => {

  if (!localStorage.getItem('count'))
                localStorage.setItem('count', 0);
  let count = localStorage.getItem('count');

  document.querySelector('#submit').onclick = () => {

    const username = document.querySelector('#username').value;
    const password = document.querySelector('#password').value;

    if ( username == "aditya" && password == "aditya1234") {
      localStorage.setItem('count', 0);
      alert(`Successfully validated ${username}`);
      window.location = "success.html";
    }
    else {
      count++;
      validate();
    }
    function validate() {
      localStorage.setItem('count', count);
      if( count == 5) {
        alert('You have only 5 more attempts remaining');
      }
      if ( count > 10) {
        alert('Sorry You took so many login attempts');
      }
    };
  };
});
