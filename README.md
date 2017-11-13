# enc
Encryption script.

The implementation of the script on PHP is newer.

Main idea: 
You submit a simple string (for example, a password) to the input and at the constant input values get the complicated string with same length.

Thus, for example, you can use one password for multiple systems. In one parameter you specify your password, in a different site name - and you have a complicated password on the output based on a simple,

At the core of the script is a block (letter) character substitution (counted adjacent to the encoded one). For the script, the reverse data conversion is realizable, that is, it is possible to use it as a method for data transmission.

Disadvantages:
- Dependence on implementation. Any change to encryption algorithm does not support all previous versions.
