#pragma once

#include "Core.h"

namespace Rosaw {

  class ROSAW_API Application
  {
  public:
    Application();
    virtual ~Application();
    void Run();
  };

  //to be defined in CLIENT
  Application* CreateApplication();


}