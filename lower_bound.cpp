// lower_bound.cpp -- using std::lower_bound
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
  // Note: BOTH type T and the type after ForwardIt is dereferenced
  // must be implicitly convertible to BOTH Type1 and Type2, used in Compare.
  // This is stricter than lower_bound requirement (see above)

  first = std::lower_bound(first, last, value, comp);
  return first != last && !comp(value, *first) ? first : last;
}

template<class ForwardIt, class T, class Compare=std::less<>>
void my_find(ForwardIt first, ForwardIt last, T const &value, Compare comp={})
{
  auto origin = first;
  first = std::lower_bound(first, last, value, comp);
  if (*first == value)
  {
    std::cout << "Found " << value << " at index " << std::distance(origin, first) << " and *first = "\
	<< *first << std::endl;
  }
  else
    std::cout << "Not found!" << std::endl;
}

template<class ForwardIt, class T>
int position(ForwardIt target, std::vector<T> &vec)  // if use value copying this vector, result may error because
													// old iterator with new copied vector
{
  int pos = 0;
  typename std::vector<T>::const_iterator s_iter = vec.begin();
  while (s_iter != target)
  {
	  ++pos;
	  ++s_iter;
  }
  return pos;
}

int main()
{
  std::vector<int> data = { 1, 3, 7, 11, 24, 39, 42, 42, 42, 53, 68, 79, 88 };
  auto b = data.begin();
  int size = 0;
  while (b != data.end())
  {
	  ++size;
	  ++b;
  }
  std::cout << "size is " << size << std::endl;
  b = data.begin();
  size = position(b, data);
  std::cout << "begin size is " << size << std::endl;

  b = data.end();
  int pos = position(b, data);
  std::cout << "end pos is " << pos << std::endl;
  --b;
  pos = position(b, data);
  std::cout << "--end pos is " << pos << std::endl;

  auto lower = std::lower_bound(data.begin(), data.end(), 4);  // find a position to insert 4
  pos = position(lower, data);
  std::cout << "lower pos is " << pos << ", *lower is " << *lower << std::endl;  // insert 4 in this position
  data.insert(lower, 4);
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, ","));
  std::cout << std::endl;

  /**
   *  @brief Finds the last position in which @p __val could be inserted
   *         without changing the ordering.
   *  @ingroup binary_search_algorithms
   *  @param  __first   An iterator.
   *  @param  __last    Another iterator.
   *  @param  __val     The search term.
   *  @return  An iterator pointing to the first element greater than @p __val,
   *           or end() if no elements are greater than @p __val.
   *  @ingroup binary_search_algorithms
  */
  auto upper = std::upper_bound(data.begin(), data.end(), 42);
  std::cout << "upper pos is " << position(upper, data) << ", *upper is " << *upper << std::endl;

  /**
   *  @brief Copies the range [first,last) into result.
   *  @ingroup mutating_algorithms
   *  @param  __first  An input iterator.
   *  @param  __last   An input iterator.
   *  @param  __result An output iterator.
   *  @return   result + (first - last)
   *
   *  This inline function will boil down to a call to @c memmove whenever
   *  possible.  Failing that, if random access iterators are passed, then the
   *  loop count will be known (and therefore a candidate for compiler
   *  optimizations such as unrolling).  Result may not be contained within
   *  [first,last); the copy_backward function should be used instead.
   *
   *  Note that the end of the output range is permitted to be contained
   *  within [first,last).
  */
  std::copy(lower, upper, std::ostream_iterator<int>(std::cout, ","));
  std::cout << '\n';

  // classic binary search, returning a value only if it is present
  data = {1, 2, 4, 6, 9, 10};
  auto it = binary_find(data.cbegin(), data.cend(), 4); // < choosing '5' will return end()
  if (it != data.cend())
  {
    std::cout << *it << " found at index " << std::distance(data.cbegin(), it) << std::endl;
  }
  // normal find
  my_find(data.begin() + 1, data.end() - 1, 6);

  // not found
  my_find(data.begin() + 1, data.end() -1, 10);

  // empty range
  my_find(data.end(), data.end(), 8);

  return 0;
}
