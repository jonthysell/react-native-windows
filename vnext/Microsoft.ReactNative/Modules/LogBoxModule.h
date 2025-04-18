// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include "codegen/NativeLogBoxSpec.g.h"
#include <NativeModules.h>
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Display.h>

namespace Microsoft::ReactNative {

REACT_MODULE(LogBox)
struct LogBox : public std::enable_shared_from_this<LogBox> {
  using ModuleSpec = ReactNativeSpecs::LogBoxSpec;

  ~LogBox();

  REACT_INIT(Initialize)
  void Initialize(winrt::Microsoft::ReactNative::ReactContext const &reactContext) noexcept;

  REACT_METHOD(Show, L"show") void Show() noexcept;
  REACT_METHOD(Hide, L"hide") void Hide() noexcept;

 private:
#ifdef USE_FABRIC
  static void RegisterWndClass() noexcept;
#endif // USE_FABRIC
  void ShowOnUIThread() noexcept;
  void HideOnUIThread() noexcept;

  winrt::Microsoft::ReactNative::ReactContext m_context;
#ifdef USE_FABRIC
  HWND m_hwnd{nullptr};
#else
  xaml::Controls::Primitives::Popup m_popup{nullptr};
  winrt::Microsoft::ReactNative::ReactRootView m_logBoxContent{nullptr};
#endif // USE_FABRIC
  xaml::FrameworkElement::SizeChanged_revoker m_sizeChangedRevoker;
  winrt::event_token m_tokenClosed;
};

} // namespace Microsoft::ReactNative
