#include "maoyaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<maoyaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

maoyaApp::maoyaApp(InputParameters parameters) : MooseApp(parameters)
{
  maoyaApp::registerAll(_factory, _action_factory, _syntax);
}

maoyaApp::~maoyaApp() {}

void
maoyaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"maoyaApp"});
  Registry::registerActionsTo(af, {"maoyaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
maoyaApp::registerApps()
{
  registerApp(maoyaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
maoyaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maoyaApp::registerAll(f, af, s);
}
extern "C" void
maoyaApp__registerApps()
{
  maoyaApp::registerApps();
}
