#pragma once

#include "pch.h"
#include "resource.h"

{{^libHasModules}}/**{{/libHasModules}}
#if __has_include("codegen\Native{{ pascalName }}DataTypes.g.h")
  #include "codegen\Native{{ pascalName }}DataTypes.g.h"
#endif
#include "codegen\Native{{ pascalName }}Spec.g.h"

#include "NativeModules.h"
{{^libHasModules}}*/{{/libHasModules}}

namespace winrt::{{ namespaceCpp }}
{

{{^libHasModules}}/**{{/libHasModules}}
// Module implementation for {{ pascalName }} based on the module template in create-react-native-module
REACT_MODULE({{ pascalName }})
struct {{ pascalName }}
{
  // This ModuleSpec type ensures the module implementation meets the requirements of the module
  using ModuleSpec = {{ namespaceCpp }}Codegen::{{ pascalName }}Spec;

  REACT_INIT(Initialize)
  void Initialize(React::ReactContext const &reactContext) noexcept;

  REACT_SYNC_METHOD(multiply)
  double multiply(double a, double b) noexcept;

private:
  React::ReactContext m_context;
};
{{^libHasModules}}*/{{/libHasModules}}

} // namespace winrt::{{ namespaceCpp }}