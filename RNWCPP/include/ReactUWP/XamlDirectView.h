// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Core.Direct.h>

namespace winrt {
  using namespace Microsoft::UI::Xaml::Core::Direct;
  using namespace Windows::UI::Xaml;
  using namespace Windows::Foundation;
}

namespace react { namespace uwp {

typedef winrt::IInspectable XamlDirectView;

inline winrt::IXamlDirect XD()
{
  return winrt::XamlDirect::GetDefault();
}

inline int64_t GetTag(XamlDirectView view)
{
  return XD().GetObjectProperty(view, winrt::XamlPropertyIndex::FrameworkElement_Tag).as<winrt::IPropertyValue>().GetInt64();
}

inline void SetTag(XamlDirectView view, int64_t tag)
{
  XD().SetObjectProperty(view, winrt::XamlPropertyIndex::FrameworkElement_Tag, winrt::PropertyValue::CreateInt64(tag));
}

inline void SetTag(XamlDirectView view, winrt::IInspectable tag)
{
  SetTag(view, tag.as<winrt::IPropertyValue>().GetInt64());
}

} }
