module NumberFieldVListener;

import  dwt.widgets.Listener,
		dwt.widgets.Event;

class NumberFieldVListener:Listener {
	bool NumberVerify=true;
	void handleEvent(Event e) {
		if(e.character>'9'||e.character<'0')
			e.doit=false;
		if(!NumberVerify||e.character==8||e.character==127)
			e.doit=true;
	}
}
