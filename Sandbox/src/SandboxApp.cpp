#include "Rosaw.h"

class Sandbox : public Rosaw::Application
{
public:
  Sandbox()
  {

  }

  ~Sandbox()
  {

  }

};

Rosaw::Application* Rosaw::CreateApplication()
{
  return new Sandbox();
}

