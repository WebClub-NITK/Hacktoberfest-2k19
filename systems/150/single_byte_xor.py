# Python program implementing single-byte XOR cipher

# English frequency of letters
english_freq = [
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, # A-I
    0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095,  5.987, # J-R
    6.327, 9.056, 2.758, 0.978,  2.360, 0.150, 1.974, 0.074 # S-Z
]

def xor_encrypt(plaintext: str, key: int) -> str:
    """ Encrypt a plaintext into a hex-encoded ciphertext.

    Args:
        plaintext (str): The plaintext to encrypt
        key (int): The single-byte key

    Returns:
        str: The hex-encoded ciphertext
    """
    return bytes(ord(c) ^ key for c in plaintext).hex()

def xor_decrypt(ciphertext: str, key: int) -> str:
    """ Decrypt a hex-encoded ciphertext into plaintext.

    Args:
        ciphertext (str): The hex-encoded ciphertext
        key (int): The single-byte key

    Returns:
        str: The plaintext
    """
    return ''.join(chr(b ^ key) for b in bytes.fromhex(ciphertext))

def count_character_frequency(plaintext: str) -> list:
    """ Count character frequency in a plaintext.

    Args:
        plaintext (str): The plaintext

    Returns:
        list: The frequency of each character
    """
    occ = [0] * 26
    for c in plaintext.lower():
        if c >= 'a' and c <= 'z':
            occ[ord(c) - ord('a')] = occ[ord(c) - ord('a')] + 1
    return [o * 100 / len(plaintext) for o in occ]

def score_character_frequency(plaintext: str) -> float:
    """ Score a plaintext based on character frequency.

    Args:
        plaintext (str): The plaintext

    Returns:
        float: The score
    """
    plaintext_freq = count_character_frequency(plaintext)
    score = 0
    for observed, expected in zip(plaintext_freq, english_freq):
        score = score + (observed - expected) ** 2
    return score

def brute_force_xor_decrypt(ciphertext: str) -> tuple:
    """ Brute force the decryption of a hex-encoded ciphertext into plaintext.

    Args:
        ciphertext (str): The hex-encoded ciphertext

    Returns:
        tuple(int, str): The key and the plaintext
    """
    key, plaintext = None, None
    score = float('Inf')
    for k in range(256):
        t = xor_decrypt(ciphertext, k)
        s = score_character_frequency(t)
        if s < score:
            key, plaintext, score = k, t, s
    return (key, plaintext)

def main():
    """ Driver program """

    # Hex-encoded ciphertext
    ciphertext = "03246a2938333a3e252d382b3a2233666a3e222f6a25242f673e23272f6a3a2b2e6a62051e1a636a23396a2b246a2f242938333a3e2325246a3e2f292224233b3f2f6a3e222b3e6a292b2424253e6a282f6a29382b29212f2e666a283f3e6a382f3b3f23382f396a3e222f6a3f392f6a252c6a2b6a25242f673e23272f6a3a382f6739222b382f2e6a212f336a3e222f6a392b272f6a3923302f6a2b39666a25386a2625242d2f386a3e222b24666a3e222f6a272f39392b2d2f6a282f23242d6a392f243e646a03246a3e2223396a3e2f292224233b3f2f666a2b6a3a262b23243e2f323e6a23396a3a2b23382f2e6a3d233e226a2b6a382b242e25276a392f29382f3e6a212f336a622b2639256a382f2c2f38382f2e6a3e256a2b396a2b6a25242f673e23272f6a3a2b2e6364"

    # Brute force decryption
    key, plaintext = brute_force_xor_decrypt(ciphertext)

    print('Key: {}'.format(key))
    print('Plaintext:\n{}'.format(plaintext))

if __name__=='__main__':
    main()
