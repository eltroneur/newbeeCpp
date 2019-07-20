// std_map.cpp -- using std::map
#include <map>
#include <string>
#include <iostream>

template <class T1, class T2>
void traverse(std::map<T1, T2> mp)
{
  typename std::map<T1, T2>::const_iterator citer;
  for (citer = mp.cbegin(); citer != mp.cend(); ++citer)
  {
    std::cout << citer->first << "-->" << citer->second << " ";
  }
  std::cout << std::endl;
}

template <class T1, class T2>
void rtraverse(std::map<T1, T2> mp)
{
  typename std::map<T1, T2>::const_reverse_iterator criter;
  for (criter = mp.rbegin(); criter != mp.rend(); ++criter)
  {
    std::cout << criter->first << "-->" << criter->second << std::endl;
  }
  std::cout << std::endl;
}

template <class T1, class T2>
//void InsertionJudgement(std::map<T1, T2> mp, std::pair<T1, T2> val)
void InsertionJudgement(std::map<T1, T2> &mp, typename std::map<T1, T2>::value_type val)
{
  std::pair<typename std::map<T1, T2>::const_iterator, bool> result;
  result = mp.insert(val);
  if (result.second)
  {
    std::cout << "Insertion succeed!" << std::endl;
  }
  else
  {
    std::cout << "Insertion failed!" << std::endl;
  }
}

int main()
{
  std::map<int, std::string> props;
  props.insert(std::pair<int, std::string>(5, "S_GDS_PROPERTY"));
  props.insert(std::map<int, std::string>::value_type(4, "S_K_CONTEXT"));
  props.insert(std::pair<int, std::string>(9, "S_MAX_INTEGER"));
  // insert a value-pair whose key is already in map, the insertion will
  // failed, and the value will not be updated
  props.insert(std::pair<int, std::string>(9, "NEW_INTEGER_WIDTH"));
  // so we need to detect whether the insertion succeeds
  InsertionJudgement(props, std::map<int, std::string>::value_type(9, "NEW_INTEGER_WIDTH"));
  //InsertionJudgement(props, std::pair<int, std::string>(9, "NEW_INTEGER_WIDTH"));
  InsertionJudgement(props, std::map<int, std::string>::value_type(88, "ULTIMATE_PROPERTY"));

  props[0] = "HACKED_PROPERTY";  // add a new map value
  props[4] = "S_OPCLAYOUT_CONTEXT"; // modify a map value
  props[50] = "OLDEST_PROPERTY";
  
  std::map<char, int> codes;
  codes.insert(std::map<char, int>::value_type('X', 5901));
  codes.insert(std::make_pair<char, int>('M', 5902));
  codes['O'] = 8080; // fine

  traverse(props);
  traverse(codes);

  rtraverse(props);
  rtraverse(codes);

  std::cout << "props's size is " << props.size() << std::endl;


  return 0;
}
