#pragma once

#ifdef AE_PLATFORM_WINDOWS

extern Asena::Application* Asena::CreateApplication();

int main( int argc, char** argv )
{
  Asena::Log::Init();
  AE_CORE_INFO( "Log is initialized." );
  auto app = Asena::CreateApplication();
  AE_CORE_INFO( "An application is running" );
  app->Run();
  delete app;
}

#endif // AE_PLATFORM_WINDOWS
