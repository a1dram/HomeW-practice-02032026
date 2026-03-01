#include <iostream>

template<class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c)
{
  // явный интерфейс: если sa или sb неверные, то UB обеспечен
  // явный интерфейс: не факт, что a и b отсортированы
  const T* a_it = a;
  const T* a_end = a + sa; // явный интерфейс: const T* + size_t быстрый, но опасный
  const T* b_it = b;
  const T* b_end = b + sb; // то же, что и с a_end
  T* out = c;

  while (a_it != a_end && b_it != b_end)
  {
    if (*b_it < *a_it) // нужен T::operator<(const T&, const T&) 
    {
      *out = *b_it; // нужен T::operator=(const T&)
      ++b_it;
    }
    else
    {
      *out = *a_it; // нужен T::operator=(const T&)
      ++a_it;
    }
    ++out;
  }

  while (a_it != a_end)
  {
    *out = *a_it; // нужен T::operator=(const T&)
    ++a_it;
    ++out;
  }

  while (b_it != b_end)
  {
    *out = *b_it; // нужен T::operator=(const T&)
    ++b_it;
    ++out;
  }

  return out;
}
