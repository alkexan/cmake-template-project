#include "Singleton.hpp"

/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton ::m_instance = nullptr;

Singleton *Singleton::GetInstance(const std::string &value) {
  /**
   * This is a safer way to create an instance. instance = new Singleton is
   * dangeruous in case two instance threads wants to access at the same time
   */
  if (m_instance == nullptr) {
    m_instance = new Singleton(value);
  }
  return m_instance;
}