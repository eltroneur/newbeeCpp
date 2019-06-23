// noJerk_mutable.cpp -- using mutable
#include <iostream>

class human
{
public:
  human()
  {
    m_isJerked = false;
  }
  virtual void jerk() const = 0;
  void isJerked() const
  {
    if (!m_isJerked)
    {
      std::cout << "You beat yourself!" << std::endl;
    }
    else
    {
      std::cout << "What a shame!" << std::endl;
    }
  }
protected:
  mutable bool m_isJerked; // even in const method, this variable can be modified
};

class ill_human
{
public:
  ill_human()
  {
    m_isJerked = false;
  }
  virtual void jerk() const = 0;
  void isJerked()
  {
    if (m_isJerked)
    {
      std::cout << "What a shame!" << std::endl;
    }
    else
    {
      std::cout << "You beat yourself!" << std::endl;
    }
  }
protected:
  bool m_isJerked; // cannot modify its value in const mtehod
};

class me : public human
{
public:
  virtual void jerk() const
  {
    std::cout << "I'm really want to jerk again... Just one more time!!!" << std::endl;
    m_isJerked = true; // modified
  }

};

class ill_me : public ill_human
{
public:
  virtual void jerk() const
  {
    //m_isJerked = true; // cannot modified , Error: Assignment of read-only member
    std::cout << "I tried to jerk again, but failed!" << std::endl;
  }
};


int main()
{
  me jason;
  jason.jerk();
  jason.isJerked();

  ill_me ill_jason;
  ill_jason.jerk();
  ill_jason.isJerked();

  return 0;
}
