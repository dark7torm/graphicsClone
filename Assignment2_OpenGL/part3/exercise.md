# exercise.md

The following are a list of questions about the design of our math library and also further your C++/general programming knowledge.

1. In C++ what are the three instances where you would use the keyword [const](https://en.cppreference.com/w/cpp/keyword/const)?
2. What does [inline](https://en.cppreference.com/w/cpp/language/inline) do? Why might a programmer use it?
3. Why do you think libraries like GLM are implemented as a header only library? 
	- (Sometimes you will see this, and you may research [.inl files](https://stackoverflow.com/questions/1208028/significance-of-a-inl-file-in-c) in C++)
4. C++ allows for something known as 'operator overloading'. This means we can define (or redefine) how operators like +,-,/,etc. work--but this means additional symbols like `<<`. Would it be helpful to implement the '<<' operator for a mat4 type? (i.e. `operator<<`)? What might you use this for? Does the GLM library overload the '<<' operator? (i.e., `std::cout << some_mat4`)
5. For the floating-point data type, would it be dangerous to overload the operator for '=='?
	- How might you mitigate this? [reference](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/)
	- The question I am really asking is, why is it a problem to compare two floating point numbers?
6. What is a template in C++? Is the GLM library using templates?
7. How closely named are the functions in GLM versus the GL Shading Language(GLSL) (i.e., Was the GLM library designed to closely match GLSL?)

You may add your notes here:

1. 
	1. When defining a variable that is non-modifiable
	2. When defining a read only member function that does not change the object it is called in
	3. When defining a variable to behave as both a const (non modifiable) object and as a volatile object.
2. The inline keyword creates an inline function to expand when called in a line. A programmer might use this when there is a function they want to call in all sources files, so they create an inline function in the header so that when the source files need it they can just call the inline function. If a function is used in more than one source file the function has to be inline.
3. Libraries like GLM are only implemented as a header only library since the sources include the header, so you only need to include them once. The benefits of this are that since the compiler doesn't need the library to build, the build process becomes simpler.
4. It would be helpful to overload the << operator for a mat4 type so that you can display matrices in a specific way or order, depending on what you need. The GLM library does overload this operator and outputs the mat4 object in a matrix form (ex. [2, 3]
																									[3, 5])
5. It is a problem to compare two floating point numbers since most times the floating point values are rounded / can't be represented with exact values. This means that two values that might actually be equal have slightly different values when compared using floating point comparison. On top of this, compilers may differ with the ways that they round so it will bring more variance on whether two truly equal floating point values are going to correctly compare.
6. Templates are generic code that can be used with many different data types. Using a template, you can compare two ints and also two strings with just one template method. The GLM library does use templates, allowing you to do things like define matrices with ints, floats, doubles, etc.
7. The GLM functions are very similarly named to GLSL. Many of the functions with similar or same uses have the same names ex. glm::cross and cross.
