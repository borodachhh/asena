#pragma once

#ifdef RSW_PLATFORM_WINDOWS

extern Rosaw::Application* Rosaw::CreateApplication();

int main(int argc, char** argv)
{
  printf( "Rosaw app is running :)\n" );
  auto app = Rosaw::CreateApplication();
  app->Run();
  delete app;
}

#endif // RSW_PLATFORM_WINDOWS
