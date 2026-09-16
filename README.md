# Caesar Cipher Tool (Encrypt / Decrypt / Brute Force)
This is a simple C++ project I built while learning the basics of cryptography as part of my journey into cybersecurity (VAPT/pentesting). It's a command-line tool that can encrypt or decrypt text using a Caesar cipher, and also has a brute-force mode that tries to crack the message even if you don't know the key.
Nothing fancy here — just plain C++ standard library (`iostream`, `string`), no external stuff. Wanted to actually understand every line instead of copy-pasting a library that does it for me.

## What's a Caesar Cipher?
It's one of the oldest and simplest encryption methods — you just shift every letter in the text by a fixed number of positions in the alphabet. So if the key is 3, A becomes D, B becomes E, and so on. Decryption is just shifting back the other way.
It's obviously not secure at all (there are only 26 possible keys, so anyone can crack it in seconds), but it's a good starting point for understanding how ciphers work before moving to actual cryptography.

## Features
- Encrypt text with a key you choose (0-25)
- Decrypt text if you already know the key
- Brute force mode — tries all 26 keys and prints every result so you can eyeball which one is actual readable text
- Works with both uppercase and lowercase, ignores spaces/numbers/symbols

## How to run it
```bash
g++ caesar_cipher.cpp -o caesar
./caesar
```
Then just follow the menu prompts.

## Example

Encrypting "Attack at dawn" with key 3:
```
Attack at dawn  ->  Dwwdfn dw gdzq
```
Brute forcing it back (without knowing the key):
```
Key 0: Dwwdfn dw gdzq
Key 1: Cvvcem cv fcyp
Key 2: Buubdl bu ebxo
Key 3: Attack at dawn      <- this one's clearly English, so key = 3
Key 4: Zsszbj zs bzvl
...
```

## Why I built this
I'm learning penetration testing and wanted to start with something basic before jumping into actual tools. This project helped me understand modular arithmetic (wrapping letters around the alphabet with `% 26`) and how weak classical ciphers really are — which is honestly part of why modern encryption needs to be so much more complex.

## Note

Made for learning purposes only, not meant to be actual secure encryption (it's really not, 26 keys is nothing to a computer).
