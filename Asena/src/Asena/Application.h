#pragma once

#include "Core.h"

namespace Asena {

  class ASENA_API Application
  {
  public:
    Application();
    virtual ~Application();
    void Run();
  };

  //to be defined in CLIENT
  Application* CreateApplication();


}