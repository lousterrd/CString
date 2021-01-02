// Louis Doherty
// CS-202 Project 7


#include <iostream>
#include "MyString.h"

using namespace std;


MyString::MyString()
{
   m_buffer = NULL;
   m_size = 0;
}


MyString::MyString(const char * str)
{
   m_buffer = NULL;
   m_size = 0;

   // Counting all characters in str, then adding one to size for '\0'
   for (int j = 0; str[j] != '\0'; j++, m_size++);
   m_size++;

   buffer_allocate(size());
   for (int i = 0; i < m_size; i++)
   {
      m_buffer[i] = str[i];
   }
}



MyString::MyString(const MyString & other_myStr)
{
   m_buffer = NULL;
   m_size = other_myStr.size();
   buffer_allocate(m_size);
   for (int i = 0; i < m_size; i++)
   {
      m_buffer[i] = other_myStr.m_buffer[i];
   }
}


MyString::~MyString()
{
   buffer_deallocate();
}


void MyString::buffer_deallocate()
{
   if (m_buffer != NULL)
   {
      delete [] m_buffer;
      m_buffer = NULL;
      m_size = 0;
   }

}


void MyString::buffer_allocate(size_t size)
{
   buffer_deallocate();
   if (size > 0)
      m_size = size;
   try
   {
      m_buffer = new char [size];
   }
   catch(bad_alloc &ex)
   {
      throw;
   }
}


size_t MyString::size() const
{
   return m_size;
}


size_t MyString::length() const
{
   /*
   size_t length = 0;

   for (int i = 0; m_buffer[i] != '\0'; i++, length++);
    */
   return m_size - 1;
}


const char * MyString::c_str() const
{
   return m_buffer;
}


bool MyString::operator==(const MyString &other_myStr) const
{
   // Tried this but is a work in progress
   /*
   char * dst = m_buffer;
   char * src = other_myStr.m_buffer;
   while (*dst == *src++)
   {
      if (!*dst++)
      {
         return false;
      }
   }
   return true;

*/

   size_t size;
   if (length() > other_myStr.length())
      size = other_myStr.size();
   else
      size = m_size;

   int flag = 0;
   for (int i = 0; i < size; i++ )
   {
      if (m_buffer[i] != other_myStr.m_buffer[i])
         flag++;
   }

   if (flag == 0)
      return true;
   else
      return false;

}


MyString & MyString::operator=(const MyString &other_myStr)
{
   buffer_allocate(other_myStr.size());
   for (int i = 0; i < other_myStr.size(); i++)
   {
      this->m_buffer[i] = other_myStr.m_buffer[i];
   }
   return *this;
}


MyString MyString::operator+(const MyString &other_myStr) const
{
   size_t len1 = length();
   size_t len2 = other_myStr.length();
   size_t size = len1 + len2 + 1;
   char * combo = new char [size];

   for (int i = 0; i < len1; i++)
   {
      combo[i] = m_buffer[i];
   }
   for (int j = 0; j < len2; j++)
   {
      combo[j + len1] = other_myStr.m_buffer[j];
   }
   combo[len1 + len2] = '\0';
   MyString result(combo);
   return result;
}


char & MyString::operator[](size_t index)
{
   return m_buffer[index];
}


const char & MyString::operator[](size_t index) const
{
   return m_buffer[index];
}

ostream & operator<<(ostream & os, const MyString & myStr)
{
   os << myStr.c_str() << endl;

   return os;
}
















