## const X and X const mean the same thing. Which do you think is better and why?

Though const X and X const here mean the same thing, but X const is better because of 
- First Reason: the `Right left rule`. It provides easier answer to the question what is constant. Its always what is in front of the const qualifier.
`const int N = 100;` is equilavent to int `const N = 100;` Whereas `int* const apple;` Here the pointer cannot change but the value its is pointing to can change.
- Second Reason: Syntactical Substitution principle. 
Let us consider:
`typedef char* CHARS`
`typedef CHARS const CPTR` This is constant pointers to chars
 Similarly replacing CHARS with original definition
`typedef char* const CPTR`
This is also constant pointer to chars.
Whereas 
`typedef char* CHARS`
`typedef const CHARS CPTR`
This is constant pointer to chars

If I now replace the definition of CHARS then
`typedef const char* CHARS`
This is now pointer to constant chars which is totally different.

http://ultra.sdk.free.fr/docs/DxO/C%2B%2B%20Templates%20The%20Complete%20Guide.pdf

https://stackoverflow.com/questions/3984989/what-is-the-differnce-between-const-x-a-and-x-const-a-if-x-is-the-class