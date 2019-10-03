function getPrimes(min, max) {
  const primes = [];
  if (min <= 1) min = 2;
  for (let i = min; i <= max; i++) {
    let primeb = true;
    for (let prime of primes) {
      if (i % prime == 0) {
        primeb = false;
        break;
      }
    }
    if (primeb) {
      primes.push(i);
    }
  }
  return primes;
}
