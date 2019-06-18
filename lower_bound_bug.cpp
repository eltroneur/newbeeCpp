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

template<class ForwardIt, class T>
int position(ForwardIt target, std::vector<T> &vec)
{
  int pos = 0;
  while (target != vec.end())
  {
	  std::cout << "*target = " << *target << std::endl;
	  ++pos;
	  ++target;
  }
  return pos;
}

int main()
{
  std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6};
  auto b = data.begin();
  int size = 0;
  while (b != data.end())
  {
	  ++size;
	  ++b;
  }
  //int size = position(b, data);
  std::cout << "size is " << size << std::endl;
  b = data.begin();
  size = position(b, data);
  std::cout << "size is " << size << std::endl;
  std::cout << "data.size() = " << data.size() << ", data.capacity() = " << data.capacity() << std::endl;

  auto lower = std::lower_bound(data.begin(), data.end(), 4);
  //--lower;
  //--lower;
  //--lower;
  int pos = position(lower, data);
  std::cout << "pos is " << pos << std::endl;

  //std::cout << "--lower = " << *(--lower) << std::endl;
  auto upper = std::upper_bound(data.begin(), data.end(), 4);

  std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  // classic binary search, returning a value only if it is present
  data = {1, 2, 4, 6, 9, 10};
  auto it = binary_find(data.cbegin(), data.cend(), 4); // < choosing '5' will return end()
  if (it != data.cend())
  {
    std::cout << *it << " found at index " << std::distance(data.cbegin(), it);
  }

  return 0;
}
