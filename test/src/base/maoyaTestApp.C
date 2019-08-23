//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "maoyaTestApp.h"
#include "maoyaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<maoyaTestApp>()
{
  InputParameters params = validParams<maoyaApp>();
  return params;
}

maoyaTestApp::maoyaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  maoyaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

maoyaTestApp::~maoyaTestApp() {}

void
maoyaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  maoyaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"maoyaTestApp"});
    Registry::registerActionsTo(af, {"maoyaTestApp"});
  }
}

void
maoyaTestApp::registerApps()
{
  registerApp(maoyaApp);
  registerApp(maoyaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
maoyaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maoyaTestApp::registerAll(f, af, s);
}
extern "C" void
maoyaTestApp__registerApps()
{
  maoyaTestApp::registerApps();
}
