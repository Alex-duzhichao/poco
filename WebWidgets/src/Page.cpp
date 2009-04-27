//
// Page.cpp
//
// $Id: //poco/Main/WebWidgets/src/Page.cpp#2 $
//
// Library: WebWidgets
// Package: Views
// Module:  Page
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/WebWidgets/Page.h"
#include "Poco/WebWidgets/RequestHandler.h"


namespace Poco {
namespace WebWidgets {


const std::string Page::EV_BEFORERENDER("beforeRender");
const std::string Page::EV_AFTERRENDER("afterRender");


Page::Page():
	ContainerView(typeid(Page)),
	_text(),
	_rm()
{
}

	
Page::Page(const std::string& name):
	ContainerView(name, typeid(Page)),
	_text(),
	_rm()
{
}

	
Page::Page(const char* pName):
	ContainerView(std::string(pName), typeid(Page)),
	_text(),
	_rm()
{
}


Page::Page(const std::string& name, const std::type_info& type):
	ContainerView(name, type),
	_text(),
	_rm()
{
}


Page::Page(const char* pName, const std::type_info& type):
	ContainerView(std::string(pName), type),
	_text(),
	_rm()
{
}

	
Page::Page(const std::type_info& type):
	ContainerView(type),
	_text(),
	_rm()
{
}


Page::~Page()
{
}


void Page::setText(const std::string& text)
{
	_text = text;
}


std::string Page::getText() const
{
	return _text;
}



void Page::handleAjaxRequest(const Poco::Net::NameValueCollection& args, Poco::Net::HTTPServerResponse& response)
{
	const std::string& ev = args[RequestHandler::KEY_EVID];
	Page* pPage = this;
	if (ev == EV_BEFORERENDER)
	{
		beforeRender.notify(this, pPage);
	}
	else if (ev == EV_AFTERRENDER)
	{
		afterRender.notify(this, pPage);
	}
	
	response.send();
}


} } // namespace Poco::WebWidgets