﻿/**
 * FileName: DcompPrivate.h
 *
 * Copyright (C) 2024 Maplespe、ALTaleX531
 *
 * This file is part of MToolBox and DWMBlurGlass.
 * DWMBlurGlass is free software: you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation, either version 3
 * of the License, or any later version.
 *
 * DWMBlurGlass is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with Foobar.
 * If not, see <https://www.gnu.org/licenses/lgpl-3.0.html>.
*/
#pragma once
#include "../framework.h"
#include "../Helper/HookHelper.h"
#include "winrt.h"
#include "winrt_impl.h"
#include <dcomp.h>

namespace MDWMBlurGlassExt::DCompPrivate
{
	DECLARE_INTERFACE_IID_(InteropCompositionTarget, IUnknown, "EACDD04C-117E-4E17-88F4-D1B12B0E3D89")
	{
		STDMETHOD(SetRoot)(THIS_ IN IDCompositionVisual* visual) PURE;
	};

	struct IDCompositionDesktopDevicePartner : IDCompositionDesktopDevice 
	{
		HRESULT CreateSharedResource(REFIID riid, PVOID* ppvObject)
		{
			return (this->*class_method_cast<decltype(&IDCompositionDesktopDevicePartner::CreateSharedResource)>(GetObjectVTable(this)[27]))(
				riid, ppvObject
			);
		}
		HRESULT OpenSharedResourceHandle(InteropCompositionTarget* interopTarget, HANDLE* resourceHandle)
		{
			return (this->*class_method_cast<decltype(&IDCompositionDesktopDevicePartner::OpenSharedResourceHandle)>(GetObjectVTable(this)[28]))(
				interopTarget, resourceHandle
			);
		}
	};

	MIDL_INTERFACE("fe93b735-e574-4a5d-a21a-f705c21945fa")
	IDCompositionVisualPartnerWinRTInterop : IDCompositionVisual3
	{
		auto GetVisualCollection()
		{
			using GetVisualCollection_t = HRESULT(STDMETHODCALLTYPE IDCompositionVisualPartnerWinRTInterop::*)(PVOID* collection);

			winrt::Windows::UI::Composition::VisualCollection collection{ nullptr };

			if (MDWMBlurGlass::os::buildNumber < 22000)
			{
				winrt::check_hresult(
					(this->*class_method_cast<GetVisualCollection_t>(GetObjectVTable(this)[44]))(
						winrt::put_abi(collection)
					)
				);
			}
			else
			{
				winrt::check_hresult(
					(this->*class_method_cast<GetVisualCollection_t>(GetObjectVTable(this)[45]))(
						winrt::put_abi(collection)
					)
				);
			}

			return collection;
		}
	};
}