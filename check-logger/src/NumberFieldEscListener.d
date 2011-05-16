module NumberFieldEscListener;

import  dwt.widgets.Listener,
		dwt.widgets.Event,
		dwt.widgets.Text,
		dwt.DWT;

import  Integer=tango.text.convert.Integer;

import  NumberFieldVListener,
		AppWindow;

class NumberFieldEscListener:Listener {
	
	NumberFieldVListener NumberVListener;
	Text NumberField;
	AppWindow context;
	
	this(Text field, NumberFieldVListener vl, AppWindow c) {
		NumberField=field;
		NumberVListener=vl;
		context=c;
	}
	
	void handleEvent(Event e) {
		if(e.keyCode==DWT.ESC) {
			NumberVListener.NumberVerify=false;
			NumberField.setText(Integer.toString(context.getNumber));
			NumberVListener.NumberVerify=true;
		}
	}
}
