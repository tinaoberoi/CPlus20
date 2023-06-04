## In slide 30, we mentioned that overloads of operator+= can be either class member functions or global functions. Which one do you think is better and why?

In this case of `operator +=` its better to use global functions because of the following two reasons:

Friend Function:
Pros: 
- The friend function is useful if many multiple classes require it.
- It allows a non-member function to share private class information with another function.
-  Can be declared anywhere, just as the global functions.
- Can be used to call the function without using the object.

Cons: 
- Friend functions are not passed down to derived class.
- Friend functions lack storage class specifiers.
- Algorithm that can be multiplied classes, will be duplicated if buried in a specific class.

Member Function:
Pros:
- Can easily access the private members of the class.
- Member functions dont expose implementation details.

Cons:
- It can lead to duplicate implementation of the algorithm being shared by multiple classes. 

Reasoning of using friend over member :

- Left hand side is the one that does the operation, so `obj + j `will look for `+` overloading in obj whereas `2 + obj` it wont work. For these friend/global functions are heloful in overloading operators. 
Thus if we have member function then `obj += 2` will work, but `2 += obj` wont. Thus we should implemenet global function here using friend.

- I would not want to make changes in int `+=` function and better make changes to my obj operator ovrloading function.