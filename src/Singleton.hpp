#include <string>

/**
 * @brief This is just a simple Singleton
 * 
 */
class Singleton {
protected:
  Singleton(const std::string value) : m_value(value) {}

  static Singleton *m_instance;

  std::string m_value;

public:

  Singleton(Singleton &other) = delete;

  void operator=(const Singleton &) = delete;

  static Singleton *GetInstance(const std::string &value);

  std::string value() const { return m_value; }
};