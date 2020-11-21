#include "Asena.h"

class Sandbox : public Asena::Application
{
public:
  Sandbox()
  {
  }

  ~Sandbox()
  {
  }
};

Asena::Application* Asena::CreateApplication()
{
  return new Sandbox();
}