// Author: Burak Doğançay
#include "EventClasses.h"
#include "EventListeners.h"
#include "EventDispatcher.h"

int main(int argc, char **argv)
{
   EventDispatcher dispatcher;

   //Creating Listeners
   std::shared_ptr<ButtonClickListener> buttonListener = std::make_shared<ButtonClickListener>();
   std::shared_ptr<TextChangedListener> textListener = std::make_shared<TextChangedListener>(); 

   //Rgeistering Listeners
   dispatcher.addListener(buttonListener);
   dispatcher.addListener(textListener);

   //simulate Events
   ButtonClickedEvent buttonEvent;
   TextChangedEvent textEvent;
   TextChangedEvent textEvent2;

   dispatcher.dispatch(buttonEvent);
   dispatcher.dispatch(textEvent);
   
}