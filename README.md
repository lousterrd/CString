# CString


The first test tests the default constructor, which sets the private pointer m_buffer to NULL, as well as setting the m_size variable to 0.

Test 2 tests the integrity of the parametrized constructor, which begins the same way as the default constructor, then allocates the correct amount of space for the m_buffer by checking the size of the character array passed in. Then, the contents of the passed in character array are copied to the m_buffer.

Test 3 tests the copy constructor, by passing in the previously created parametrized MyString object.

Test 4 tests the destructor, which merely deallocates the m_buffer and resets the pointer to NULL, as well as resetting the m_size to 0.

Next, tests 5 and 6 check to make sure that size and length are indeed 2 different values, length being one less than size. This is because the size variable takes into account the NULL character at the end of character arrays, whereas length only counts valid characters.

Test 7 tests the c_str() method, which merely returns the m_buffer contents.

Test 8 tests the validity of the overloaded comparison operator, by creating two MyString objects with the same c-string contents, and one with different c-string content. The first if statement checks to make sure the two identical objects are indeed the same, and the second if statement checks to make sure the different objects are different.

Test 9 checks the overloaded assignment operator, which copies the contents of the rhs object into the new object.

Test 10 checks the overloaded + operator, which allows concatenation of two MyString objects. Using the assignment operator, the resulting object of the concatenation is set to ms_concat.

Test 11 makes sure that the overloaded operator [] works, giving full access to MyString's m_buffer character array, without needing private permissions.

Test 12 checks the overloaded << operator, which just returns the passed in MyString object's c-string in the stream.



