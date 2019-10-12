const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.question('Enter the IPv4 address:  ', (answer) => {
  // TODO: Log the answer in a database
    if(valid_ipv4_address(answer)==true){
  console.log(`This is a class ${ipv4_class(answer)} IPv4 address.`);
    }
    else{
        console.log('This is an invalid IPv4 address.')
    }
  rl.close();
});




function valid_ipv4_address (ip) {
  if (typeof ip !== 'string') {
    throw new TypeError('Expected a string');
  }

  var matcher = /^(?:(?:2[0-4]\d|25[0-5]|1\d{2}|[1-9]?\d)\.){3}(?:2[0-4]\d|25[0-5]|1\d{2}|[1-9]?\d)$/;

  return matcher.test(ip);
};


function ipv4_class(ip){
const firstOct = parseInt(ip.match(/\d{1,3}(?=\.)/)[0], 10);

	if (firstOct < 128) {
		return 'A';
	}
	if (firstOct > 127 && firstOct < 192) {
		return 'B';
	}
	if (firstOct > 191 && firstOct < 224) {
		return 'C';
	}
	if (firstOct > 223 && firstOct < 240) {
		return 'D';
	}
	if (firstOct > 239 && firstOct < 256) {
		return 'E';
	}

}


