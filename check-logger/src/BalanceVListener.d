module BalanceVListener;

import  dwt.DWT,
		dwt.widgets.Text,
		dwt.widgets.Listener,
		dwt.widgets.Event;

import tango.text.Util;

class BalanceVListener:Listener {
	
	bool process=true;
	Text BalanceField;
	
	this(Text bfield) {
		BalanceField=bfield;
	}
	
	void handleEvent(Event e) {
		if(!process)
			return;
		if(e.keyCode==DWT.BS&&BalanceField.getCaretPosition()<BalanceField.getText().length) {
			if(BalanceField.getText[BalanceField.getCaretPosition()-1]!='.') {
				e.doit=true;
				return;
			} else {
				e.doit=false;
				return;
			}
		}
		if(e.character>='0'&&e.character<='9')
			e.doit=true;
		else
			e.doit=false;
		if(e.character=='.') {
			e.doit=false;
			char[] txt=BalanceField.getText();
			int caret=BalanceField.getCaretPosition();
			if(caret>=tango.text.Util.locate(txt, '.')||caret==0)
				return;
			BalanceField.setText(txt[0..caret]~'.'~txt[tango.text.Util.locate(txt, '.')..$]);
		}
	}
}