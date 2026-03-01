#include <iostream>

template<class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c)
{
  const T* a_it = a;
  const T* a_end = a + sa;
  const T* b_it = b;
  const T* b_end = b + sb;
  T* out = c;

  while (a_it != a_end && b_it != b_end)
  {
    if (*b_it < *a_it)
    {
      *out = *b_it;
      ++b_it;
    }
    else
    {
      *out = *a_it;
      ++a_it;
    }
    ++out;
  }

  while (a_it != a_end)
  {
    *out = *a_it;
    ++a_it;
    ++out;
  }

  while (b_it != b_end)
  {
    *out = *b_it;
    ++b_it;
    ++out;
  }

  return out;
}
